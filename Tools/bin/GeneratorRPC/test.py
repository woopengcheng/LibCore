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

g_rpcXmlPath = "testRpc.xml"
g_rpcMsgs=RpcMsgs() 

def main():
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
			handerRpcServerName(g_rpcMsgs.rpcServerNames , xmlData)

def handleDefaultParams(defaultParams , defaultParamsList, xmlDefaultParams):

	for attr in xmlDefaultParams.attrib:
		defaultParam = DefaultParam(defaultParams)
		defaultParam.type = attr
		defaultParam.value = xmlDefaultParams.attrib[attr]
		defaultParams[attr] = defaultParam
		defaultParamsList[attr] = "g_rpcDefaultParam_" + attr
		print(defaultParams[attr].type + "  " + defaultParams[attr].value )

def handerRpcServerName(rpcServerNames , xmlRpcServerName):

	rpcServerName = RpcServerName(g_rpcMsgs)

	for attr in xmlRpcServerName.attrib:
		if attr == "serverName":
			rpcServerName.serverName = xmlRpcServerName.attrib[attr]
			print(attr , rpcServerName.serverName) 
		if attr == "outputPath":
			rpcServerName.outputPath = xmlRpcServerName.attrib[attr]
			print(attr , rpcServerName.outputPath)

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

	GenerateRpcDefines()
	GenerateGlableRpc()
	GenerateRpcRegister()
	GenerateRpcHandlers()
	GenerateRpcDatas()

def GenerateRpcDefines(): 
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():  
		outputPath = GetOutputPath(rpcServerName.serverName)  
		outputPath = outputPath + "RpcDefines.h"    
	
		fileRpc = open(outputPath , "a")  
		fileRpc.write("#ifndef __" + rpcServerName.serverName + "_rpc_defines_h__\n")
		fileRpc.write("#define __" + rpcServerName.serverName + "_rpc_defines_h__\n") 
		fileRpc.write("#include \"MsgCommon.h\" \n\n") 

		for index , rpc in g_rpcMsgs.rpcs.rpcs.items():   
			GenerateRpcServerDefines(rpc , fileRpc) 

		fileRpc.write("\n#endif\n\n")
		fileRpc.close()	

def GenerateRpcServerDefines(rpc , fileRpc): 
	if rpc.server == "":
		return 

	fileRpc.write("//5 " + rpc.name + " declare here\n") 
	
	strParams = GetParams(rpc.call.params) 
	print(strParams)
	fileRpc.write("#define  RPC_DEFINE_" + rpc.name + "public:\\\n")
	fileRpc.write(oneTab + "Msg::ObjectMsgCall<Object> * " + rpc.name + "_RpcServer(" + strParams + ", std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\n\n")
 
def GenerateGlableRpc(): 
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():  
		outputPath = GetOutputPath(rpcServerName.serverName)  
		outputPath = outputPath + "GlobalRpc.h"    
	
		fileRpc = open(outputPath , "a")  
		fileRpc.write("#include \"RPCMsgCall.h\" \n") 
		fileRpc.write("#include \"RpcServerManager.h\" \n") 
		fileRpc.write("#include \"RpcInstance.h\" \n") 
		fileRpc.write("#include \"Chunk.h\" \n\n") 
		fileRpc.write("namespace " + rpcServerName.serverName + "\n{\n") 
		fileRpc.write(oneTab + "// static defaultParams define here. \n") 
		
		WriteDefaultParams(fileRpc)
		fileRpc.write(oneTab + "class GlobalRpc : public Msg::IRpcMsgCallableObject\n") 
		fileRpc.write(oneTab + "{\n") 
		fileRpc.write(oneTab + "public:\n") 
		fileRpc.write(twoTab + "GlobalRpc(Msg::Object nID = Msg::DEFAULT_RPC_CALLABLE_ID , Msg::RpcManager * pRpcManager = RpcInstance::GetInstance().GetRpcServerManager())\n") 
		fileRpc.write(threeTab + ": Msg::IRpcMsgCallableObject(nID , pRpcManager)\n") 
		fileRpc.write(twoTab + "{\n") 
		fileRpc.write(threeTab + "Msg::Parameters objDeliverParams , objReturnParams;\n\n") 

		GenerateGlableRpcClass(g_rpcMsgs.rpcs.rpcs , fileRpc , rpcServerName.serverName) 
 
