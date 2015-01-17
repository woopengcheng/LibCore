#include "XMLLib/inc/xml.h"
#include "fstream"
#include "LogLib/inc/Log.h"
extern "C"
{
#include <expat.h> 
};

namespace XML
{  
	void XMLCALL XML::StartElement( void * pUserData , const char * pName , const char ** pAttr )
	{
		XMLValue * pValues = (XMLValue*)pUserData;
		pValues->GetVectorParents().push_back(pName);

	}

	void XMLCALL XML::DataHandler( void * pUserData , const char * pValue , int nLength )
	{
		XMLValue * pValues = (XMLValue*)pUserData;

		std::string strKey , strValue(pValue , nLength);
		strKey = pValues->GetParents();
		pValues->GetXMLValues().insert(std::make_pair(strKey , strValue));
	}

	void XMLCALL XML::EndElement( void * pUserData , const char * pName )
	{
		XMLValue * pValues = (XMLValue*)pUserData;

		pValues->GetVectorParents().pop_back();   //5 将最后一个值弹出去.
	}

	INT32 XML::LoadFromFile( const std::string strFilePath )
	{
		std::fstream fStream(strFilePath.c_str());

		if (!fStream.good())
		{
			return ERR_FAILURE;
		}
		
		return LoadFromStream(fStream);
	}

	INT32 XML::LoadFromStream( std::istream & objStream )
	{
		XMLValue   objValue; 
		XML_Parser objParser = XML_ParserCreate(NULL);

		XML_SetUserData(objParser , &objValue);
		XML_SetCharacterDataHandler(objParser , DataHandler);
		XML_SetElementHandler(objParser , StartElement , EndElement);

		char szBuf[512] = {'\0'};
		while(1)
		{
			objStream.getline(szBuf , sizeof(szBuf));
			bool bEOF = objStream.eof();

			if (XML_Parse(objParser , szBuf , (INT32)strlen(szBuf) , bEOF ? 1 : 0) == XML_STATUS_ERROR)
			{
				gErrorStream( XML_ErrorString(XML_GetErrorCode(objParser))  << "at line " <<  XML_GetCurrentLineNumber(objParser));
				return ERR_FAILURE;
			}
			if(bEOF)
				break;
		}

		XML_ParserFree(objParser);
		m_mapXMLValues = objValue.GetXMLValues();

		return ERR_SUCCESS;
	}

	INT32 XML::LoadFromString( const std::string strXMLContent )
	{ 
		XMLValue   objValue; 
		XML_Parser objParser = XML_ParserCreate(NULL);

		XML_SetUserData(objParser , &objValue);
		XML_SetCharacterDataHandler(objParser , DataHandler);
		XML_SetElementHandler(objParser , StartElement , EndElement);
		 
		if (XML_Parse(objParser , strXMLContent.c_str() , (INT32)strXMLContent.length() , 1) == XML_STATUS_ERROR)
		{
			gErrorStream( XML_ErrorString(XML_GetErrorCode(objParser))  << "at line " <<  XML_GetCurrentLineNumber(objParser));
			return -1;
		} 

		XML_ParserFree(objParser);
		m_mapXMLValues = objValue.GetXMLValues();

		return ERR_SUCCESS;
	}

	std::string XML::GetXMLValue( std::string strXMLPath , std::string strDefaultValue )
	{
		MapValuesT::iterator iter = m_mapXMLValues.find(strXMLPath);
		if(iter == m_mapXMLValues.end())
			return strDefaultValue;
		return iter->second;
	}

}
