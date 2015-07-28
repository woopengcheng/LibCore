#-*- coding: utf-8 -*-
import sys , getopt
import os , re , string
import time , datetime
import binascii 
import collections  
import xml.dom.minidom
import time,datetime
import socket  

from xml.dom import minidom , Node 

from xml.etree.ElementTree import ElementTree
from xml.etree.ElementTree import Element
from xml.etree.ElementTree import SubElement as SE
#sys.reload()
#sys.setdefaultencoding("utf-8") 
#sys.setdefaultencoding("cp936") 
 
g_rpcXmlPath = "GameDB.xml"

#rpc的类型
g_targetTypeClient = 1
g_targetTypeProxy  = 2
g_targetTypeServer = 3
################################类定义#####################################
class ParentPoint:
	def __init__(self, parentPoint): 
		#self.parentPoint = parentPoint  
		pass
 
class RpcMsgs(ParentPoint):
	def __init__(self): 
		super(RpcMsgs , self).__init__(self)
		self.defaultParams = collections.OrderedDict()
		self.defaultParamsList = collections.OrderedDict()
		self.rpcs = Rpcs(self)
		self.rpcServerNames = collections.OrderedDict()

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
		self.rpcs = collections.OrderedDict()
		self.rpcDatas = collections.OrderedDict() 

class Rpc(ParentPoint):
	def __init__(self , parentPoint):
		super(Rpc , self).__init__(parentPoint) 
		self.call = Call(self)  #这里calls为dic保存所有的call
		self.returns = Return(self)  #这里returns为dic保存所有的return
		self.name = None
		self.syncType = 0
		self.timeout = 10
		self.targets = collections.OrderedDict()
		# self.client = None
		# self.server = None
		# self.proxy = None
		# self.serverClass = None
		# self.serverInclude = None
		# self.proxyInclude = None
		# self.proxyClass = None
		# self.clientInclude = None
		# self.clientClass = None
		
class TargetAttr(ParentPoint):
	def __init__(self , parentPoint):
		super(TargetAttr , self).__init__(parentPoint)  
		self.targetType = None 
		self.classes = None
		self.include = None 
		self.name = None
		
class RpcData(ParentPoint):
	def __init__(self , parentPoint):
		super(RpcData , self).__init__(parentPoint)
		self.params = collections.OrderedDict()   #这里存放所有的params.用dic结构
		self.name = None

class Call(ParentPoint):
	def __init__(self , parentPoint):
		super(Call , self).__init__(parentPoint) 
		self.params = collections.OrderedDict()  #这里的参数同上

class Return(ParentPoint):
	def __init__(self , parentPoint):
		super(Return , self).__init__(parentPoint)
		self.name = None
		self.params = collections.OrderedDict() #这里的参数同上

class Param(ParentPoint):
	def __init__(self , parentPoint):
		super(Param , self).__init__(parentPoint)
		self.name = None
		self.type = None
		self.default = None
		self.refer = None
		self.unrefer = None

################################函数解析XML内容#####################################

g_rpcMsgs=RpcMsgs() 
g_rpcRecords = collections.OrderedDict()   #记录所以得RPC

def start(): 
	ParseRpcs() 
	LogOutInfo("ParseRpcs finished.\n") 
	
	SortRpcs(g_rpcMsgs)
	
	GenerateRpc()  
	LogOutInfo("Generate Rpc finished.\n") 
	
noneDir = collections.OrderedDict()
def SortRpcs(sortObj):
	for name , value in vars(sortObj).items():   
		if isinstance(value , dict): 
			i = 0
			for key , val in value.items(): 
				i = i + 1
				if IsSortNext(val): 
					SortRpcs(val)
				else:
					sorted(value.items() , key=lambda e:e[i] , reverse=True)  
					break 

		elif IsSortNext(value): 
			SortRpcs(value)

def IsSortNext(value): 
	if isinstance(value , RpcServerName) or \
		isinstance(value , RpcMsgs) or \
		isinstance(value , DefaultParam) or \
		isinstance(value , Rpcs) or \
		isinstance(value , Rpc) or \
		isinstance(value , RpcData) or \
		isinstance(value , Call) or \
		isinstance(value , Return) or \
		isinstance(value , Param) or \
		isinstance(value , TargetAttr) or \
		isinstance(value , Rpc)   : 

		return True

	return False 

def ParseRpcs():  
#使用ElementTree读取节点
	rpcDoc = ElementTree(None , g_rpcXmlPath)  
	xmlRpcMsgs = rpcDoc.getroot() 
	handleRpcMsgs(xmlRpcMsgs) 

def handleRpcMsgs(xmlRpcMsgs):
	for xmlData in iter(xmlRpcMsgs.getchildren()): 
		if xmlData.tag.lower() == "DefaultParams".lower():
			handleDefaultParams(g_rpcMsgs.defaultParams , g_rpcMsgs.defaultParamsList , xmlData)
		if xmlData.tag.lower() == "Rpcs".lower():
			handleRpcs(g_rpcMsgs.rpcs , xmlData)
		if xmlData.tag.lower() == "RpcServerName".lower():
			handleRpcServerName(g_rpcMsgs.rpcServerNames , xmlData)

def handleDefaultParams(defaultParams , defaultParamsList, xmlDefaultParams):
	for attr in iter(xmlDefaultParams.attrib):
		defaultParam = DefaultParam(defaultParams)
		defaultParam.type = attr
		defaultParam.value = xmlDefaultParams.attrib[attr]
		defaultParams[attr] = defaultParam
		defaultParamsList[attr] = "g_rpcDefaultParam_" + attr

def handleRpcServerName(rpcServerNames , xmlRpcServerName):
	rpcServerName = RpcServerName(g_rpcMsgs)

	for attr in iter(xmlRpcServerName.attrib):
		if attr.lower() == "serverName".lower():
			rpcServerName.serverName = xmlRpcServerName.attrib[attr]
		if attr.lower() == "outputPath".lower():
			rpcServerName.outputPath = xmlRpcServerName.attrib[attr]
		if attr.lower() == "include".lower():
			rpcServerName.include = xmlRpcServerName.attrib[attr]
		if attr.lower() == "namespace".lower():
			rpcServerName.namespace = xmlRpcServerName.attrib[attr]
		if attr.lower() == "rpcInterface".lower():
			rpcServerName.rpcInterface = xmlRpcServerName.attrib[attr]

	g_rpcRecords[rpcServerName.namespace] = collections.OrderedDict()
	g_rpcRecords[rpcServerName.namespace]["GlobalRpc"] = collections.OrderedDict()
	rpcServerNames[rpcServerName.serverName] = rpcServerName

def handleRpcs(rpcs , xmlRpcs):
	for xmlData in iter(xmlRpcs.getchildren()): 
		if xmlData.tag.lower() == "RpcData".lower():
			handleRpcData(rpcs.rpcDatas , xmlData)
		if xmlData.tag.lower() == "Rpc".lower():
			handleRpc(rpcs.rpcs , xmlData)

