#include "pw_xml.h"
#include "tokenizer.h"
#include <cstdio>
#include <cstdlib>
#include <fstream>

namespace pwutils
{
	struct XmlParseParams
	{
		std::vector<std::string> mParents;
		Xml::CollectionValuesT mValues;

		std::string GetParents()
		{
			std::string result;
			for(size_t i = 0; i < mParents.size(); ++i)
				result = result + "/" + mParents[i];
			return result;
		}
	};

	Xml::Xml()
	{
	}

	Xml::~Xml()
	{
	}

	static void XMLCALL
	startElement(void *userData, const char *name, const char **atts)
	{
		XmlParseParams* params = (XmlParseParams*)userData;
		params->mParents.push_back(name);
	}

	static void XMLCALL DataHandler(void *userData,const char *s,int len)
	{
		std::string key;
		std::string val(s,len);

		XmlParseParams* params = (XmlParseParams*)userData;

		key = params->GetParents();
		//std::cout << key << std::endl;
		params->mValues.insert(std::make_pair(key,val));
	}

	static void XMLCALL
	endElement(void *userData, const char *name)
	{
		XmlParseParams* params = (XmlParseParams*)userData;

		params->mParents.pop_back();
	}


	int Xml::LoadFromFile(const std::string& file)
	{
#ifdef WIN32
		std::fstream stream(file.c_str());
#else
		std::fstream stream(file);
#endif
		if(!stream.good())
			return -1;
		return LoadFromStream(stream);
	}

	int Xml::LoadFromStream(std::istream& stream)
	{
		XmlParseParams objParams;
		XML_Parser parser = XML_ParserCreate(NULL);
		XML_SetUserData(parser, &objParams);
		XML_SetCharacterDataHandler(parser,DataHandler);
		XML_SetElementHandler(parser, startElement, endElement);

		char buf[256] = "";
		while(true)
		{
			stream.getline(buf,sizeof(buf));
			bool eof = stream.eof();

			if (XML_Parse(parser, buf, strlen(buf), eof ? 1 : 0) == XML_STATUS_ERROR)
			{
				fprintf(stderr,
				        "%s at line %lu\n",
				        XML_ErrorString(XML_GetErrorCode(parser)),
				        XML_GetCurrentLineNumber(parser));
				return -1;
			}
			if(eof)
				break;
		}

		XML_ParserFree(parser);
		mValues = objParams.mValues;
		return 0;
	}

	int Xml::LoadFromString(const std::string& text)
	{
		XmlParseParams objParams;
		XML_Parser parser = XML_ParserCreate(NULL);
		XML_SetUserData(parser, &objParams);
		XML_SetCharacterDataHandler(parser,DataHandler);
		XML_SetElementHandler(parser, startElement, endElement);

		if (XML_Parse(parser, text.c_str(), text.length(), 1) == XML_STATUS_ERROR)
		{
			fprintf(stderr,
			        "%s at line %lu\n",
			        XML_ErrorString(XML_GetErrorCode(parser)),
			        XML_GetCurrentLineNumber(parser));
			return -1;
		}

		XML_ParserFree(parser);
		mValues = objParams.mValues;
		return 0;
	}
	
	std::string Xml::GetValue(const std::string& path,const std::string& defaultValue)
	{
		CollectionValuesT::iterator iter = mValues.find(path);
		if(iter == mValues.end())
			return defaultValue;
		return iter->second;
	}

}
