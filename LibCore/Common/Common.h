#ifndef __common_h__
#define __common_h__

#include "MsgAssert.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string>
#include <vector>
#include <queue>
#include "ClassTypeID.h"
#include "Platform.h"
#include "ErrorCode.h"
 
#define TRUE    1
#define FALSE   0

#pragma warning(disable:4251)

typedef const char *     ConstCharPtr;
typedef unsigned char    UINT8; 

typedef short            INT16;
typedef unsigned short   UINT16; 

typedef ptrdiff_t        PtrDiff;

typedef int   BOOL;
typedef int   INT32;
typedef unsigned int   UINT32; 

#define MAX_NAME_LENGTH          50

#define SAFE_DELETE(x) if(x){ delete x; x = NULL;}
#define SAFE_DELETE_ARRAY(x) if(x){ delete []x; x = NULL;}
 
#endif