def GenerateGlableRpcClass(rpcs , fileRpc , serverName): 
	#生成所有的rpc的检查参数部分,所有文件都有
	for index , rpc in rpcs.items():  
		fileRpc.write(threeTab + "//" + rpc.name + " generate default deliver and return check param here\n")
		fileRpc.write(threeTab + "{\n")
		strDefaultParams = GetRpcParamsIncludeDefault(rpc.call)
		fileRpc.write(fourTab + "Msg::GenMsgHelper::GenMsgParams(objDeliverParams ," + strDefaultParams +  ");\n") 
		strDefaultParams = GetRpcParamsIncludeDefault(rpc.returns)
		fileRpc.write(fourTab + "Msg::GenMsgHelper::GenMsgParams(objReturnParams ," + strDefaultParams +  ");\n") 
		fileRpc.write(fourTab + "InsertDeliverParams(" + "\"" + rpc.name  + "\");\n") 
		fileRpc.write(fourTab + "InsertReturnParams(" + "\"" + rpc.name  +  "\");\n") 
		fileRpc.write(fourTab + "objDeliverParams.Clear();\n") 
		fileRpc.write(fourTab + "objReturnParams.Clear();\n") 
		fileRpc.write(threeTab +"}\n\n") 

	fileRpc.write(twoTab +"}\n")   
	fileRpc.write(oneTab +"public:\n")  

	#生成函数声明.部分文件有.
	for index , rpc in rpcs.items():  
		if rpc.client == serverName:
			fileRpc.write(twoTab + "//" + rpc.name + " generate RPC func here\n")
			strDefaultParams = GetRpcParamsIncludeDefault(rpc.call)
			fileRpc.write(twoTab + "Msg::ObjectMsgCall<Object> * " + rpc.name + "_RpcTimeout(" + strDefaultParams + ", std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\n")
			strDefaultParams = GetRpcParamsIncludeDefault(rpc.returns)
			fileRpc.write(twoTab + "Msg::ObjectMsgCall<Object> * " + rpc.name + "_RpcClient(" + strDefaultParams + ", std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\n")
	
		elif rpc.proxy == serverName:
			fileRpc.write(twoTab + "//" + rpc.name + " generate RPC func here\n")
			strDefaultParams = GetRpcParamsIncludeDefault(rpc.call)
			fileRpc.write(twoTab + "Msg::ObjectMsgCall<Object> * " + rpc.name + "_RpcServerProxy(" + strDefaultParams + ", std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\n")
			fileRpc.write(twoTab + "Msg::ObjectMsgCall<Object> * " + rpc.name + "_RpcClientTimeout(" + strDefaultParams + ", std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\n")
			strDefaultParams = GetRpcParamsIncludeDefault(rpc.returns)
			fileRpc.write(twoTab + "Msg::ObjectMsgCall<Object> * " + rpc.name + "_RpcClientProxy(" + strDefaultParams + ", std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\n\n")
			
		elif rpc.server == serverName: 
			pass

	fileRpc.write(oneTab + "};\n")
	fileRpc.write("}\n\n")
	fileRpc.write("#endif\n\n")
  
