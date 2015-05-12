#-*- coding: utf-8 -*-
import sys , getopt
import os , re , string
import time , datetime
import binascii
import xml.dom.minidom

from xml.etree.ElementTree import ElementTree
from xml.etree.ElementTree import Element
from xml.etree.ElementTree import SubElement as SE
#sys.reload()
#sys.setdefaultencoding("utf-8") 
#sys.setdefaultencoding("cp936") 
 
g_rpcXmlPath = "testRpc.xml"
################################类定义#####################################
class ParentPoint:
	def __init__(self, parentPoint): 
		self.parentPoint = parentPoint  
 
class RpcMsgs(ParentPoint):
	def __init__(self): 
		super(RpcMsgs , self).__init__(self)
		self.defaultParams = {}
		self.defaultParamsList = {}
		self.rpcs = Rpcs(self)
		self.rpcServerNames = {}

class RpcServerName(ParentPoint):
	"""docstring for RpcServerName"""
	def __init__(self, parentPoint):
		super(RpcServerName, self).__init__(parentPoint)
		self.serverName = None
		self.outputPath = None
		self.include = None
		self.namespace = None
		self.rpcInterface = None 

class DefaultParam(ParentPoint):
	def __init__(self, parentPoint): 
		super(DefaultParam , self).__init__(parentPoint) 
		self.type = None
		self.value = None

class Rpcs(ParentPoint):
	def __init__(self , parentPoint):
		super(Rpcs , self).__init__(parentPoint)  
		self.rpcs = {}
		self.rpcDatas = {} 

class Rpc(ParentPoint):
	def __init__(self , parentPoint):
		super(Rpc , self).__init__(parentPoint) 
		self.call = Call(self)  #这里calls为dic保存所有的call
		self.returns = Return(self)  #这里returns为dic保存所有的return
		self.client = None
		self.server = None
		self.proxy = None
		self.name = None
		self.classes = None
		self.include = None
		self.syncType = 0

class RpcData(ParentPoint):
	def __init__(self , parentPoint):
		super(RpcData , self).__init__(parentPoint)
		self.params = {}   #这里存放所有的params.用dic结构
		self.name = None

class Call(ParentPoint):
	def __init__(self , parentPoint):
		super(Call , self).__init__(parentPoint) 
		self.params = {}  #这里的参数同上

class Return(ParentPoint):
	def __init__(self , parentPoint):
		super(Return , self).__init__(parentPoint)
		self.name = None
		self.params = {}  #这里的参数同上

class Param(ParentPoint):
	def __init__(self , parentPoint):
		super(Param , self).__init__(parentPoint)
		self.name = None
		self.type = None
		self.default = None

################################函数解析XML内容#####################################

g_rpcMsgs=RpcMsgs() 

def start():
	ParseRpcs()
	GenerateRpc()  

def ParseRpcs():  
#使用ElementTree读取节点
	rpcDoc = ElementTree(None , g_rpcXmlPath)  
	xmlRpcMsgs = rpcDoc.getroot() 
	handleRpcMsgs(xmlRpcMsgs) 

def handleRpcMsgs(xmlRpcMsgs):

	for xmlData in xmlRpcMsgs.getchildren(): 
		if xmlData.tag == "DefaultParams":
			handleDefaultParams(g_rpcMsgs.defaultParams , g_rpcMsgs.defaultParamsList , xmlData)
		if xmlData.tag == "Rpcs":
			handleRpcs(g_rpcMsgs.rpcs , xmlData)
		if xmlData.tag == "RpcServerName":
			handleRpcServerName(g_rpcMsgs.rpcServerNames , xmlData)

def handleDefaultParams(defaultParams , defaultParamsList, xmlDefaultParams):

	for attr in xmlDefaultParams.attrib:
		defaultParam = DefaultParam(defaultParams)
		defaultParam.type = attr
		defaultParam.value = xmlDefaultParams.attrib[attr]
		defaultParams[attr] = defaultParam
		defaultParamsList[attr] = "g_rpcDefaultParam_" + attr
		print(defaultParams[attr].type + "  " + defaultParams[attr].value )

def handleRpcServerName(rpcServerNames , xmlRpcServerName):

	rpcServerName = RpcServerName(g_rpcMsgs)

	for attr in xmlRpcServerName.attrib:
		if attr == "serverName":
			rpcServerName.serverName = xmlRpcServerName.attrib[attr]
			print(attr , " " , rpcServerName.serverName) 
		if attr == "outputPath":
			rpcServerName.outputPath = xmlRpcServerName.attrib[attr]
			print(attr ,  " ", rpcServerName.outputPath)
		if attr == "include":
			rpcServerName.include = xmlRpcServerName.attrib[attr]
			print(attr , " " , rpcServerName.include)
		if attr == "namespace":
			rpcServerName.namespace = xmlRpcServerName.attrib[attr]
			print(attr ,  " ", rpcServerName.namespace)
		if attr == "rpcInterface":
			rpcServerName.rpcInterface = xmlRpcServerName.attrib[attr]
			print(attr , " " , rpcServerName.rpcInterface)

	rpcServerNames[rpcServerName.serverName] = rpcServerName

