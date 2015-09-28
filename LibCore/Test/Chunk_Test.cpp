#include "CUtil/inc/Chunk.h"
#include "UnitTest++/UnitTestPP.h"
 
TEST(Chunk)
{
	{
		CUtil::Chunk objChunk;
		CHECK_EQUAL(objChunk.GetChunkData()->GetDataLen() , 0);
		{
			CUtil::Chunk objChunk2 = objChunk;
			CHECK_EQUAL(objChunk.GetChunkData()->GetRefCount() , -1);
		}
		CHECK_EQUAL(objChunk.GetChunkData()->GetRefCount() , -1);
	}
	{
		CUtil::Chunk objChunk("test" , sizeof("test"));
		CUtil::Chunk objChunk2("test2" , sizeof("test2"));
		CUtil::Chunk objChunk3("test" , sizeof("test"));
		CUtil::Chunk objChunk4;
		CUtil::Chunk objChunk5;
		CHECK_EQUAL(objChunk != objChunk2 , true);
		CHECK_EQUAL(objChunk , objChunk3);
		CHECK_EQUAL(objChunk4 , objChunk5);
	}
	{
		CUtil::Chunk objChunk("test" , sizeof("test"));
		CUtil::Chunk objChunk2;
		CUtil::Chunk objChunk3;
		objChunk2.Insert(objChunk2.Begin() , "test" , sizeof("test"));
		objChunk3.Pushback("test" , sizeof("test"));
		CHECK_EQUAL(objChunk , objChunk2);
		CHECK_EQUAL(objChunk2.GetDataLen() , sizeof("test"));
		CHECK_EQUAL(objChunk , objChunk3);
		CHECK_EQUAL(objChunk3.GetDataLen() , sizeof("test"));
	}
	{
		CUtil::Chunk objChunk2;
		CUtil::Chunk objChunk3;
		objChunk2.Reverse(11);
		CHECK_EQUAL(objChunk2.GetSize() , 16); 
		objChunk2.Reverse(17);
		CHECK_EQUAL(objChunk2.GetSize() , 32);

		CHECK_EQUAL(objChunk2 , objChunk3);
	}
	{
		CUtil::Chunk objChunk("test" , sizeof("test"));
		objChunk.Clear();
		CHECK_EQUAL(objChunk.GetDataLen() , 0);
	}
	{
		CUtil::Chunk objChunk("test" , sizeof("test"));
		CUtil::Chunk objChunk1("est" , sizeof("est"));
		CUtil::Chunk objChunk2("st" , sizeof("st"));
		objChunk.Erase(objChunk.Begin() , (char *)objChunk.Begin() + 1);
		CHECK_EQUAL(objChunk.GetDataLen() , objChunk1.GetDataLen());
		CHECK_EQUAL(objChunk , objChunk1);
		objChunk.Erase(objChunk.Begin() , (char *)objChunk.Begin() + 1);
		CHECK_EQUAL(objChunk.GetDataLen() , objChunk2.GetDataLen());
		CHECK_EQUAL(objChunk , objChunk2);
	}
	{
		CUtil::Chunk objChunk("test" , sizeof("test"));
		CUtil::Chunk objChunk1("est" , sizeof("est"));
		CUtil::Chunk objChunk2("st" , sizeof("st"));
		CUtil::Chunk objChunk3;
		objChunk.Erase(objChunk.Begin() , (char *)objChunk.Begin() + 1);
		CHECK_EQUAL(objChunk.GetDataLen() , objChunk1.GetDataLen());
		CHECK_EQUAL(objChunk , objChunk1);
		objChunk.Erase(objChunk.Begin() , (char *)objChunk.Begin() + 1);
		CHECK_EQUAL(objChunk.GetDataLen() , objChunk2.GetDataLen());
		CHECK_EQUAL(objChunk , objChunk2);
		objChunk.Erase(objChunk.Begin() , (char *)objChunk.End());
		CHECK_EQUAL(objChunk.GetDataLen() , objChunk3.GetDataLen());
		CHECK_EQUAL(objChunk , objChunk3);
	}
	{
		CUtil::Chunk objChunk("test" , sizeof("test"));
		CUtil::Chunk objChunk1("te" , sizeof("te")-1);
		CUtil::Chunk objChunk2("st" , sizeof("st"));
		CUtil::Chunk objChunk3("tt" , sizeof("tt"));
		CHECK_EQUAL((UINT32)((char*)objChunk.End() - (char*)objChunk.Begin()) , objChunk.GetDataLen());

		objChunk1.Insert(objChunk1.End() , "st" , sizeof("st"));
		CHECK_EQUAL(objChunk , objChunk1);

		objChunk2.Insert(objChunk2.Begin() , "te" , sizeof("te") - 1);
		CHECK_EQUAL(objChunk , objChunk2);

		objChunk3.Insert((char*)(objChunk3.Begin()) + 1 , "es" , sizeof("es") - 1);
		CHECK_EQUAL(objChunk , objChunk3); 
	}
	{
		char szBuf[5 + sizeof(CUtil::ChunkData)] = {0};
		CUtil::Chunk objChunk(szBuf , sizeof(szBuf), false);
		CUtil::Chunk objChunk1("te" , sizeof("te") - 1);
		CUtil::Chunk objChunk2("test" , sizeof("test"));
		CUtil::Chunk objChunk3("test\0es" , sizeof("test\0es"));

		CHECK_EQUAL(objChunk.GetDataLen() , 0);
		CHECK_EQUAL(objChunk.GetSize() , sizeof(szBuf) - sizeof(CUtil::ChunkData));
		CHECK_EQUAL(objChunk.GetChunkData()->GetRefCount() , -1);

		objChunk.Insert(objChunk.Begin() , "te" , sizeof("te")-1);
		CHECK_EQUAL(objChunk.GetDataLen() , sizeof("te")-1);
		CHECK_EQUAL(objChunk.GetSize() , sizeof(szBuf) - sizeof(CUtil::ChunkData));
		CHECK_EQUAL(objChunk , objChunk1);
		CHECK_EQUAL(objChunk.GetChunkData()->GetRefCount() , -1);

		objChunk.Pushback("st" , sizeof("st"));
		CHECK_EQUAL(objChunk.GetDataLen() , sizeof("test"));
		CHECK_EQUAL(objChunk , objChunk2);
		CHECK_EQUAL(objChunk.GetSize() , sizeof(szBuf) - sizeof(CUtil::ChunkData));
		CHECK_EQUAL(objChunk.GetChunkData()->GetRefCount() , -1);

		objChunk.Insert(objChunk.End() , "es" , sizeof("es"));
		CHECK_EQUAL(objChunk.GetDataLen() , sizeof("test") + sizeof("es"));
		CHECK_EQUAL(objChunk , objChunk3);
		CHECK_EQUAL(objChunk.GetSize() , 8);
		CHECK_EQUAL(objChunk.GetChunkData()->GetRefCount() , 1);

		CUtil::Chunk objChunk4 = objChunk;
		CHECK_EQUAL(objChunk.GetChunkData()->GetRefCount() , 2);
		CHECK_EQUAL(objChunk.GetDataLen() , objChunk3.GetDataLen()); 

		objChunk4.Insert(objChunk4.End() , "!" , sizeof("!"));
		CHECK_EQUAL(objChunk.GetDataLen() , objChunk3.GetDataLen()); 
		CHECK_EQUAL(objChunk.GetSize() , 8);
		CHECK_EQUAL(objChunk.GetChunkData()->GetRefCount() , 1);
		CHECK_EQUAL(objChunk4.GetDataLen() , objChunk3.GetDataLen() + sizeof("!")); 
		CHECK_EQUAL(objChunk4.GetSize() , 16);
		CHECK_EQUAL(objChunk4.GetChunkData()->GetRefCount() , 1);
	}
}
