#-*- coding: utf-8 -*-
import sys , getopt
import os , re , string
import time , datetime
import binascii 
import collections  
import xml.dom.minidom
import time,datetime
import socket

from openpyxl import Workbook
from openpyxl.compat import range
from openpyxl.cell import get_column_letter
from openpyxl import load_workbook
import csv

from xml.dom import minidom , Node 

from xml.etree.ElementTree import ElementTree
from xml.etree.ElementTree import Element
from xml.etree.ElementTree import SubElement as SE
#sys.reload()
#sys.setdefaultencoding("utf-8") 
#sys.setdefaultencoding("cp936") 

g_xlsImportPath = ""
g_xlsExportPath = ""
	
def start(): 
	LogOutInfo("start generate csv.\n")   
	
	DeleteExportPathFiles()
	GenerateCSVFromXLS()
	LogOutInfo("generate CSV finished.\n") 
			
	ReadCSV()
	
	GenerateCPP()
	LogOutInfo("generate CPP finished.\n") 
	
def GenerateCSVFromXLS2():
	root = g_xlsImportPath
	dirout = g_xlsExportPath
	if os.path.exists(dirout) == False:
		os.makedirs(dirout)
	
	files = Search(root ,'.xls')
	dirout = dirout + os.sep  #新路径名称
	for result in files:
		filename = os.path.basename(result) #获取文件名
		dirname = os.path.dirname(result)#获取子目录路径
		dir1_1 = os.path.split(root)    #分离输入文件目录
		dirname1 = os.path.split(dirname) #分离子目录名称
		outputdir = dirname1[0].split(dir1_1[0])#获取输出文件路径
		if os.path.exists(newdir) == False:
			os.makedirs(newdir)
			
		a = xlrd.open_workbook(result)
		for i in a.sheets():
			output = open(newdir + filename+"_"+ i.name + ".csv",'a')
			for r in range(i.nrows):
				linevalue = []
				for l in range(i.ncols):
					if i.cell(r,l).ctype == 0:
						linevalue.append(('%*s'%(4,' ')))   
					else:
						b = i.cell(r,l).value
						if type(b) == type(4.0):
							b= str(b)
						linevalue.append(b)
				d = ','.join(linevalue)
				output.write(d+'\\n') 
			output.write(os.linesep)
		output.close() 
	
def GenerateCSVFromXLS():
	root = g_xlsImportPath
	
	files = Search(root ,'.xlsx')
	for result in files:
		LogOutInfo("filename:" , result);
		Xlsx2CSV(result)
	
def ReadCSV(): 
	pass
	
def GenerateCPP(): 
	pass
	
################################流程无关函数处理#####################################
def Usage():
    print('GenerateCSV.py usage:')
    print('-h,--help: print help message.')
    print('-v, --version: print script version')
    print('-o, --output: input an output verb')
    print('--foo: Test option ')
    print('--fre: another test option')

def Version():
	print('GenerateCSV.py 1.0.0.0.1')

def LogOutDebug(*string):
	longStr = "debug: "
	for item in range(len(string)):  
		longStr += str(string[item])

	print(longStr)
	pass

def LogOutInfo(*string):
	longStr = "info: "
	for item in range(len(string)):  
		longStr += str(string[item])
	
	print(longStr)
	
def LogOutError(*string):
	longStr = "error: "
	for item in range(len(string)):  
		longStr += str(string[item])
	
	print(longStr)
	sys.exit()
	
def WriteFileDescription(fileRpc , sfile , desc):
	fileRpc.write("/************************************" + "\n")
	fileRpc.write("FileName	:	" + sfile + "\n")
	fileRpc.write("Author		:	generate by tools" + "\n")
	fileRpc.write("HostName	:	" + socket.gethostname() + "\n")
	fileRpc.write("IP			:	" + socket.gethostbyname(socket.gethostname()) + "\n")
	fileRpc.write("Version		:	0.0.1" + "\n")
#	fileRpc.write("Date		:	" + time.strftime('%Y-%m-%d %H:%M:%S') + "\n")
	fileRpc.write("Description	:	" + desc + "\n")
	fileRpc.write("************************************/" + "\n")

def Search(base , suffix):
    pattern = suffix
    fileresult = []
    cur_list = os.listdir(base)
    for item in cur_list:
        full_path = os.path.join(base, item)
        if os.path.isdir(full_path):            
            fileresult += Search(full_path , suffix)
        if os.path:
            if full_path.endswith(pattern):
                fileresult.append(full_path)
    return fileresult
	
def DeleteExportPathFiles():
	files = Search(g_xlsExportPath , '.csv')
	for sfile in files:
		if os.path.exists(sfile): 
			os.remove(sfile)

def CreateServerNamePath(): 
	for index , serverName in g_rpcMsgs.rpcServerNames.items():
		if False == os.path.exists(serverName.outputPath):
			LogOutDebug(serverName.outputPath)

def Xlsx2CSV(filepath):
	dirout = g_xlsExportPath
	if os.path.exists(dirout) == False:
		os.makedirs(dirout)
	dirout = dirout + os.sep  #新路径名称
	try:
		filename = os.path.basename(filepath) #获取文件名
		xlsx_file_reader = load_workbook(filepath)
		for sheet in xlsx_file_reader.get_sheet_names():
			# 每个sheet输出到一个csv文件中，文件名用xlsx文件名和sheet名用'_'连接
			csv_filename = '{xlsx}_{sheet}.csv'.format(
				xlsx=os.path.splitext(filename.replace(' ', '_'))[0],
				sheet=sheet.replace(' ', '_'))

			LogOutDebug("dirout" , dirout + csv_filename)
			csv_file = file(dirout + csv_filename, 'wb')
			LogOutDebug("csv_file" , csv_file)
			csv_file_writer = csv.writer(csv_file)
			
			sheet_ranges = xlsx_file_reader[sheet]
			for row in sheet_ranges.rows:
				row_container = []
				for cell in row:
					if type(cell.value) == unicode:
						row_container.append(cell.value)
					else:
						row_container.append(str(cell.value))
				csv_file_writer.writerow(row_container)
			csv_file.close()

	except Exception as e:
		print(e)
		
################################main函数处理#####################################
def handleArgs(argv): 
	global g_xlsImportPath 
	global g_xlsExportPath
	
	try:
		opts, args = getopt.getopt(argv[1:], 'hvi:o:', ['import='])
	except: 
		Usage()
		sys.exit(2) 
	if len(argv) < 2: 
		Usage()
		return  
	for o, a in opts:
		if o in ('-h', '--help'):
			Usage()
			sys.exit(1)
		elif o in ('-v', '--version'):
			Version()
			sys.exit(0) 
		elif o in ('-i','--import',):
			g_xlsImportPath = a
		elif o in ('-o','--export',):
			g_xlsExportPath = a
		elif o in ('--fre',):
			Fre=a
		else:
			print('unhandled option')
			sys.exit(3) 
			
def main(argv):
	handleArgs(argv)
	LogOutInfo("generate csv from path:" + g_xlsImportPath + " will export to:" + g_xlsExportPath) 
	start()
	LogOutInfo("complete generate csv.") 
	
if __name__ == '__main__': 
	main(sys.argv)