def handleRpcData(rpcDatas , xmlrpcData):
	rpcData = RpcData(rpcDatas)
	for attr in iter(xmlrpcData.attrib):
		if attr.lower() == "name".lower():
			rpcData.name = xmlrpcData.attrib[attr]

	rpcDatas[attr] = rpcData
	
	for xmlData in iter(xmlrpcData.getchildren()): 
		if xmlData.tag.lower() == "Param".lower():
			handleParams(rpcData.params , xmlData)

def handleRpc(rpcs , xmlRpc): 
	rpc = Rpc(rpcs)

	targetAttrClient = TargetAttr(rpc)
	targetAttrProxy = TargetAttr(rpc)
	targetAttrServer = TargetAttr(rpc)
	for attr in iter(xmlRpc.attrib):
		if attr.lower() == "name".lower():
			rpc.name = xmlRpc.attrib[attr]
		if attr.lower() == "syncType".lower():
			rpc.syncType = xmlRpc.attrib[attr]
		if attr.lower() == "timeout".lower():
			rpc.timeout = xmlRpc.attrib[attr]
		if attr.lower() == "serverInclude".lower():
			targetAttrServer.include = xmlRpc.attrib[attr]
		if attr.lower() == "serverClass".lower():
			targetAttrServer.classes = xmlRpc.attrib[attr]
		if attr.lower() == "server".lower():
			targetAttrServer.name = xmlRpc.attrib[attr]
		if attr.lower() == "proxy".lower():
			targetAttrProxy.name = xmlRpc.attrib[attr]
		if attr.lower() == "proxyInclude".lower():
			targetAttrProxy.include = xmlRpc.attrib[attr]
		if attr.lower() == "proxyClass".lower():
			targetAttrProxy.classes = xmlRpc.attrib[attr]
		if attr.lower() == "clientInclude".lower():
			targetAttrClient.include = xmlRpc.attrib[attr]
		if attr.lower() == "clientClass".lower():
			targetAttrClient.classes = xmlRpc.attrib[attr]
		if attr.lower() == "client".lower():
			targetAttrClient.name = xmlRpc.attrib[attr] 
 
	if targetAttrClient.name != "" and targetAttrClient.name != None:
		if targetAttrClient.classes == None:
			targetAttrClient.classes = "GlobalRpc"
		targetAttrServer.targetType = g_targetTypeClient
		rpc.targets[targetAttrClient.name + targetAttrClient.classes + str(targetAttrClient.targetType) ] = targetAttrClient
		AddToGlobalTargets(targetAttrClient , rpc)		
		
	if targetAttrProxy.name != "" and targetAttrProxy.name != None:
		if targetAttrProxy.classes == None:
			targetAttrProxy.classes = "GlobalRpc"
		targetAttrServer.targetType = g_targetTypeProxy
		rpc.targets[targetAttrProxy.name + targetAttrProxy.classes + str(targetAttrProxy.targetType) ] = targetAttrProxy
		AddToGlobalTargets(targetAttrProxy , rpc)	
			
	if targetAttrServer.name != "" and targetAttrServer.name != None:
		if targetAttrServer.classes == None:
			targetAttrServer.classes = "GlobalRpc"
		targetAttrServer.targetType = g_targetTypeServer
		rpc.targets[targetAttrServer.name + targetAttrServer.classes + str(targetAttrServer.targetType) ] = targetAttrServer
		AddToGlobalTargets(targetAttrServer , rpc)	
			
	for xmlData in iter(xmlRpc.getchildren()): 
		if xmlData.tag.lower() == "Call".lower():
			handleCall(rpc.call , xmlData)
		if xmlData.tag.lower() == "Return".lower():
			handleReturn(rpc.returns , xmlData)
		if xmlData.tag.lower() == "Targets".lower():
			handleTargets(rpc.targets , xmlData , rpc)
			
	rpcs[rpc.name] = rpc

#这个肯定是唯一的
def handleTargets(targets , xmlTarget, rpc): 			
	for xmlData in iter(xmlTarget.getchildren()): 
		if xmlData.tag.lower() == "Client".lower():
			handleTarget(targets , xmlData , rpc, g_targetTypeClient)
		if xmlData.tag.lower() == "Proxy".lower():
			handleTarget(targets , xmlData , rpc, g_targetTypeProxy)
		if xmlData.tag.lower() == "Server".lower():
			handleTarget(targets , xmlData, rpc, g_targetTypeServer)
				
def handleTarget(targets , xmData , rpc , targetType): 
	targetAttr = TargetAttr(rpc) 
	targetAttr.targetType = targetType
	
	for attr in iter(xmData.attrib):
		if attr.lower() == "name".lower():
			targetAttr.name = xmData.attrib[attr]
		if attr.lower() == "include".lower():
			targetAttr.include = xmData.attrib[attr]
		if attr.lower() == "class".lower():
			targetAttr.classes = xmData.attrib[attr]
			
	if targetAttr.classes == "" or targetAttr.classes == None:
		targetAttr.classes = "GlobalRpc" 
	
	#标示一个唯一的target.因为导致一个target不一样的有可能是类型,class,以及
	targets[targetAttr.name + targetAttr.classes + str(targetType) ] = targetAttr
	AddToGlobalTargets(targetAttr , rpc)
	
def AddToGlobalTargets(targetAttr , rpc): 
	strNamespace = GetServerNamespaceByName(targetAttr.name)
	 
	if targetAttr.classes not in g_rpcRecords[strNamespace]:
		g_rpcRecords[strNamespace][targetAttr.classes] = collections.OrderedDict()
	
	if rpc.name not in g_rpcRecords[strNamespace][targetAttr.classes] :
		g_rpcRecords[strNamespace][targetAttr.classes][rpc.name] = rpc

def handleCall(call , xmlCall): 
	for xmlData in iter(xmlCall.getchildren()): 
		if xmlData.tag.lower() == "Param".lower():
			handleParams(call.params , xmlData)

def handleReturn(_return , xmlReturn): 
	for attr in iter(xmlReturn.attrib):
		if attr.lower() == "name".lower():
			_return.name = xmlReturn.attrib[attr]

	for xmlData in iter(xmlReturn.getchildren()):
		if xmlData.tag.lower() == "Param".lower():
			handleParams(_return.params , xmlData)

def handleParams(params , xmlParam):
	param = Param(params)
	for attr in iter(xmlParam.attrib):
		if attr.lower() == "name".lower():
			param.name = xmlParam.attrib[attr] 
		if attr.lower() == "type".lower():  
			param.type = GetDefaultParamsType(xmlParam.attrib[attr]) #这里获取最相近的类型. 
		if attr.lower() == "default".lower():  
			param.default = xmlParam.attrib[attr] 
		if attr.lower() == "refer".lower():  
			param.refer = "&"
		if attr.lower() == "unrefer".lower():  
			param.unrefer = "!&"

	if not IsInDefaultParams(param):
		LogOutDebug("param type error , not in the defaultParams" , param.type , param.name)
		exit()
		
	if IsNotInTheSameParam(param, params):
		LogOutDebug("params has one same param" , param.type , param.name)
		exit()
	
	if param.type.lower()  == "SINT8".lower() or param.type.lower()  == "UINT8".lower() or\
		param.type.lower()  == "INT16".lower() or param.type.lower()  == "UINT16".lower() or\
		param.type.lower()  == "INT32".lower() or param.type.lower()  == "UINT32".lower() or\
		param.type.lower()  == "INT64".lower() or param.type.lower()  == "INT64".lower() or\
		param.type.lower()  == "double".lower() or param.type.lower()  == "float".lower() or \
		param.unrefer == "!&".lower(): 
		
		param.refer = None
	else:
		param.refer = "&"
		
	params[param.name] = param
	