def handleRpcs(rpcs , xmlRpcs):
	for xmlData in xmlRpcs.getchildren(): 
		if xmlData.tag == "RpcData":
			handleRpcData(rpcs.rpcDatas , xmlData)
		if xmlData.tag == "Rpc":
			handleRpc(rpcs.rpcs , xmlData)

def handleRpcData(rpcDatas , xmlrpcData):
	rpcData = RpcData(rpcDatas)
	for attr in xmlrpcData.attrib:
		if attr == "name":
			rpcData.name = xmlrpcData.attrib[attr]
			print(attr , rpcData.name)  

	rpcDatas[attr] = rpcData
	
	for xmlData in xmlrpcData.getchildren(): 
		if xmlData.tag == "Param":
			handleParams(rpcData.params , xmlData)

def handleRpc(rpcs , xmlRpc): 
	rpc = Rpc(rpcs)

	for attr in xmlRpc.attrib:
		if attr == "client":
			rpc.client = xmlRpc.attrib[attr]
			print(attr , rpc.client)  
		if attr == "server":
			rpc.server = xmlRpc.attrib[attr]
			print(attr , rpc.server)  
		if attr == "proxy":
			rpc.proxy = xmlRpc.attrib[attr]
			print(attr , rpc.proxy)  
		if attr == "name":
			rpc.name = xmlRpc.attrib[attr]
			print(attr , rpc.name)
		if attr == "include":
			rpc.include = xmlRpc.attrib[attr]
			print(attr , rpc.include)
		if attr == "class":
			rpc.classes = xmlRpc.attrib[attr]
			print(attr , rpc.classes)
		if attr == "syncType":
			rpc.syncType = xmlRpc.attrib[attr]
			print(attr , rpc.syncType)

	for xmlData in xmlRpc.getchildren(): 
		if xmlData.tag == "Call":
			handleCall(rpc.call , xmlData)
		if xmlData.tag == "Return":
			handleReturn(rpc.returns , xmlData)
	rpcs[rpc.name] = rpc

def handleCall(call , xmlCall): 
	for xmlData in xmlCall.getchildren(): 
		if xmlData.tag == "Param":
			handleParams(call.params , xmlData)

def handleReturn(_return , xmlReturn): 
	for attr in xmlReturn.attrib:
		if attr == "name":
			_return.name = xmlReturn.attrib[attr]
			print(attr , _return.name)

	for xmlData in xmlReturn.getchildren(): 
		if xmlData.tag == "Param":
			handleParams(_return.params , xmlData)
  
def handleParams(params , xmlParam):
	param = Param(params)
	for attr in xmlParam.attrib:
		if attr == "name":
			param.name = xmlParam.attrib[attr]
			print(attr , param.name)  
		if attr == "type":  
			param.type = xmlParam.attrib[attr] 
			print(attr , param.type)  
		if attr == "default":  
			param.default = xmlParam.attrib[attr] 
			print(attr , param.default)  

	params[param.name] = param

################################生成对应文件#####################################

oneTab = "\t"
twoTab = oneTab + "\t"
threeTab = twoTab + "\t"
fourTab = threeTab + "\t"
fiveTab = fourTab + "\t"

def GenerateRpc():
	DeleteServerNameFiles() 
	CreateServerNamePath() 

	GenerateMsgNameDefine()
	GenerateGlableRpc()
	GenerateRpcRegister()
	GenerateRpcHandlers()
	GenerateRpcDatas()
	GenerateRpcCallFuncs()
	GenerateRPCDefines()

def GenerateMsgNameDefine(): 
	sameNamespace = {} 
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():  
		outputPath = GetOutputPath(rpcServerName.serverName)  
		outputPath = outputPath + "MsgNameDefine.h"     
		
		fileRpc = open(outputPath , "a")
		if rpcServerName.namespace not in sameNamespace :
			GenerateRPCParamDefineHeader(fileRpc , rpcServerName.namespace)
			sameNamespace[rpcServerName.namespace] = 1
		
			sameRecord = {}
			for index , rpc in g_rpcMsgs.rpcs.rpcs.items():   
				if rpc.name not in sameRecord :
					GenerateRPCParamDefine(rpc , fileRpc) 
					sameRecord[rpc.name] = 1
			
			fileRpc.close()	

	sameNamespace = {} 
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():  
		outputPath = GetOutputPath(rpcServerName.serverName)  
		outputPath = outputPath + "MsgNameDefine.h"     
		
		if rpcServerName.namespace not in sameNamespace : 
			fileRpc = open(outputPath , "a")
			fileRpc.write("}\n\n#endif\n\n")
			fileRpc.close()	
			sameNamespace[rpcServerName.namespace] = 1

def GenerateRPCParamDefineHeader(fileRpc , namespace):  
	fileRpc.write("#ifndef __msg_" + namespace + "_msg_name_define_h__\n")
	fileRpc.write("#define __msg_" + namespace + "_msg_name_define_h__\n") 
	fileRpc.write("#include \"MsgLib/inc/MsgCommon.h\" \n\n") 
	fileRpc.write("namespace Msg\n") 
	fileRpc.write("{\n") 
	

