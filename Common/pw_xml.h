#ifndef PWXML_H
#define PWXML_H

#include "pw_def.h"

namespace pwutils
{
	class Xml
	{
	public:
		Xml();
		~Xml();
	public:
		int LoadFromFile(const std::string& file);
		int LoadFromStream(std::istream& stream);
		int LoadFromString(const std::string& text);
	public:
		std::string GetValue(const std::string& path,const std::string& defaultValue = "");
	public:
		typedef std::map<std::string,std::string> CollectionValuesT;
	private:
		CollectionValuesT mValues;
	};

}

#endif // PWXML_H
