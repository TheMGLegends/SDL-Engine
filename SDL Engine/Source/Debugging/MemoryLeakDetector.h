#pragma once

// INFO: Detection Flags for Memory Leaks (Needs to be placed in main.cpp)
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

// INFO: Specify unique allocation number identified during debug mode runtime to break at that point (Needs to be placed in main.cpp)
//_CrtSetBreakAlloc(UNIQUE ALLOCATION NUMBER)

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#else
#define DBG_NEW
#endif

#ifdef _DEBUG
#define new DBG_NEW
#endif