################################生成对应文件#####################################

oneTab = "\t"
twoTab = oneTab + "\t"
threeTab = twoTab + "\t"
fourTab = threeTab + "\t"
fiveTab = fourTab + "\t"

def GenerateRpc():
	DeleteServerNameFiles() 
	LogOutInfo("deleted all files but rpc handler file finished.\n")
	
	CreateServerNamePath() 
	LogOutInfo("created every server name path finished.\n")

	GenerateMsgNameDefine()	
	LogOutInfo("generate MsgNameDefine.h file finished.\n")
	
	GenerateGlableRpc()
	LogOutInfo("generate GlobalRpc.h file finished.\n")
	
	GenerateRpcRegister()
	LogOutInfo("generate RpcRegister.cpp file finished.\n")
	
	GenerateRpcHandlers()
	LogOutInfo("generate RpcHandler.cpp file finished.\n")
	
	GenerateRpcDatas()
	LogOutInfo("generate RpcData.h file finished.\n")
	
	GenerateRpcCallFuncs()
	LogOutInfo("generate RpcCallFuncs.h file finished.\n") 
	
	GenerateRPCDefines()
	LogOutInfo("generate RpcDefine.h file finished.\n") 

def GenerateMsgNameDefine(): 
	sameNamespace = collections.OrderedDict()
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():  
		outputPath = GetOutputPath(rpcServerName.serverName)  
		outputPath = outputPath + "MsgNameDefine.h"     
		
		fileRpc = open(outputPath , "a")
		if rpcServerName.namespace not in sameNamespace :
			GenerateRPCParamDefineHeader(fileRpc , rpcServerName.namespace)
			sameNamespace[rpcServerName.namespace] = 1
		
			sameRecord = collections.OrderedDict()
			for index , rpc in g_rpcMsgs.rpcs.rpcs.items():   
				if rpc.name not in sameRecord :
					GenerateRPCParamDefine(rpc , fileRpc) 
					sameRecord[rpc.name] = 1
			
			fileRpc.close()	

	sameNamespace = collections.OrderedDict() 
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():  
		outputPath = GetOutputPath(rpcServerName.serverName)  
		outputPath = outputPath + "MsgNameDefine.h"     
		
		if rpcServerName.namespace not in sameNamespace : 
			fileRpc = open(outputPath , "a")
			fileRpc.write("}\n\n#endif\n\n")
			fileRpc.close()	
			sameNamespace[rpcServerName.namespace] = 1

def GenerateRPCParamDefineHeader(fileRpc , namespace):  
	WriteFileDescription(fileRpc , "MsgNameDefine.h" , "用于定义消息的全局唯一名字")
	fileRpc.write("#ifndef __msg_" + namespace + "_msg_name_define_h__\n")
	fileRpc.write("#define __msg_" + namespace + "_msg_name_define_h__\n") 
	fileRpc.write("#include \"MsgLib/inc/MsgCommon.h\" \n\n") 
	fileRpc.write("namespace Msg\n") 
	fileRpc.write("{\n") 
	

def GenerateRPCParamDefine(rpc , fileRpc): 
	fileRpc.write(oneTab + "//5 " + rpc.name + " declare here\n")
	fileRpc.write(oneTab + "RPC_DEFINE(" + rpc.name + ");\n\n")
	
def GenerateRPCDefines(): 

	rpcRecords = collections.OrderedDict()		
	sameNamespace = collections.OrderedDict()   
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():  
		outputPath = GetOutputPath(rpcServerName.serverName)  
		outputPath = outputPath + "RPCDefines.h"    
		 
		fileRpc = open(outputPath , "a")
		if rpcServerName.namespace not in sameNamespace :
			GenerateRPCDefinesHeader(fileRpc , rpcServerName.namespace)			
			sameNamespace[rpcServerName.namespace] = 1  
			
			for recordIndex , rpcClasses in g_rpcRecords[rpcServerName.namespace].items():
				GenerateRPCDefine(recordIndex , rpcClasses , fileRpc , rpcServerName.namespace)						
	
		fileRpc.write("\n\n")
		fileRpc.close()	 
			
	sameNamespace = collections.OrderedDict() 
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

def GenerateRPCDefine(className , rpcs , fileRpc , serverName): 
	fileRpc.write("\n#define  RPC_DEFINE_" + className + " public:\\\n")
#	for recordIndex , rpcClasses in g_rpcRecords.items():
	for rpcIndex , rpc in rpcs.items():
		strParams = GetParamsIncludeDefaultParam(rpc.call.params)  
		strReturnParams = GetParamsIncludeDefaultParam(rpc.returns.params) 
		for targetIndex , target in rpc.targets.items():
			if target.targetType == g_targetTypeClient and target.classes == className:
				fileRpc.write(oneTab + "Msg::ObjectMsgCall * " + rpc.name + "_RpcClient(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) " + strReturnParams + ");\\\n") 
				fileRpc.write(oneTab + "Msg::ObjectMsgCall * " + rpc.name + "_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) " + strParams + ");\\\n")
				
			if target.targetType == g_targetTypeProxy and target.classes == className:
				fileRpc.write(oneTab + "Msg::ObjectMsgCall * " + rpc.name + "_RpcServerProxy(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) " + strParams + ");\\\n")
				fileRpc.write(oneTab + "Msg::ObjectMsgCall * " + rpc.name + "_RpcTimeoutProxy(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) " + strParams + ");\\\n")
				fileRpc.write(oneTab + "Msg::ObjectMsgCall * " + rpc.name + "_RpcClientProxy(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) " + strReturnParams + ");\\\n") 

			if target.targetType == g_targetTypeServer and target.classes == className:
				fileRpc.write(oneTab + "Msg::ObjectMsgCall * " + rpc.name + "_RpcServer(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID)" + strParams + ");\\\n")				
								
	GenerateObjectHaveCurFunc(fileRpc , className , rpcs)
		