def GenerateRPCParamDefine(rpc , fileRpc): 
	if rpc.server == "":
		return 
	fileRpc.write(oneTab + "//5 " + rpc.name + " declare here\n")
	fileRpc.write(oneTab + "RPC_DEFINE(" + rpc.name + ");\n\n")
#	strParams = GetParams(rpc.call.params) 
#	print(strParams)
#	fileRpc.write("#define  RPC_DEFINE_" + rpc.name + " public:\\\n")
#	fileRpc.write(oneTab + "Msg::ObjectMsgCall<Object> * " + rpc.name + "_RpcServer(" + strParams + ", std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\n\n")

def GenerateRPCDefines(): 
	sameNamespace = {}   
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():  
		outputPath = GetOutputPath(rpcServerName.serverName)  
		outputPath = outputPath + "RPCDefines.h"    
		 
		fileRpc = open(outputPath , "a")
		if rpcServerName.namespace not in sameNamespace :
			GenerateRPCDefinesHeader(fileRpc , rpcServerName.namespace)
			sameNamespace[rpcServerName.namespace] = 1  
		
		rpcRecords = {}
		for index , rpc in g_rpcMsgs.rpcs.rpcs.items():   
			GenerateRPCDefine(rpc , fileRpc , rpcServerName.serverName , rpcRecords) 
		
		fileRpc.write("\n")
		fileRpc.close()	 
			
	sameNamespace = {} 
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():  
		outputPath = GetOutputPath(rpcServerName.serverName)  
		outputPath = outputPath + "RPCDefines.h"     
		
		if rpcServerName.namespace not in sameNamespace : 
			fileRpc = open(outputPath , "a")
			fileRpc.write("\n}\n\n#endif\n\n")
			fileRpc.close()	
			sameNamespace[rpcServerName.namespace] = 1
			
def GenerateRPCDefinesHeader(fileRpc , namespace):
	fileRpc.write("#ifndef __msg_" + namespace + "_rpc_defines_h__\n")
	fileRpc.write("#define __msg_" + namespace + "_rpc_defines_h__\n") 
	fileRpc.write("#include \"MsgLib/inc/MsgCommon.h\" \n\n") 
	fileRpc.write("namespace Msg\n") 
	fileRpc.write("{\n") 

def GenerateRPCDefine(rpc , fileRpc , serverName , rpcRecords): 
	if serverName == rpc.server:
		strParams = GetParams(rpc.call.params)  
		if rpc.classes not in rpcRecords:
			fileRpc.write("#define  RPC_DEFINE_" + rpc.classes + " public:\\\n")
			rpcRecords[rpc.classes] = 1
		fileRpc.write(oneTab + "Msg::ObjectMsgCall * " + rpc.name + "_RpcServer(" + strParams + "std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\\\n")


def GenerateGlableRpc():
	sameNamespace = {}
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():  
		outputPath = GetOutputPath(rpcServerName.namespace)  
		outputPath = outputPath + "GlobalRpc.h"   
		
		fileRpc = open(outputPath , "a")
		if rpcServerName.namespace not in sameNamespace :
			GenerateGlableRpcHeaderNamespace(fileRpc , rpcServerName.namespace)
			sameNamespace[rpcServerName.namespace] = 1
		
		GenerateGlableRpcClass(g_rpcMsgs.rpcs.rpcs , fileRpc , rpcServerName.serverName) 
		fileRpc.close()	

	sameNamespace = {}
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():  
		outputPath = GetOutputPath(rpcServerName.namespace)  
		outputPath = outputPath + "GlobalRpc.h"   
		
		if rpcServerName.namespace not in sameNamespace :
			fileRpc = open(outputPath , "a")
			GenerateGlableRpcLastNamespace(fileRpc , rpcServerName.namespace)
			sameNamespace[rpcServerName.namespace] = 1  
			fileRpc.close()	
		 
#生成GlableRpc头部部分.
def GenerateGlableRpcHeaderNamespace(fileRpc , namespace): 
	fileRpc.write("#ifndef __" + namespace + "_global_rpc_h__\n") 
	fileRpc.write("#define __" + namespace + "_global_rpc_h__\n") 
	fileRpc.write("#include \"Common/Chunk.h\" \n") 
	fileRpc.write("#include \"MsgLib/inc/Object.h\" \n") 
	fileRpc.write("#include \"MsgLib/inc/MsgCommon.h\" \n") 
	fileRpc.write("#include \"MsgLib/inc/RPCMsgCall.h\" \n") 
	fileRpc.write("#include \"MsgLib/inc/RpcServerManager.h\" \n") 
	fileRpc.write("#include \"MsgLib/inc/IRpcMsgCallableObject.h\" \n") 
	fileRpc.write("#include \"RpcDatas.h\" \n") 
	fileRpc.write("\n") 
	fileRpc.write("namespace Msg" + "\n{\n") 
	
	fileRpc.write(oneTab + "class GlobalRpc : public Msg::IRpcMsgCallableObject\n") 
	fileRpc.write(oneTab + "{\n") 
	fileRpc.write(oneTab + "public:\n") 
	fileRpc.write(twoTab + "GlobalRpc(Msg::Object nID , Msg::RpcManager * pRpcManager)\n") 
	fileRpc.write(threeTab + ": Msg::IRpcMsgCallableObject(nID , pRpcManager)\n") 
	fileRpc.write(twoTab + "{\n")  
	fileRpc.write(twoTab +"}\n")   
	fileRpc.write(oneTab +"public:\n")  
	
