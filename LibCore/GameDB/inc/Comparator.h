#ifndef __gamedb_comparator_h__ 
#define __gamedb_comparator_h__
#include "GameDB/inc/DBCommon.h"
#include "leveldb/comparator.h"

namespace GameDB
{
	//5 ����levelDB�����õ�.
	class DLL_EXPORT Comparator :public leveldb::Comparator
	{
	public:
		Comparator(){}
		~Comparator(){}
		
	public:
		// Three-way comparison.  Returns value:
		//   < 0 iff "a" < "b",
		//   == 0 iff "a" == "b",
		//   > 0 iff "a" > "b"
		virtual INT32		Compare(const Slice& a, const Slice& b) const; 
		virtual void		FindShortestSeparator(std::string* start,const Slice& limit) const;
		virtual void		FindShortSuccessor(std::string* key) const;
		virtual const char* Name() const { return "GameDBComparator"; }
	};
}

#endif