def GenerateObjectHaveCurFunc(fileRpc , className , rpcs):	
	fileRpc.write("public:\\\n")
	fileRpc.write(oneTab + "static CollectionObjectFuncsT s_setFuncs;\\\n")
	fileRpc.write(oneTab + "static void InitObjectFuncs()\\\n")
	fileRpc.write(oneTab + "{\\\n")
	for index , rpc in rpcs.items(): 
		fileRpc.write(twoTab + className + "::" + "s_setFuncs.insert(\"" + rpc.name + "\");\\\n")
	fileRpc.write(oneTab + "}\\\n")
	fileRpc.write(oneTab + "virtual BOOL IsHasFunc(const std::string & strFunc)\\\n")
	fileRpc.write(oneTab + "{\\\n") 
	fileRpc.write(twoTab + "CollectionObjectFuncsT::iterator iter = " + className + "::s_setFuncs.find(strFunc);\\\n")
	fileRpc.write(twoTab + "if (iter != " + className + "::s_setFuncs.end())\\\n")
	fileRpc.write(twoTab + "{\\\n") 
	fileRpc.write(threeTab + "return TRUE;\\\n")
	fileRpc.write(twoTab + "}\\\n")
	fileRpc.write(oneTab + "return FALSE;\\\n") 
	fileRpc.write(oneTab + "}\\\n")		

	
def GenerateGlableRpc():
	sameNamespace = collections.OrderedDict()
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():  
		outputPath = GetOutputPath(rpcServerName.namespace)  
		outputPath = outputPath + "GlobalRpc.h"   
					
		fileRpc = open(outputPath , "a")
		if rpcServerName.namespace not in sameNamespace :
			GenerateGlableRpcHeaderNamespace(fileRpc , rpcServerName.namespace)
			sameNamespace[rpcServerName.namespace] = 1
							
		fileRpc.close()	

	sameNamespace = collections.OrderedDict()
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
	WriteFileDescription(fileRpc , "GlableRpc.h" , "静态函数,无对象时通过这个类处理.") 
	fileRpc.write("#ifndef __" + namespace + "_global_rpc_h__\n") 
	fileRpc.write("#define __" + namespace + "_global_rpc_h__\n") 
	fileRpc.write("#include \"Common/Chunk.h\" \n") 
	fileRpc.write("#include \"MsgLib/inc/Object.h\" \n") 
	fileRpc.write("#include \"MsgLib/inc/RPCMsgCall.h\" \n") 
	fileRpc.write("#include \"MsgLib/inc/RpcServerManager.h\" \n") 
	fileRpc.write("#include \"MsgLib/inc/IRpcMsgCallableObject.h\" \n") 
	fileRpc.write("#include \"RpcDatas.h\" \n") 
	fileRpc.write("#include \"RpcDefines.h\" \n") 
	fileRpc.write("\n") 
	fileRpc.write("namespace Msg" + "\n{\n") 
	
	fileRpc.write(oneTab + "class GlobalRpc : public Msg::IRpcMsgCallableObject\n") 
	fileRpc.write(oneTab + "{\n") 
	fileRpc.write(twoTab + "RPC_DEFINE_GlobalRpc;\n") 
	fileRpc.write(oneTab + "public:\n") 
	fileRpc.write(twoTab + "GlobalRpc(Msg::Object nID , Msg::RpcManager * pRpcManager)\n") 
	fileRpc.write(threeTab + ": Msg::IRpcMsgCallableObject(nID , pRpcManager)\n") 
	fileRpc.write(twoTab + "{\n")  
	fileRpc.write(threeTab +"GlobalRpc::InitObjectFuncs();\n")  
	fileRpc.write(twoTab +"}\n")   
	fileRpc.write(oneTab +"public:\n")  
			 
#生成GlableRpc尾部部分.
def GenerateGlableRpcLastNamespace(fileRpc , namespace):  
	fileRpc.write(oneTab + "};\n\n")
	fileRpc.write("}\n\n")
	fileRpc.write("#endif\n\n")
	
def GenerateRpcRegister():   
	#生成注册的头 
	sameNamespace = collections.OrderedDict()   
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
		fileRpc.write(twoTab + "static Msg::GlobalRpc g_pGlobalRpc( Msg::DEFAULT_RPC_CALLABLE_ID , m_pRpcServerManager); \n\n") 

		fileRpc.write(twoTab + "Msg::Parameters objDeliverParams , objReturnParams;\n")
		
		rpcRecords = collections.OrderedDict()
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
			
			for index , target in rpc.targets.items():  
				if target.classes not in rpcRecords and target.classes != "GlobalRpc" and rpcServerName.serverName == target.name:
					rpcRecords[target.classes] = 1		

		GenerateInitStaticFunc(fileRpc , rpcServerName.namespace , rpcRecords)
				
		fileRpc.write(oneTab + "}\n\n")
		
		fileRpc.close() 
		
	sameNamespace = collections.OrderedDict()
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():  
		outputPath = GetOutputPath(rpcServerName.namespace)  
		outputPath = outputPath + "RpcRegister.cpp"    
		
		if rpcServerName.namespace not in sameNamespace :
			fileRpc = open(outputPath , "a")
			
			GenerateDefineStaticFunc(fileRpc , rpcServerName.namespace)
				
			fileRpc.write("}//" + rpcServerName.namespace + "\n\n") 
			fileRpc.write("CollectionObjectFuncsT Msg::GlobalRpc::s_setFuncs;\n")
			
			sameNamespace[rpcServerName.namespace] = 1 
			fileRpc.close()	 

def GenerateInitStaticFunc(fileRpc , namespace , rpcRecords):	  
	for index , rpcs in rpcRecords.items(): 
		fileRpc.write(twoTab + namespace + "::"+ index + "::" +"InitObjectFuncs();\n")
		
def GenerateDefineStaticFunc(fileRpc , namespace):	  
	for index , rpcs in g_rpcRecords[namespace].items(): 
		if index != "GlobalRpc":
			fileRpc.write(oneTab + "CollectionObjectFuncsT " + namespace + "::"+ index + "::" +"s_setFuncs;\n")
	
def GenerateRpcRegisterHeader(fileRpc , rpcNamespace) :
	WriteFileDescription(fileRpc , "RpcRegister.cpp" , "注册每个函数.以及检测网络传递的消息是否是正确的参数.") 
	fileRpc.write("#include \"MsgLib/inc/RpcServerManager.h\"\n")
	fileRpc.write("#include \"MsgLib/inc/RpcCheckParams.h\"\n") 
	fileRpc.write("#include \"Common/Chunk.h\"\n") 
	fileRpc.write("#include \"GlobalRpc.h\"\n")  
	fileRpc.write("#include \"MsgNameDefine.h\"\n")  
#	fileRpc.write("#include \"" + rpcServerName.include + "\"\n")
	GenerateRpcRegisterHeaderInclude(fileRpc , rpcNamespace)

	sameNamespace = collections.OrderedDict()
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():
		if rpcServerName.namespace == rpcNamespace : 
			sameNamespace[rpcServerName.serverName] = 1 
			
	for index , foo in sameNamespace.items():   
		GenerateRpcRegisterServerHeader(g_rpcMsgs.rpcs.rpcs , fileRpc , index)
 
	fileRpc.write("\n") 

	fileRpc.write("namespace " + rpcNamespace + "\n{\n")
	fileRpc.write(oneTab + "//5 defaultParams define here.\n")
	WriteDefaultParams(fileRpc)
	