def GenerateRpcRegister(): 
	fileRpc = None
	
	#生成注册的头 
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():  
		outputPath = GetOutputPath(rpcServerName.serverName)  
		outputPath = outputPath + "RpcRegister.cpp"    
 
		fileRpc = open(outputPath , "a")   
		fileRpc.write("#include \"MsgCommon.h\"\n")
		fileRpc.write("#include \"RpcInstance.h\"\n")
		fileRpc.write("#include \"MsgNameDefine.h\"\n")
		fileRpc.write("#include \"RpcServerManager.h\"\n")
		fileRpc.write("#include \"RpcBase.h\"\n")
		fileRpc.write("#include \"GlobalRpc.h\"\n") 

		GenerateRpcRegisterServerHeader(g_rpcMsgs.rpcs.rpcs , fileRpc , rpcServerName.serverName)
		fileRpc.write("\n") 

		fileRpc.write("namespace " + rpcServerName.serverName + "\n{\n")
		fileRpc.write(oneTab + "void RpcInstance::OnRegisterRpcs( void )\n")
		fileRpc.write(oneTab + "{\n")
		fileRpc.write(twoTab + "Assert(GetRpcServerManager());	\n")
		fileRpc.write(twoTab + "static GlobalRpc objRpc; \n\n") 

		GenerateRpcRegisterFuncs(g_rpcMsgs.rpcs.rpcs , fileRpc , rpcServerName.serverName)

#		GenerateRpcRegisterClientClient(g_rpcMsgs.rpcs.rpcs , fileRpc , rpcServerName.serverName)
#		GenerateRpcRegisterClientProxy(g_rpcMsgs.rpcs.rpcs , fileRpc , rpcServerName.serverName)

		fileRpc.write(oneTab + "}\n\n")
		fileRpc.write("}\n\n")  

		fileRpc.close()	

def GenerateRpcRegisterServerHeader(rpcs , fileRpc , serverName):
	#生成所有的rpc
	for index , rpc in rpcs.items():     
		if rpc.server == serverName: 
			fileRpc.write("#include \"" + rpc.include + "\"\n") 


def GenerateRpcRegisterFuncs(rpcs , fileRpc , serverName):
	#生成所有的rpc
	for index , rpc in rpcs.items():    
		if rpc.server == serverName: 
			fileRpc.write(twoTab + "GetRpcServerManager()->RegisterFunc<"+ rpc.name + " >(Msg::g_sz" + rpc.name + "_RpcServer , &" + rpc.name + "::" + rpc.name + "_RpcServer); \n") 
	  
		if rpc.proxy == serverName: 
			fileRpc.write(twoTab + "")
			fileRpc.write(twoTab + "GetRpcServerManager()->RegisterFunc<GlobalRpc>(Msg::g_sz" + rpc.name + "_RpcServerProxy , &GlobalRpc::" + rpc.name + "_RpcServerProxy); \n") 
			fileRpc.write(twoTab + "GetRpcServerManager()->RegisterFunc<GlobalRpc>(Msg::g_sz" + rpc.name + "_RpcClientProxy , &GlobalRpc::" + rpc.name + "_RpcClientProxy); \n") 
			fileRpc.write(twoTab + "GetRpcServerManager()->RegisterFunc<GlobalRpc>(Msg::g_sz" + rpc.name + "_RpcTimeoutProxy , &GlobalRpc::" + rpc.name + "_RpcTimeoutProxy); \n") 
	  
		if rpc.client == serverName: 
			fileRpc.write(twoTab + "GetRpcServerManager()->RegisterFunc<GlobalRpc>(Msg::g_sz" + rpc.name + "_RpcTimeout , &GlobalRpc::" + rpc.name + "_RpcTimeout); \n") 
			fileRpc.write(twoTab + "GetRpcServerManager()->RegisterFunc<GlobalRpc>(Msg::g_sz" + rpc.name + "_RpcClient , &GlobalRpc::" + rpc.name + "_RpcClient); \n") 
		  
def GenerateRpcHandlers():
	#生成注册的头 
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():   
		GenerateRpcHandler(g_rpcMsgs.rpcs.rpcs , rpcServerName.serverName, rpcServerName.serverName) 