def GenerateGlableRpcClass(rpcs , fileRpc , serverName): 

	#生成函数声明.部分文件有.
	for index , rpc in rpcs.items():  
		if rpc.client == serverName:
			fileRpc.write(twoTab + "//" + rpc.name + " generate RPC func here\n")
			strDefaultParams = GetParams(rpc.call.params)  
			fileRpc.write(twoTab + "Msg::ObjectMsgCall * " + rpc.name + "_RpcTimeout(" + strDefaultParams + "std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\n")
			strDefaultParams = GetParams(rpc.returns.params)  
			fileRpc.write(twoTab + "Msg::ObjectMsgCall * " + rpc.name + "_RpcClient(" + strDefaultParams + "std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\n")
	
		elif rpc.proxy == serverName:
			fileRpc.write(twoTab + "//" + rpc.name + " generate RPC func here\n")
			strDefaultParams = GetParams(rpc.call.params)
			fileRpc.write(twoTab + "Msg::ObjectMsgCall * " + rpc.name + "_RpcServerProxy(" + strDefaultParams + "std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\n")
			fileRpc.write(twoTab + "Msg::ObjectMsgCall * " + rpc.name + "_RpcTimeout(" + strDefaultParams + "std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\n")
			strDefaultParams = GetParams(rpc.returns.params)
			fileRpc.write(twoTab + "Msg::ObjectMsgCall * " + rpc.name + "_RpcClientProxy(" + strDefaultParams + "std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\n\n")
			
		elif rpc.server == serverName: 
			pass 

	fileRpc.write(twoTab + "\n")
	
#生成GlableRpc尾部部分.
def GenerateGlableRpcLastNamespace(fileRpc , namespace):  
	fileRpc.write(oneTab + "};\n\n")
	fileRpc.write(oneTab + "extern GlobalRpc * g_pGlobalRpc;\n")
	fileRpc.write("}\n\n")
	fileRpc.write("#endif\n\n")
	
def GenerateRpcRegister():   
	#生成注册的头 
	sameNamespace = {}   
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():  
		outputPath = GetOutputPath(rpcServerName.serverName)  
		outputPath = outputPath + "RpcRegister.cpp"    
 
		fileRpc = open(outputPath , "a")    
		if rpcServerName.namespace not in sameNamespace :
			GenerateRpcRegisterHeader(fileRpc , rpcServerName.namespace)
			sameNamespace[rpcServerName.namespace] = 1  
			
		fileRpc.write(oneTab + "void " + rpcServerName.rpcInterface + "::OnRegisterRpcs( void )\n")
		fileRpc.write(oneTab + "{\n")
		fileRpc.write(twoTab + "Assert(m_pRpcServerManager && Msg::g_pRpcCheckParams);	\n")
		fileRpc.write(twoTab + "Msg::GlobalRpc * g_pGlobalRpc  = new Msg::GlobalRpc( Msg::DEFAULT_RPC_CALLABLE_ID , m_pRpcServerManager); \n\n") 

		fileRpc.write(twoTab + "Msg::Parameters objDeliverParams , objReturnParams;\n")
		
		for index , rpc in g_rpcMsgs.rpcs.rpcs.items():  
			fileRpc.write(twoTab + "//5 " + rpc.name + " generate default deliver and return check param here\n")
			fileRpc.write(twoTab + "{\n")
			strDefaultParams = GetRpcParamsIncludeDefault(rpc.call)
			fileRpc.write(threeTab + "Msg::GenMsgHelper::GenMsgParams(objDeliverParams " + strDefaultParams +  ");\n") 
			strDefaultParams = GetRpcParamsIncludeDefault(rpc.returns)
			fileRpc.write(threeTab + "Msg::GenMsgHelper::GenMsgParams(objReturnParams " + strDefaultParams +  ");\n") 
			fileRpc.write(threeTab + "Msg::g_pRpcCheckParams->InsertDeliverParams(" + "\"" + rpc.name  + "\", objDeliverParams);\n") 
			fileRpc.write(threeTab + "Msg::g_pRpcCheckParams->InsertReturnParams(" + "\"" + rpc.name  +  "\", objReturnParams);\n") 
			fileRpc.write(threeTab + "objDeliverParams.Clear();\n") 
			fileRpc.write(threeTab + "objReturnParams.Clear();\n") 
			GenerateRpcRegisterFuncs(rpc , fileRpc , rpcServerName.serverName)
			fileRpc.write(twoTab +"}\n\n") 

		fileRpc.write(oneTab + "}\n\n")
		fileRpc.close() 
		
	sameNamespace = {}
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():  
		outputPath = GetOutputPath(rpcServerName.namespace)  
		outputPath = outputPath + "RpcRegister.cpp"    
		
		if rpcServerName.namespace not in sameNamespace :
			fileRpc = open(outputPath , "a")
			fileRpc.write("}\n\n") 
			sameNamespace[rpcServerName.namespace] = 1 
			fileRpc.close()	 