def GenerateRpcRegisterHeaderInclude(fileRpc , rpcNamespace): 
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():  
		if rpcNamespace == rpcServerName.namespace :
			fileRpc.write("#include \"" + rpcServerName.include + "\"\n")
	
def GenerateRpcRegisterServerHeader(rpcs , fileRpc , serverName):
	
	sameRecord = collections.OrderedDict()
	#生成所有的rpc
	for index , rpc in rpcs.items():  
		for index , target in rpc.targets.items():     
			if target.name == serverName and target.include not in sameRecord: 
				if target.classes != "GlobalRpc":
					fileRpc.write("#include \"" + target.include + "\"\n") 
					sameRecord[target.include] = 1
 
def GenerateRpcRegisterFuncs(rpc , fileRpc , serverName):

	#生成所有的rpc  
	for index , target in rpc.targets.items():  

		className = ""	 
		if target.classes != "GlobalRpc":
			className =  target.classes
		else:			
			className = "Msg::GlobalRpc"
				
		if target.targetType == g_targetTypeClient and serverName == target.name:
		
			fileRpc.write(threeTab + "\n") 
			fileRpc.write(threeTab + "m_pRpcServerManager->RegisterFunc<"+ className + " >(Msg::g_sz" + rpc.name + "_RpcClient , &" + className + "::" + rpc.name + "_RpcClient); \n") 
			fileRpc.write(threeTab + "m_pRpcServerManager->RegisterFunc<"+ className + " >(Msg::g_sz" + rpc.name + "_RpcTimeout ,&" + className + "::" + rpc.name + "_RpcTimeout); \n") 
				
		elif target.targetType == g_targetTypeProxy and serverName == target.name:
		
			fileRpc.write(threeTab + "\n")
			fileRpc.write(threeTab + "m_pRpcServerManager->RegisterFunc<"+ className + " >(Msg::g_sz" + rpc.name + "_RpcServerProxy , &" + className + "::" + rpc.name + "_RpcServerProxy); \n") 
			fileRpc.write(threeTab + "m_pRpcServerManager->RegisterFunc<"+ className + " >(Msg::g_sz" + rpc.name + "_RpcClientProxy , &" + className + "::" + rpc.name + "_RpcClientProxy); \n") 
			fileRpc.write(threeTab + "m_pRpcServerManager->RegisterFunc<"+ className + " >(Msg::g_sz" + rpc.name + "_RpcTimeoutProxy ,&" + className + "::" + rpc.name + "_RpcTimeoutProxy); \n") 
				
		elif target.targetType == g_targetTypeServer and serverName == target.name:
			fileRpc.write(threeTab + "m_pRpcServerManager->RegisterFunc<"+ className + " >(Msg::g_sz" + rpc.name + "_RpcServer , &" + className + "::" + rpc.name + "_RpcServer); \n") 
	
def GenerateRpcHandlers():
	#生成注册的头 
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():   
		GenerateRpcHandler(g_rpcMsgs.rpcs.rpcs , rpcServerName.serverName, rpcServerName.namespace) 

def GenerateRpcHandler(rpcs , serverName , old_namespace):
	namespace = old_namespace

	#生成所有的rpc
	for index , rpc in rpcs.items():			
		for index , target in rpc.targets.items(): 
			if serverName != target.name:
				continue 
			
			className = ""
			if target.classes != "GlobalRpc":
				className = target.classes
				namespace = old_namespace
			else:
				namespace = "Msg"
				className = "GlobalRpc"
				
			outputPath = GetOutputPath(serverName)  
			outputPath = outputPath + target.classes + "_" + rpc.name
			if target.targetType == g_targetTypeClient and serverName == target.name:
				outputPath = outputPath + "_Client.cpp"
			elif target.targetType == g_targetTypeProxy and serverName == target.name:
				outputPath = outputPath + "_Proxy.cpp" 
			elif target.targetType == g_targetTypeServer and serverName == target.name:
				outputPath = outputPath + "_Server.cpp"
			else:
				continue
			
			if IsPathExist(outputPath):
#				os.remove(outputPath)
				continue
				
			fileRpc = open(outputPath , "a")   
			fileRpc.write("#include \"GlobalRpc.h\"\n")
			if className != "GlobalRpc":
				fileRpc.write("#include \"" + target.include + "\"\n\n") 
			fileRpc.write("\n\n") 
 				
			if target.targetType == g_targetTypeClient and serverName == target.name:			
			
				fileRpc.write("Msg::ObjectMsgCall * " + namespace + "::" + className + "::" +  rpc.name + "_RpcClient(Net::ISession * pSession, Msg::Object objSrc ")
				strParams = GetParamsExcludeDefaultParam(rpc.returns.params) 
				fileRpc.write(strParams + ")\n{\n\n\n")

				fileRpc.write(oneTab + "std::cout << \"" + rpc.name + "_RpcClient\" << std::endl;\n")
				fileRpc.write(oneTab + "RPCReturnNULL;\n}\n\n")

				fileRpc.write("Msg::ObjectMsgCall * " + namespace + "::" + className + "::" + rpc.name + "_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc ") 
				strParams = GetParamsExcludeDefaultParam(rpc.call.params) 
				fileRpc.write(strParams + ")\n{\n\n\n")
					
				fileRpc.write(oneTab + "std::cout << \"" + rpc.name + "_RpcTimeout\" << std::endl;\n")
				fileRpc.write(oneTab + "RPCReturnNULL;\n}\n\n")

				fileRpc.close()
				
			elif target.targetType == g_targetTypeProxy and serverName == target.name:
				fileRpc.write("Msg::ObjectMsgCall * " + namespace + "::" + className + "::" + rpc.name + "_RpcServerProxy(Net::ISession * pSession , Msg::Object objSrc ")
				strParams = GetParamsExcludeDefaultParam(rpc.call.params) 
				fileRpc.write(strParams + ")\n{\n")
				
				WriteDefineParams(fileRpc , rpc.returns.params)
				fileRpc.write("\n\n");			
				
				strParamsNoType = GetParamsExcludeDefaultAndType(rpc.call.params)
				if len(rpc.call.params) == 0:
					fileRpc.write(oneTab + "if(ERR_FAILURE == ProxySendMsg(\"tcp://127.0.0.1:8002\" , 0))\n")
				else:
					fileRpc.write(oneTab + "if(ERR_FAILURE == ProxySendMsg(\"tcp://127.0.0.1:8002\" , 0 , " + strParamsNoType + "))\n")
					
				fileRpc.write(oneTab + "{\n")
				strParamsNoType= GetParamsExcludeDefaultAndType(rpc.returns.params)
				strReturnCount = len(rpc.returns.params)
				fileRpc.write(twoTab + "RPCReturn" + str(strReturnCount) + "(" + strParamsNoType + ");\n") 
				fileRpc.write(oneTab + "}\n\n\n")
				
				strParamsNoType= GetParamsExcludeDefaultAndType(rpc.returns.params)
				strReturnCount = len(rpc.returns.params)
				fileRpc.write(oneTab + "std::cout << \"" + rpc.name + "_RpcServerProxy\" << std::endl;\n")
	#			fileRpc.write(oneTab + "//RPCReturn" + str(strReturnCount) + "(" + strParamsNoType + ");\n") 
				fileRpc.write(oneTab + "RPCReturnNULL;\n}\n\n")

				fileRpc.write("Msg::ObjectMsgCall * " + namespace + "::" + className + "::" + rpc.name + "_RpcClientProxy(Net::ISession * pSession , Msg::Object objSrc  ,") 
				strParams = GetParamsExcludeDefault(rpc.returns.params)
				if len(strParams) != 0:
					fileRpc.write(strParams + ")\n{\n\n\n")
				else:
					fileRpc.write(")\n{\n\n\n")	  
	#			WriteDefineParams(fileRpc , rpc.returns.params)
				fileRpc.write("\n\n")
				
				fileRpc.write(oneTab + "std::cout << \"" + rpc.name + "_RpcClientProxy\" << std::endl;\n")

				strParamsNoType= GetParamsExcludeDefaultAndType(rpc.returns.params)
				strReturnCount = len(rpc.returns.params)
				fileRpc.write(oneTab + "RPCReturn" + str(strReturnCount) + "(" + strParamsNoType + ");\n}\n\n")

				strParams = GetParamsExcludeDefault(rpc.call.params)
				fileRpc.write("Msg::ObjectMsgCall * " + namespace + "::" + className + "::" + rpc.name + "_RpcTimeoutProxy(Net::ISession * pSession , Msg::Object objSrc,")
				fileRpc.write(strParams + " )\n{\n\n\n ")
				fileRpc.write(oneTab + "std::cout << \"" + rpc.name + "_RpcTimeoutProxy\" << std::endl;\n")
				fileRpc.write(oneTab + "RPCReturnNULL;\n}\n\n")

				fileRpc.close()
			elif target.targetType == g_targetTypeServer and serverName == target.name:
			
				fileRpc.write("Msg::ObjectMsgCall * " + namespace + "::" + className + "::" + rpc.name + "_RpcServer(Net::ISession * pSession, Msg::Object objSrc ")
				strParams = GetParamsExcludeDefaultParam(rpc.call.params)
				fileRpc.write(strParams + ")\n{\n")
					
				WriteDefineParams(fileRpc , rpc.returns.params)
				fileRpc.write("\n\n")
				
				strParamsNoType= GetParamsExcludeDefaultAndType(rpc.returns.params)
				strReturnCount = len(rpc.returns.params)
				fileRpc.write(oneTab + "std::cout << \"" + rpc.name + "_RpcServer \"<< std::endl;\n")
				fileRpc.write(oneTab + "RPCReturn" + str(strReturnCount) + "(" + strParamsNoType + ");\n}\n\n")
	  
				fileRpc.close() 
 
