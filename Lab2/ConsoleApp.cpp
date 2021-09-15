#include <iostream>
#include <string.h>
#include "tchar.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "../StaticLib1/ACurve.h"

int _tmain(int argc, _TCHAR* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    Lab2::ASpiral* spiral = new Lab2::ASpiral();
    int Option = 10;

    Menu::start(spiral);

    delete spiral;
}