def GenerateRpcRegisterHeader(fileRpc , rpcNamespace) :
	fileRpc.write("#include \"MsgLib/inc/RpcBase.h\"\n")
	fileRpc.write("#include \"MsgLib/inc/MsgCommon.h\"\n")
	fileRpc.write("#include \"MsgLib/inc/RpcServerManager.h\"\n")
	fileRpc.write("#include \"MsgLib/inc/RpcCheckParams.h\"\n") 
	fileRpc.write("#include \"MsgLib/inc/IRpcMsgCallableObject.h\"\n") 
	fileRpc.write("#include \"Common/Chunk.h\"\n") 
	fileRpc.write("#include \"GlobalRpc.h\"\n")  
	fileRpc.write("#include \"MsgNameDefine.h\"\n")  
#	fileRpc.write("#include \"" + rpcServerName.include + "\"\n")
	GenerateRpcRegisterHeaderInclude(fileRpc , rpcNamespace)

	sameNamespace = {}
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():
		if rpcServerName.namespace == rpcNamespace : 
			sameNamespace[rpcServerName.serverName] = 1 
			
	for index , rpcNamespace in sameNamespace.items():   
		GenerateRpcRegisterServerHeader(g_rpcMsgs.rpcs.rpcs , fileRpc , index)
 
	fileRpc.write("\n") 

	fileRpc.write("namespace " + rpcServerName.namespace + "\n{\n")
	fileRpc.write(oneTab + "//5 defaultParams define here.\n")
	WriteDefaultParams(fileRpc)
	
def GenerateRpcRegisterHeaderInclude(fileRpc , rpcNamespace): 
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():  
		if rpcNamespace == rpcServerName.namespace :
			fileRpc.write("#include \"" + rpcServerName.include + "\"\n")
	
def GenerateRpcRegisterServerHeader(rpcs , fileRpc , serverName):
	
	sameRecord = {}
	#生成所有的rpc
	for index , rpc in rpcs.items():     
		if rpc.server == serverName and rpc.include not in sameRecord: 
			fileRpc.write("#include \"" + rpc.include + "\"\n") 
			sameRecord[rpc.include] = 1

def GenerateRpcRegisterFuncs(rpc , fileRpc , serverName):
	#生成所有的rpc  
	if rpc.server == serverName: 
		fileRpc.write(threeTab + "m_pRpcServerManager->RegisterFunc<"+ rpc.classes + " >(Msg::g_sz" + rpc.name + "_RpcServer , &" + rpc.classes + "::" + rpc.name + "_RpcServer); \n") 
  
	if rpc.proxy == serverName: 
		fileRpc.write(threeTab + "\n")
		fileRpc.write(threeTab + "m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_sz" + rpc.name + "_RpcServerProxy , &Msg::GlobalRpc::" + rpc.name + "_RpcServerProxy); \n") 
		fileRpc.write(threeTab + "m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_sz" + rpc.name + "_RpcClientProxy , &Msg::GlobalRpc::" + rpc.name + "_RpcClientProxy); \n") 
		fileRpc.write(threeTab + "m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_sz" + rpc.name + "_RpcTimeout , &Msg::GlobalRpc::" + rpc.name + "_RpcTimeout); \n") 
  
	if rpc.client == serverName: 
		fileRpc.write(threeTab + "m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_sz" + rpc.name + "_RpcTimeout , &Msg::GlobalRpc::" + rpc.name + "_RpcTimeout); \n") 
		fileRpc.write(threeTab + "m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_sz" + rpc.name + "_RpcClient , &Msg::GlobalRpc::" + rpc.name + "_RpcClient); \n") 
	  
def GenerateRpcHandlers():
	#生成注册的头 
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():   
		GenerateRpcHandler(g_rpcMsgs.rpcs.rpcs , rpcServerName.serverName, rpcServerName.namespace) 

def GenerateRpcHandler(rpcs , serverName , namespace):
	#生成所有的rpc
	for index , rpc in rpcs.items():    
		
		if rpc.client == serverName: 
			outputPath = GetOutputPath(serverName)  
			outputPath += rpc.name
			outputPath += "_RpcClient.cpp"

			if IsPathExist(outputPath):