def GenerateRpcDatas():
	sameNamespace = collections.OrderedDict() 
	#生成所有的rpc
	for index , serverName in g_rpcMsgs.rpcServerNames.items():    
		outputPath = GetOutputPath(serverName.serverName)   
		outputPath += "RpcDatas.h" 
			 
		fileRpc = open(outputPath , "a")
		if serverName.namespace not in sameNamespace :
			GenerateRpcDatasHeader(fileRpc , serverName)
			sameNamespace[serverName.namespace] = 1 

			for index , rpcData in g_rpcMsgs.rpcs.rpcDatas.items():   
				fileRpc.write(oneTab + "struct " + rpcData.name + "\n") 
				fileRpc.write(oneTab + "{ \n")
				WriteDefineParamsWithoutDefault(fileRpc , rpcData.params) 
				
				fileRpc.write("\n")
				fileRpc.write(twoTab + rpcData.name + "()\n")
				WriteDefineParamsWithDefault(fileRpc , rpcData.params)  
				fileRpc.write(threeTab + "{}\n")
				
				
				fileRpc.write(oneTab + "}; \n \n")
			
		fileRpc.close()

	sameNamespace = collections.OrderedDict() 
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():  
		outputPath = GetOutputPath(rpcServerName.serverName)  
		outputPath = outputPath + "RpcDatas.h"     
		
		if rpcServerName.namespace not in sameNamespace : 
			fileRpc = open(outputPath , "a")
			fileRpc.write("}\n\n")	
			fileRpc.write("#endif\n")				
			fileRpc.close()
			sameNamespace[rpcServerName.namespace] = 1
			
def  GenerateRpcDatasHeader(fileRpc , serverName):
	WriteFileDescription(fileRpc , "RpcDatas.h" , "网络消息的数据域.") 
	fileRpc.write("#ifndef __" + serverName.namespace + "_rpc_datas_h__\n") 
	fileRpc.write("#define __" + serverName.namespace + "_rpc_datas_h__\n")  
	fileRpc.write("#include \"Common/Common.h\"\n") 
	fileRpc.write("#include \"Common/Chunk.h\"\n\n")   
	fileRpc.write("namespace " + serverName.namespace)   
	fileRpc.write("\n{\n")   
	
