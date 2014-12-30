#ifndef __xml_xml_h__
#define __xml_xml_h__   
#include <iostream>
#include "XMLValue.h"

namespace XML
{ 
	class XML
	{
	public:
		XML(){}
		virtual ~XML(){}  

	public:
		static void StartElement(void * pUserData , const char * pName , const char ** pAttr);
		static void DataHandler(void * pUserData , const char * pValue , int nLength);
		static void EndElement(void * pUserData , const char * pName);

	public:
		INT32 DLL_EXPORT LoadFromFile(const std::string strFilePath);
		INT32 DLL_EXPORT LoadFromStream(std::istream & stream);
		INT32 DLL_EXPORT LoadFromString(const std::string strXMLContent);

	public:
		std::string DLL_EXPORT GetXMLValue(std::string  strXMLPath , std::string strDefaultValue = "" );

	private:
		MapValuesT   m_mapXMLValues;
	};
}
 
#endif