def GenerateRpcHandler(rpcs , serverName , namespace):
	#生成所有的rpc
	for index , rpc in rpcs.items():    
		
		if rpc.client == serverName: 
			outputPath = GetOutputPath(serverName)  
			outputPath += rpc.name
			outputPath += "_RpcClient.cpp"

			if IsPathExist(outputPath):
				os.remove(outputPath)

			fileRpc = open(outputPath , "a")   

			fileRpc.write("#include \"GlobalRpc.h\"\n\n")
			fileRpc.write("Msg::ObjectMsgCall * " + namespace + "::GlobalRpc::" + rpc.name + "_RpcClient(")
			strParams = GetParamsExcludeDefault(rpc.returns.params)
			fileRpc.write(strParams + ", std::vector<Msg::Object> vecTargets , Msg::Object objSrc \n{\n\n\n")

			strParams = GetParamsExcludeDefaultAndType(rpc.returns.params)
			fileRpc.write(oneTab + "RPCReturn(" + strParams + ");\n}\n\n")

			fileRpc.write("Msg::ObjectMsgCall * " + namespace + "::GlobalRpc::" + rpc.name + "_RpcTimeout(") 
			strParams = GetParamsExcludeDefault(rpc.call.params)
			fileRpc.write(strParams + ", std::vector<Msg::Object> vecTargets , Msg::Object objSrc) \n{\n\n\n")
			fileRpc.write(oneTab + "RPCReturnNULL;\n}\n\n")

			fileRpc.close()

		if rpc.proxy == serverName: 
			outputPath = GetOutputPath(serverName)  
			outputPath += rpc.name
			outputPath += "_RpcProxy.cpp"

			if IsPathExist(outputPath):
				os.remove(outputPath)

			fileRpc = open(outputPath , "a")   

			fileRpc.write("#include \"GlobalRpc.h\"\n\n")

			fileRpc.write("Msg::ObjectMsgCall * " + namespace + "::GlobalRpc::" + rpc.name + "_RpcServerProxy(")
			strParams = GetParamsExcludeDefault(rpc.call.params)
			fileRpc.write(strParams + ", std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )\n{\n\n\n ")
			
			strParamsNoType= GetParamsExcludeDefaultAndType(rpc.call.params)
			fileRpc.write(oneTab + "ProxySendMsg(\"\" , " + strParamsNoType + ");\n")
			fileRpc.write(oneTab + "RPCReturnNULL;\n}\n\n")

			fileRpc.write("Msg::ObjectMsgCall * " + namespace + "::GlobalRpc::" + rpc.name + "_RpcClientProxy(") 
			strParams = GetParamsExcludeDefault(rpc.returns.params)
			fileRpc.write(strParams + ", std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )\n{\n\n\n ")

			strParamsNoType= GetParamsExcludeDefaultAndType(rpc.returns.params)
			fileRpc.write(oneTab + "RPCReturn(" + strParamsNoType + ");\n}\n\n")

			strParams = GetParamsExcludeDefault(rpc.call.params)
			fileRpc.write("Msg::ObjectMsgCall * " + namespace + "::GlobalRpc::" + rpc.name + "_RpcTimeoutProxy(")
			fileRpc.write(strParams + ", std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )\n{\n\n\n ")
			fileRpc.write(oneTab + "RPCReturnNULL;\n}\n\n")

			fileRpc.close()

		if rpc.server == serverName: 
			outputPath = GetOutputPath(serverName)  
			outputPath += rpc.name
			outputPath += "_RpcServer.cpp"

			if IsPathExist(outputPath):
				os.remove(outputPath)

			fileRpc = open(outputPath , "a")   

			fileRpc.write("#include \"GlobalRpc.h\"\n") 
			fileRpc.write("#include \"" + rpc.include + "\"\n\n") 

			fileRpc.write("Msg::ObjectMsgCall * " + namespace + "::" + rpc.classes + "::" + rpc.name + "_RpcServer(")
			strParams = GetParamsExcludeDefault(rpc.call.params)
			fileRpc.write(strParams + ", std::vector<Msg::Object> vecTargets , Msg::Object objSrc )\n{\n\n\n")
			fileRpc.write(oneTab + "RPCReturnNULL;\n}\n\n")
 
			fileRpc.close() 
 