#				os.remove(outputPath)
				continue

			fileRpc = open(outputPath , "a")   

			fileRpc.write("#include \"GlobalRpc.h\"\n\n")
			fileRpc.write("Msg::ObjectMsgCall * Msg::GlobalRpc::" + rpc.name + "_RpcClient(")
			strParams = GetParamsExcludeDefault(rpc.returns.params) 
			fileRpc.write(strParams + "std::vector<Msg::Object> vecTargets , Msg::Object objSrc) \n{\n\n\n")

			fileRpc.write(oneTab + "std::cout << \"" + rpc.name + "_RpcClient\" << std::endl;\n")
			fileRpc.write(oneTab + "RPCReturnNULL;\n}\n\n")

			fileRpc.write("Msg::ObjectMsgCall * Msg::GlobalRpc::" + rpc.name + "_RpcTimeout(") 
			strParams = GetParamsExcludeDefault(rpc.call.params) 
			fileRpc.write(strParams + "std::vector<Msg::Object> vecTargets , Msg::Object objSrc) \n{\n\n\n")
			fileRpc.write(oneTab + "std::cout << \"" + rpc.name + "_RpcTimeout\" << std::endl;\n")
			fileRpc.write(oneTab + "RPCReturnNULL;\n}\n\n")

			fileRpc.close()

		if rpc.proxy == serverName: 
			outputPath = GetOutputPath(serverName)  
			outputPath += rpc.name
			outputPath += "_RpcProxy.cpp"

			if IsPathExist(outputPath):
#				os.remove(outputPath)
				continue

			fileRpc = open(outputPath , "a")   

			fileRpc.write("#include \"GlobalRpc.h\"\n\n")

			fileRpc.write("Msg::ObjectMsgCall * Msg::GlobalRpc::" + rpc.name + "_RpcServerProxy(")
			strParams = GetParamsExcludeDefault(rpc.call.params) 
			fileRpc.write(strParams + "std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )\n{\n\n\n ")
			
			strParamsNoType= GetParamsExcludeDefaultAndType(rpc.call.params)
			fileRpc.write(oneTab + "ProxySendMsg(\"tcp://127.0.0.1:8002\" , " + strParamsNoType + ");\n")
			
			strParamsNoType= GetParamsExcludeDefaultAndType(rpc.returns.params)
			strReturnCount = len(rpc.returns.params)
			fileRpc.write(oneTab + "std::cout << \"" + rpc.name + "_RpcServerProxy\" << std::endl;\n")
			fileRpc.write(oneTab + "//RPCReturn" + str(strReturnCount) + "(" + strParamsNoType + ");\n") 
			fileRpc.write(oneTab + "RPCReturnNULL;\n}\n\n")

			fileRpc.write("Msg::ObjectMsgCall * Msg::GlobalRpc::" + rpc.name + "_RpcClientProxy(") 
			strParams = GetParamsExcludeDefault(rpc.returns.params) 
			fileRpc.write(strParams + "std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )\n{\n ")
			WriteDefineParams(fileRpc , rpc.returns.params)
			fileRpc.write("\n\n")
			
			fileRpc.write(oneTab + "std::cout << \"" + rpc.name + "_RpcClientProxy\" << std::endl;\n")

			strParamsNoType= GetParamsExcludeDefaultAndType(rpc.returns.params)
			strReturnCount = len(rpc.returns.params)
			fileRpc.write(oneTab + "RPCReturn" + str(strReturnCount) + "(" + strParamsNoType + ");\n}\n\n")

			strParams = GetParamsExcludeDefault(rpc.call.params) 
			fileRpc.write("Msg::ObjectMsgCall * Msg::GlobalRpc::" + rpc.name + "_RpcTimeout(")
			fileRpc.write(strParams + "std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )\n{\n\n\n ")
			fileRpc.write(oneTab + "std::cout << \"" + rpc.name + "_RpcTimeout\" << std::endl;\n")
			fileRpc.write(oneTab + "RPCReturnNULL;\n}\n\n")

			fileRpc.close()

		if rpc.server == serverName: 
			outputPath = GetOutputPath(serverName)  
			outputPath += rpc.name
			outputPath += "_RpcServer.cpp"

			if IsPathExist(outputPath):
#				os.remove(outputPath)
				continue

			fileRpc = open(outputPath , "a")   

			fileRpc.write("#include \"GlobalRpc.h\"\n") 
			fileRpc.write("#include \"" + rpc.include + "\"\n\n") 

			fileRpc.write("Msg::ObjectMsgCall * " + namespace + "::" + rpc.classes + "::" + rpc.name + "_RpcServer(")
			strParams = GetParamsExcludeDefault(rpc.call.params)
			fileRpc.write(strParams + "std::vector<Msg::Object> vecTargets , Msg::Object objSrc )\n{\n")
			WriteDefineParams(fileRpc , rpc.returns.params)
			fileRpc.write("\n\n")
			
			strParamsNoType= GetParamsExcludeDefaultAndType(rpc.returns.params)
			strReturnCount = len(rpc.returns.params)
			fileRpc.write(oneTab + "std::cout << \"" + rpc.name + "_RpcServer \"<< std::endl;\n")
			fileRpc.write(oneTab + "RPCReturn" + str(strReturnCount) + "(" + strParamsNoType + ");\n}\n\n")
  
			fileRpc.close() 
 
def GenerateRpcDatas():
	#生成所有的rpc
	for index , serverName in g_rpcMsgs.rpcServerNames.items():    
		outputPath = GetOutputPath(serverName.serverName)   
		outputPath += "RpcDatas.h" 
			
		fileRpc = open(outputPath , "a")

		for index , rpcData in g_rpcMsgs.rpcs.rpcDatas.items():  
			pass
