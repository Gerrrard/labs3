#ifndef _UTILITY_H_
#define _UTILITY_H_
#include "ACurve.h"

namespace Utility {
	bool isInt(const char* S);
	bool isDouble(const char* S);
	template <class V> int getNum(V& a, const char* msg);
}

namespace Menu {
	void start(Lab2::ASpiral* spir);
	int menu();
	void menuExit(Lab2::ASpiral* spir);
	void menuParametrInput(Lab2::ASpiral* spir);
	void menuDistance(Lab2::ASpiral* spir);
	void menuSectorArea(Lab2::ASpiral* spir);
	void menuRingArea(Lab2::ASpiral* spir);
	void menuTurnArea(Lab2::ASpiral* spir);
	void menuLength(Lab2::ASpiral* spir);
	void menuCurvatureRadius(Lab2::ASpiral* spir);
}

#endif