def GenerateRpcCallFuncs(): 
	sameNamespace = collections.OrderedDict() 
	for index , serverName in g_rpcMsgs.rpcServerNames.items(): 
		outputPath = GetOutputPath(serverName.serverName)   
		outputPath += "RPCCallFuncs.h" 
			 
		fileRpc = open(outputPath , "a")
		if serverName.namespace not in sameNamespace :
			GenerateRpcCallFuncsHeader(fileRpc , serverName)
			sameNamespace[serverName.namespace] = 1 
		
		for index , rpc in g_rpcMsgs.rpcs.rpcs.items(): 
			for targetInde , target in rpc.targets.items():
				if serverName.serverName == target.name and target.targetType == g_targetTypeClient:	
					strDefaultParams = GetParamsIncludeDefaultParam(rpc.call.params) 
					syncType = GetSyncTypeInString(rpc.syncType)	
					
					strExcludeDefaultParams = GetParamsExcludeDefaultParamAndType(rpc.call.params) 
					strExcludeDefaultParamsCount = len(rpc.call.params)
					
					#生成sessionName方式带有vec发送的RPC					
					fileRpc.write(oneTab + "static INT32  rpc_" + rpc.name + "(const char * pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc " + strDefaultParams + " , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = " +syncType + ")\n" + oneTab + "{\n")
					fileRpc.write(twoTab + "GEN_RPC_CALL_" + str(strExcludeDefaultParamsCount) + "((&(" + serverName.namespace + "::" + serverName.rpcInterface + "::GetInstance())) , pSessionName , " + "Msg::g_sz" + rpc.name + "_RpcCall " + strExcludeDefaultParams + ", vecTargets , objSrc , usPriority , " + serverName.namespace + "::" + serverName.rpcInterface + "::GetInstance().GetServerName() , objSyncType , " + str(rpc.timeout) + ");\n" + oneTab + "}\n\n")
					
					#生成sessionName方式不带有vec发送的RPC
					fileRpc.write(oneTab + "static INT32  rpc_" + rpc.name + "(const char * pSessionName , Msg::Object objTarget, Msg::Object objSrc " + strDefaultParams + " , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = " +syncType + ")\n")
					fileRpc.write(oneTab + "{\n")
					
					fileRpc.write(twoTab + "std::vector<Msg::Object> vecTargets;\n" + twoTab + "vecTargets.push_back(objTarget);\n" )
					fileRpc.write(twoTab + "return rpc_" + rpc.name + "( pSessionName ,vecTargets , objSrc " + strExcludeDefaultParams + ", usPriority , objSyncType);\n" )
					fileRpc.write(oneTab + "}\n\n")		
					
					#生成sessionName方式不带有vec且全局发送的RPC
					fileRpc.write(oneTab + "static INT32  rpc_" + rpc.name + "(const char * pSessionName , Msg::Object objSrc " + strDefaultParams + " , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = " +syncType + ")\n")
					fileRpc.write(oneTab + "{\n")
					  
					fileRpc.write(twoTab + "return rpc_" + rpc.name + "( pSessionName , 0 , objSrc " + strExcludeDefaultParams + ", usPriority , objSyncType);\n" )
					fileRpc.write(oneTab + "}\n\n")	
					
					#生成strNodeName方式带有vec发送的RPC
					fileRpc.write(oneTab + "static INT32  rpc_" + rpc.name + "(const std::string & pSessionName , Msg::VecObjects & vecTargets , Msg::Object objSrc " + strDefaultParams + " , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = " +syncType + ")\n")
					fileRpc.write(oneTab + "{\n")
					
					fileRpc.write(twoTab + "GEN_RPC_CALL_" + str(strExcludeDefaultParamsCount) + "((&(" + serverName.namespace + "::" + serverName.rpcInterface + "::GetInstance())) , pSessionName , " + "Msg::g_sz" + rpc.name + "_RpcCall " + strExcludeDefaultParams + ", vecTargets , objSrc , usPriority , " + serverName.namespace + "::" + serverName.rpcInterface + "::GetInstance().GetServerName() , objSyncType , " + str(rpc.timeout) + ");\n")
					fileRpc.write(oneTab + "}\n\n")	
																	
					#生成strNodeName方式不带有vec发送的RPC
					fileRpc.write(oneTab + "static INT32  rpc_" + rpc.name + "(const std::string & pSessionName , Msg::Object objTarget, Msg::Object objSrc " + strDefaultParams + " , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = " +syncType + ")\n")
					fileRpc.write(oneTab + "{\n")
					
					fileRpc.write(twoTab + "std::vector<Msg::Object> vecTargets;\n" + twoTab + "vecTargets.push_back(objTarget);\n" )
					fileRpc.write(twoTab + "return rpc_" + rpc.name + "( pSessionName ,vecTargets , objSrc " + strExcludeDefaultParams + ", usPriority , objSyncType);\n" )
					fileRpc.write(oneTab + "}\n\n")	
							
					#生成strNodeName方式不带有vec且全局发送的RPC
					fileRpc.write(oneTab + "static INT32  rpc_" + rpc.name + "(const std::string & pSessionName , Msg::Object objSrc " + strDefaultParams + " , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = " +syncType + ")\n")
					fileRpc.write(oneTab + "{\n")
					
					fileRpc.write(twoTab + "return rpc_" + rpc.name + "( pSessionName , 0 , objSrc " + strExcludeDefaultParams + ", usPriority , objSyncType);\n" )
					fileRpc.write(oneTab + "}\n\n")	
					
					#生成sessionID方式带有vec发送的RPC
					fileRpc.write(oneTab + "static INT32  rpc_" + rpc.name + "(INT32 nSessionID , Msg::VecObjects & vecTargets , Msg::Object objSrc " + strDefaultParams + " , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = " +syncType + ")\n")
					fileRpc.write(oneTab + "{\n")
					
					fileRpc.write(twoTab + "GEN_RPC_CALL_" + str(strExcludeDefaultParamsCount) + "((&(" + serverName.namespace + "::" + serverName.rpcInterface + "::GetInstance())) , nSessionID , " + "Msg::g_sz" + rpc.name + "_RpcCall " + strExcludeDefaultParams + ", vecTargets , objSrc , usPriority , " + serverName.namespace + "::" + serverName.rpcInterface + "::GetInstance().GetServerName() , objSyncType , " + str(rpc.timeout) + ");\n")
					fileRpc.write(oneTab + "}\n\n")	
																	
					#生成sessionID方式不带有vec发送的RPC
					fileRpc.write(oneTab + "static INT32  rpc_" + rpc.name + "(INT32 nSessionID , Msg::Object objTarget, Msg::Object objSrc " + strDefaultParams + " , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = " +syncType + ")\n")
					fileRpc.write(oneTab + "{\n")
					
					fileRpc.write(twoTab + "std::vector<Msg::Object> vecTargets;\n" + twoTab + "vecTargets.push_back(objTarget);\n" )
					fileRpc.write(twoTab + "return rpc_" + rpc.name + "( nSessionID ,vecTargets , objSrc " + strExcludeDefaultParams + ", usPriority , objSyncType);\n" )	
					fileRpc.write(oneTab + "}\n\n")	
										
					#生成sessionID方式不带有vec且全局发送的RPC
					fileRpc.write(oneTab + "static INT32  rpc_" + rpc.name + "(INT32 nSessionID , Msg::Object objSrc " + strDefaultParams + " , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = " +syncType + ")\n")
					fileRpc.write(oneTab + "{\n")
					
					fileRpc.write(twoTab + "return rpc_" + rpc.name + "( nSessionID , 0 , objSrc " + strExcludeDefaultParams + ", usPriority , objSyncType);\n" )
					fileRpc.write(oneTab + "}\n\n")	
					
		fileRpc.close()
			
	sameNamespace = collections.OrderedDict() 
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
	WriteFileDescription(fileRpc , "RpcCallFuncs.h" , "客户端调用的rpc.") 
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

def LogOutDebug(*string):
	longStr = ""
	for item in range(len(string)):  
		longStr += str(string[item])

#	print(longStr)
	pass

def LogOutInfo(*string):
	longStr = ""
	for item in range(len(string)):  
		longStr += str(string[item])
	
	print(longStr)
	
def WriteFileDescription(fileRpc , file , desc):
	fileRpc.write("/************************************" + "\n")
	fileRpc.write("FileName	:	" + file + "\n")
	fileRpc.write("Author		:	generate by tools" + "\n")
	fileRpc.write("HostName	:	" + socket.gethostname() + "\n")
	fileRpc.write("IP			:	" + socket.gethostbyname(socket.gethostname()) + "\n")
	fileRpc.write("Version		:	0.0.1" + "\n")
	fileRpc.write("Date		:	" + time.strftime('%Y-%m-%d %H:%M:%S') + "\n")
	fileRpc.write("Description	:	" + desc + "\n")
	fileRpc.write("************************************/" + "\n")


