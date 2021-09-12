#include <iostream>
#include "lab1.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace lab1Normal;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Dialog* dialog = new Dialog();
	bool dial = true;

	while (dial) {
		switch (dialog->getOption()) {
		case Dialog::options::Exit:
			delete dialog;
			dial = false;
			break;
		case Dialog::options::MatrixInput:
			dialog->matrixInput();
			break;
		case Dialog::options::MatrixOutput:
			dialog->matrixOutput();
			break;
		case Dialog::options::VectorOutput:
			dialog->vectorOutput();
			break;
		case Dialog::options::Waiting:
			dialog->menu();
			break;
		}
	}
}