#			fileRpc.write("template<typename Object>\n")
#			fileRpc.write("ObjectMsgCall<Object> * Rpc<Object>::" + rpcData.name + "_RpcServer(")
#			strParams = GetParamsExcludeDefault(rpcData.params)
#			fileRpc.write(strParams + ", std::vector<Object> vecTargets , Object objSrc ) \n{\n\n\n RPCReturnNULL;\n}\n\n")
			
		fileRpc.close()

def GenerateRpcCallFuncs(): 
	sameNamespace = {} 
	for index , serverName in g_rpcMsgs.rpcServerNames.items(): 
		outputPath = GetOutputPath(serverName.serverName)   
		outputPath += "RPCCallFuncs.h" 
			 
		fileRpc = open(outputPath , "a")
		if serverName.namespace not in sameNamespace :
			GenerateRpcCallFuncsHeader(fileRpc , serverName)
			sameNamespace[serverName.namespace] = 1 
		
		for index , rpc in g_rpcMsgs.rpcs.rpcs.items(): 
			if serverName.serverName == rpc.client:		
				strParams = GetParamsExcludeDefault(rpc.call.params) 
				syncType = GetSyncTypeInString(rpc.syncType)
				fileRpc.write(oneTab + "static INT32  local_call_" + rpc.name + "(const char * pSessionName , " + strParams + "std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = " +syncType + ")\n")
				fileRpc.write(oneTab + "{\n")
				
				strParams = GetParamsExcludeDefaultAndType(rpc.call.params) 
				strParamsCount = len(rpc.call.params)
				fileRpc.write(twoTab + "GEN_RPC_CALL_" + str(strParamsCount) + "((&(" + serverName.namespace + "::" + serverName.rpcInterface + "::GetInstance())) , pSessionName , " + "Msg::g_sz" + rpc.name + "_RpcCall , " + strParams + " vecTargets , objSrc , usPriority , " + serverName.namespace + "::" + serverName.rpcInterface + "::GetInstance().GetServerName() , objSyncType);\n")
				fileRpc.write(oneTab + "}\n\n")	
				
		fileRpc.close()
			
	sameNamespace = {} 
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():  
		outputPath = GetOutputPath(rpcServerName.serverName)  
		outputPath = outputPath + "RPCCallFuncs.h"     
		
		if rpcServerName.namespace not in sameNamespace : 
			fileRpc = open(outputPath , "a")
			fileRpc.write("}\n\n")	
			fileRpc.write("#endif\n")				
			fileRpc.close()
			sameNamespace[rpcServerName.namespace] = 1
			

def  GenerateRpcCallFuncsHeader(fileRpc , serverName):
	fileRpc.write("#ifndef __msg_rpc_call_funcs_h__\n")
	fileRpc.write("#define __msg_rpc_call_funcs_h__\n")
	fileRpc.write("\n")
	fileRpc.write("#include \"MsgLib/inc/MsgHelper.h\"\n") 
	fileRpc.write("#include \"MsgLib/inc/RPCMsgCall.h\"\n")  
	fileRpc.write("#include \"MsgNameDefine.h\"\n") 
	for index , serverNames in g_rpcMsgs.rpcServerNames.items(): 
		if serverNames.namespace == serverName.namespace:
			fileRpc.write("#include \"" + serverNames.include + "\"\n") 
	
	fileRpc.write("\n") 
	fileRpc.write("namespace " + serverName.namespace + "\n") 
	fileRpc.write("{\n") 
#	fileRpc.write("#ifndef MSG_INSTANCE\n") 
#	fileRpc.write("#error \"need define marcor MSG_INSTANCE for rpc use.\"\n") 
#	fileRpc.write("#endif\n") 

		
################################流程无关函数处理#####################################
def Usage():
    print('PyTest.py usage:')
    print('-h,--help: print help message.')
    print('-v, --version: print script version')
    print('-o, --output: input an output verb')
    print('--foo: Test option ')
    print('--fre: another test option')

def Version():
	print('GenerateRpc.py 1.0.0.0.1')

def CheckInRpcServerName(name):
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():
		if rpcServerName.serverName == name: 
			return True

	assert(0 , "no this serverName in serverNamelist")

def GetOutputPath(name):
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items(): 
		if rpcServerName.serverName == name:
			if os.path.exists(rpcServerName.outputPath):  
				return rpcServerName.outputPath
			else: 
#				os.makedirs(rpcServerName.outputPath)
				return rpcServerName.outputPath

	assert(0 , "no path is serverNamelist")

def IsPathExist(path):
	if os.path.exists(path):
		return True
	else:
		return False

def GetParams(params):
	strParams = ""
	nCount = 0
	for index , param in params.items(): 
		nCount += 1

		strParams = strParams + param.type
		strParams = strParams + " "
		strParams = strParams + param.name
		strParams = strParams + " = "

		if param.default == "" or param.default == None:
			strParams = strParams + GetAndCheckDefaultParam(param.type)
		else:
			strParams = strParams + param.default
 
		if nCount != len(params):
			strParams = strParams + " , " 

	if len(params) != 0:
		strParams += ", "
		
	return strParams