#检查在RPCServerName中是否存在这样的服务器
def CheckInRpcServerName(name):
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():
		if rpcServerName.serverName == name: 
			return True

	LogOutInfo("no this serverName in serverNamelist")
	exit()

#通过服务器名字获取命名空间
def GetServerNamespaceByName(strName):
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items():
		if rpcServerName.serverName == strName: 
			return rpcServerName.namespace
			
	LogOutInfo("GetServerNamespaceByName error. serverName:" + strName)
	exit()
	
def GetOutputPath(name):
	for index , rpcServerName in g_rpcMsgs.rpcServerNames.items(): 
		if rpcServerName.serverName == name:
			if os.path.exists(rpcServerName.outputPath):  
				return rpcServerName.outputPath
			else: 
#				os.makedirs(rpcServerName.outputPath)
				return rpcServerName.outputPath

	LogOutInfo("no path is serverNamelist")
	exit()

def IsPathExist(path):
	if os.path.exists(path):
		return True
	else:
		return False

def GetParamsIncludeDefaultParam(params , type = 0):
	strParams = ""
	
	if len(params) != 0:		#如果有参数,则第一个加上 ,
		strParams += ", "
		
	nCount = 0
	for index , param in params.items(): 
		nCount += 1

		strParams = strParams + param.type
		if param.refer == "&":
			strParams = strParams + " "
			strParams = strParams + "&"
		strParams = strParams + " "
		strParams = strParams + param.name
		strParams = strParams + " = "

		if param.default == "" or param.default == None:
			strParams = strParams + GetAndCheckDefaultParam(param.type)
		else:
			strParams = strParams + param.default
		
		if type == 0:
			if nCount != len(params):              #默认最后一个不加
				strParams = strParams + " , " 
		else: #其他类型每一个都加
			strParams = strParams + " , " 
			
	return strParams
	
def GetParams(params):
	strParams = ""
	nCount = 0
	for index , param in params.items(): 
		nCount += 1

		strParams = strParams + param.type
		if param.refer == "&":
			strParams = strParams + " "
			strParams = strParams + "&"
		strParams = strParams + " "
		strParams = strParams + param.name
		strParams = strParams + " = "

		if param.default == "" or param.default == None:
			strParams = strParams + GetAndCheckDefaultParam(param.type)
		else:
			strParams = strParams + param.default
 
		if nCount != len(params):
			strParams = strParams + " , " 

#	if len(params) != 0:
#		strParams += ", "
		
	return strParams
	
def IsInDefaultParams(param):
	for index , defaultParam in g_rpcMsgs.defaultParams.items():
		if defaultParam.type == param.type:
			return True
	
	return False

def IsNotInTheSameParam(param , params):
	for index , defaultParam in params.items():
		if defaultParam.name == param.name:
			return True
	
	return False
	
def GetDefaultParamsType(theSameType):
	for index , defaultParam in g_rpcMsgs.defaultParams.items():
		if index.lower() == theSameType.lower():
			return index
			
	return theSameType
	
def WriteDefaultParams(fileRpc):
	for index , defaultParam in g_rpcMsgs.defaultParams.items():
		fileRpc.write(oneTab + "static " + defaultParam.type + " g_rpcDefaultParam_" + defaultParam.type + " = " + defaultParam.value + ";\n")
	fileRpc.write("\n")

def GetRpcParamsIncludeDefault(call):
	strParams = ""

	nCount = 0
	for index , param in call.params.items():
		strParams += " , "
		
		nCount = nCount + 1
		strParams += GetDefaultParamValue(param.type)

	return strParams
		
def GetParamsExcludeDefaultParam(params , type = 0):
	strParams = ""
	
	if len(params) != 0:
		strParams += ", "
		
	nCount = 0
	for index , param in params.items(): 
		nCount += 1

		strParams = strParams + param.type
		if param.refer == "&":
			strParams = strParams + " "
			strParams = strParams + "&"
		strParams = strParams + " "
		strParams = strParams + param.name
		strParams = strParams + "/* = "

		if param.default == "" or param.default == None:
			strParams = strParams + GetAndCheckDefaultParam(param.type)
		else:
			strParams = strParams + param.default

		strParams += "*/"
 
		if type == 0:
			if nCount != len(params):              #默认最后一个不加
				strParams = strParams + " , " 
		else: #其他类型每一个都加
			strParams = strParams + " , " 
			
	return strParams

def GetParamsExcludeDefaultParamAndType(params , type = 0):
	strParams = ""
	if len(params) != 0:
		strParams += ", "
		
	nCount = 0
	for index , param in params.items(): 

		nCount += 1
		strParams += param.name

		if type == 0:
			if nCount != len(params):              #默认最后一个不加
				strParams = strParams + " , " 
		else: #其他类型每一个都加
			strParams = strParams + " , " 			
		
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

def WriteDefineParamsWithoutDefault(fileRpc , params):
	for index , param in params.items():  
		strParams = twoTab 
		strParams += param.type
		strParams += " "
		strParams += param.name 

		strParams += ";\n" 
		fileRpc.write(strParams) 

def WriteDefineParamsWithDefault(fileRpc , params):
	fileRpc.write(threeTab + ":")
	nCount = 0
	for index , param in params.items():  
		nCount = nCount + 1
		strParams = ""   
		strParams += " "
		strParams += param.name  
		strParams += "( "

		if param.default == "" or param.default == None:
			strParams += GetAndCheckDefaultParam(param.type)
		else:
			strParams += param.default
		strParams += " ) \n" 

		if nCount != len(params):
			strParams += threeTab + ","  
		fileRpc.write(strParams)   
		
def GetParamsExcludeDefault(params):
	strParams = ""
	nCount = 0
	for index , param in params.items(): 
		nCount += 1

		strParams = strParams + param.type
		if param.refer == "&":
			strParams = strParams + " "
			strParams = strParams + "&"
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

#	if len(params) != 0:
#		strParams += ", "
	return strParams

def GetParamsExcludeDefaultAndType(params):
	strParams = ""
	nCount = 0
	for index , param in params.items(): 

		nCount += 1
		strParams = strParams + param.name

		if nCount != len(params):
			strParams = strParams + " , " 

#	if len(params) != 0:
#		strParams += ", "
		
	return strParams

def GetAndCheckDefaultParam(paramType):
	for index , defaultParam in g_rpcMsgs.defaultParams.items():
		if defaultParam.type == paramType: 
			return defaultParam.value

	LogOutInfo("no this value in defaultParamsList")
	exit()

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
			LogOutDebug(serverName.outputPath)
			os.makedirs(serverName.outputPath)
			
def GetDefaultParamValue(paramType):
	for index , param in g_rpcMsgs.defaultParamsList.items():
		if paramType == index:
			return param 
			
	LogOutInfo("no this defaultParam value in defaultParamsList")
	exit( )

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
	LogOutInfo("start generate rpc from path:" + g_rpcXmlPath) 
	start()  
	LogOutInfo("complete generate rpc.") 
	
if __name__ == '__main__': 
	main(sys.argv)


