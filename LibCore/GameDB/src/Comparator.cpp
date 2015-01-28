#include "GameDB/inc/Comparator.h"

namespace GameDB
{


	INT32 Comparator::Compare(const Slice& a, const Slice& b) const
	{
		const leveldb::Comparator * pBaseComparator = leveldb::BytewiseComparator();


		//5 调用系统默认的比较函数.
		return pBaseComparator->Compare(a , b);
	}

	void Comparator::FindShortestSeparator(std::string* start,const Slice& limit) const
	{
		const leveldb::Comparator * pBaseComparator = leveldb::BytewiseComparator();

		pBaseComparator->FindShortestSeparator(start , limit );
	}

	void Comparator::FindShortSuccessor(std::string* key) const
	{ 
		const leveldb::Comparator * pBaseComparator = leveldb::BytewiseComparator();

		pBaseComparator->FindShortSuccessor(key);
	}

}