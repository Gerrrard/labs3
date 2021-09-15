#ifndef _SPIRAL_H_
#define _SPIRAL_H_
#include <math.h>
namespace Lab2 {
	class ASpiral {
	private:
		double a;
	public:
		ASpiral() : a(1) {};
		ASpiral(double _a) : a(_a) {};
		void setA(double _a);
		double getA() const { return a; }

		double distance (double angle) const;
		double sectorArea(double radius1, double radius2) const;
		double curvature(double angle) const;
		double curveLength(double angle) const;
		double figureAreaTurn(int turn) const;
		double figureRingAreaTurn(int turn) const;
	};
}

namespace Utility {
	bool is_Int(const char* S);
	bool is_Double(const char* S);
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