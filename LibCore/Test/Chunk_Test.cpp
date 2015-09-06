#include "CUtil/inc/Chunk.h"
#include "UnitTest++/UnitTestPP.h"

// struct ChunkFixture
// {
// 	ChunkFixture() 
// 	{ 
// 	}
// 	~ChunkFixture() { /* some teardown */ }
// 
// 	CUtil::Chunk objChunk;
// };
// TEST_FIXTURE(ChunkFixture, Chunk)
// {
// 	CHECK_EQUAL(pStr2 , pStr1); // succeeds 
//}

TEST(Chunk)
{
	{
		CUtil::Chunk objChunk;
		CHECK_EQUAL(objChunk.GetChunkData()->GetDataLen() , 0);
		{
			CUtil::Chunk objChunk2 = objChunk;
			CHECK_EQUAL(objChunk.GetChunkData()->m_refCount , 2);
		}
		CHECK_EQUAL(objChunk.GetChunkData()->m_refCount , 1);
	}
	{
		CUtil::Chunk objChunk("test" , sizeof("test"));
		CUtil::Chunk objChunk2("test2" , sizeof("test2"));
		CUtil::Chunk objChunk3("test" , sizeof("test"));
		CUtil::Chunk objChunk4;
		CUtil::Chunk objChunk5;
		CHECK_EQUAL(objChunk != objChunk2 , true);
		CHECK_EQUAL(objChunk == objChunk3 , true);
		CHECK_EQUAL(objChunk4 == objChunk5 , true);
	}
	{
		CUtil::Chunk objChunk("test" , sizeof("test"));
		CUtil::Chunk objChunk2;
		CUtil::Chunk objChunk3;
		objChunk2.Insert(objChunk2.Begin() , "test" , sizeof("test"));
		objChunk3.Pushback("test" , sizeof("test"));
		CHECK_EQUAL(objChunk == objChunk2 , true);
		CHECK_EQUAL(objChunk2.GetDataLen() == sizeof("test") , true);
		CHECK_EQUAL(objChunk == objChunk3 , true);
		CHECK_EQUAL(objChunk3.GetDataLen() == sizeof("test") , true);
	}
	{
		CUtil::Chunk objChunk2;
		CUtil::Chunk objChunk3;
		objChunk2.Reverse(11);
		CHECK_EQUAL(objChunk2.GetSize() == 16 , true); 
		objChunk2.Reverse(17);
		CHECK_EQUAL(objChunk2.GetSize() == 32 , true);

		CHECK_EQUAL(objChunk2 == objChunk3 , true);
	}
}