def GenerateRpcDatas():
	#生成所有的rpc
	for index , serverName in g_rpcMsgs.rpcServerNames.items():    
		outputPath = GetOutputPath(serverName.serverName)   
		outputPath += "RpcDatas.h" 
			
		fileRpc = open(outputPath , "a")

		for index , rpcData in g_rpcMsgs.rpcs.rpcDatas.items():  

			fileRpc.write("template<typename Object>\n")
			fileRpc.write("ObjectMsgCall<Object> * Rpc<Object>::" + rpcData.name + "_RpcServer(")
			strParams = GetParamsExcludeDefault(rpcData.params)
			fileRpc.write(strParams + ", std::vector<Object> vecTargets , Object objSrc ) \n{\n\n\n RPCReturnNULL;\n}\n\n")
			
		fileRpc.close()


################################流程无关函数处理#####################################
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
				os.makedirs(rpcServerName.outputPath)
				return rpcServerName.outputPath

	assert(0 , "no path is serverNamelist")

def IsPathExist(path):
	if os.path.exists(path):
		return True
	else:
		return True

def GetParams(params):
	strParams = ""
	nCount = 0
	for index , param in params.items(): 
		nCount += 1

		strParams = strParams + param.type
		strParams = strParams + " "
		strParams = strParams + param.name
		strParams = strParams + " = "

		if param.default == "":
			strParams = strParams + GetAndCheckDefaultParam(param.type)
		else:
			strParams = strParams + param.default
 
		if nCount != len(params):
			strParams = strParams + " , " 

	return strParams

def WriteDefaultParams(fileRpc):
	for index , defaultParam in g_rpcMsgs.defaultParams.items():
		fileRpc.write(oneTab + "static " + defaultParam.type + " g_rpcDefaultParam_" + defaultParam.type + " = " + defaultParam.value + ";\n")
	fileRpc.write("\n")

def GetRpcParamsIncludeDefault(call):
	strParams = ""

	nCount = 0
	for index , param in call.params.items():
		if nCount != 0:
			strParams += " , "
		
		nCount = nCount + 1
		strParams += GetDefaultParamValue(param.type)

	return strParams

def GetParamsExcludeDefault(params):
	strParams = ""
	nCount = 0
	for index , param in params.items(): 
		nCount += 1

		strParams = strParams + param.type
		strParams = strParams + " "
		strParams = strParams + param.name
		strParams = strParams + "/* = "

		if param.default == "":
			strParams = strParams + GetAndCheckDefaultParam(param.type)
		else:
			strParams = strParams + param.default

		strParams += "*/"
 
		if nCount != len(params):
			strParams = strParams + " , " 

	return strParams

def GetParamsExcludeDefaultAndType(params):
	strParams = ""
	nCount = 0
	for index , param in params.items(): 

		nCount += 1
		strParams = strParams + param.name

		if nCount != len(params):
			strParams = strParams + " , " 

	return strParams

def GetAndCheckDefaultParam(paramType):
	for index , defaultParam in g_rpcMsgs.defaultParams.items():
		if defaultParam.type == paramType: 
			return defaultParam.value

	assert(0 , "no this value in defaultParamsList")

def DeleteServerNameFiles():
	for index , serverName in g_rpcMsgs.rpcServerNames.items():
		if os.path.exists(serverName.outputPath + "RpcDefines.h"): 
			os.remove(serverName.outputPath + "RpcDefines.h")
		if os.path.exists(serverName.outputPath + "GlobalRpc.h"): 
			os.remove(serverName.outputPath + "GlobalRpc.h") 
		if os.path.exists(serverName.outputPath + "RpcRegister.cpp"): 
			os.remove(serverName.outputPath + "RpcRegister.cpp") 

def CreateServerNamePath(): 
	for index , serverName in g_rpcMsgs.rpcServerNames.items():
		if False == os.path.exists(serverName.outputPath):
			os.makedirs(serverName.outputPath)

def GetDefaultParamValue(paramType):
	for index , param in g_rpcMsgs.defaultParamsList.items():
		if paramType == index:
			return param 
	assert(0 ,  "no this defaultParam value in defaultParamsList")

################################main函数处理#####################################
if __name__ == '__main__':
	main()