def WriteDefaultParams(fileRpc):
	for index , defaultParam in g_rpcMsgs.defaultParams.items():
		fileRpc.write(oneTab + "static " + defaultParam.type + " g_rpcDefaultParam_" + defaultParam.type + " = " + defaultParam.value + ";\n")
	fileRpc.write("\n")

def GetRpcParamsIncludeDefault(call):
	strParams = ""

#	if len(call.params) != 0:
#		strParams += ", "
		
	nCount = 0
	for index , param in call.params.items():
#		if nCount != 0:
		strParams += " , "
		
		nCount = nCount + 1
		strParams += GetDefaultParamValue(param.type)

	return strParams
def WriteDefaultParams(fileRpc):
	for index , defaultParam in g_rpcMsgs.defaultParams.items():
		fileRpc.write(oneTab + "static " + defaultParam.type + " g_rpcDefaultParam_" + defaultParam.type + " = " + defaultParam.value + ";\n")
	fileRpc.write("\n")
	
def WriteDefineParams(fileRpc , params):
	for index , param in params.items():  
		strParams = oneTab 
		strParams += param.type
		strParams += " "
		strParams += param.name
		strParams += " = "

		if param.default == "" or param.default == None:
			strParams += GetAndCheckDefaultParam(param.type)
		else:
			strParams += param.default

		strParams += ";\n" 
		fileRpc.write(strParams) 

def GetParamsExcludeDefault(params):
	strParams = ""
	nCount = 0
	for index , param in params.items(): 
		nCount += 1

		strParams = strParams + param.type
		strParams = strParams + " "
		strParams = strParams + param.name
		strParams = strParams + "/* = "

		if param.default == "" or param.default == None:
			strParams = strParams + GetAndCheckDefaultParam(param.type)
		else:
			strParams = strParams + param.default

		strParams += "*/"
 
		if nCount != len(params):
			strParams = strParams + " , " 

	if len(params) != 0:
		strParams += ", "
	return strParams

def GetParamsExcludeDefaultAndType(params):
	strParams = ""
	nCount = 0
	for index , param in params.items(): 

		nCount += 1
		strParams = strParams + param.name

		if nCount != len(params):
			strParams = strParams + " , " 

	if len(params) != 0:
		strParams += ", "
		
	return strParams

def GetAndCheckDefaultParam(paramType):
	for index , defaultParam in g_rpcMsgs.defaultParams.items():
		if defaultParam.type == paramType: 
			return defaultParam.value

	assert(0 , "no this value in defaultParamsList")

def DeleteServerNameFiles():
	for index , serverName in g_rpcMsgs.rpcServerNames.items():
		if os.path.exists(serverName.outputPath + "MsgNameDefine.h"): 
			os.remove(serverName.outputPath + "MsgNameDefine.h")
		if os.path.exists(serverName.outputPath + "RPCCallFuncs.h"): 
			os.remove(serverName.outputPath + "RPCCallFuncs.h")
		if os.path.exists(serverName.outputPath + "RpcDatas.h"): 
			os.remove(serverName.outputPath + "RpcDatas.h")
		if os.path.exists(serverName.outputPath + "RPCDefines.h"): 
			os.remove(serverName.outputPath + "RPCDefines.h")
		if os.path.exists(serverName.outputPath + "GlobalRpc.h"): 
			os.remove(serverName.outputPath + "GlobalRpc.h") 
		if os.path.exists(serverName.outputPath + "RpcRegister.cpp"): 
			os.remove(serverName.outputPath + "RpcRegister.cpp") 

def CreateServerNamePath(): 
	for index , serverName in g_rpcMsgs.rpcServerNames.items():
		if False == os.path.exists(serverName.outputPath):
			print(serverName.outputPath)
			os.makedirs(serverName.outputPath)
			
def GetDefaultParamValue(paramType):
	for index , param in g_rpcMsgs.defaultParamsList.items():
		if paramType == index:
			return param 
	assert(0 ,  "no this defaultParam value in defaultParamsList")

def GetSyncTypeInString(syncType):
	if syncType == "0":
		return "Msg::SYNC_TYPE_SYNC"
	elif syncType == "1":
		return "Msg::SYNC_TYPE_NONSYNC"
	else:
		return "Msg::SYNC_TYPE_SYNC" 
	
################################main函数处理#####################################
def handleArgs(argv): 
	global g_rpcXmlPath
	try:
		opts, args = getopt.getopt(argv[1:], 'hvo:', ['import='])
	except: 
		Usage()
		sys.exit(2) 
	if len(argv) == 1: 
		g_rpcXmlPath = "testRpc.xml"
		return
	elif len(argv) == 2:  
		g_rpcXmlPath = argv[1]
		return  
	for o, a in opts:
		if o in ('-h', '--help'):
			Usage()
			sys.exit(1)
		elif o in ('-v', '--version'):
			Version()
			sys.exit(0) 
		elif o in ('--import',):
			g_rpcXmlPath = a
		elif o in ('--fre',):
			Fre=a
		else:
			print('unhandled option')
			sys.exit(3) 
			
def main(argv):
	handleArgs(argv)
	print(g_rpcXmlPath)
	start()  
	
if __name__ == '__main__':
	main(sys.argv)

