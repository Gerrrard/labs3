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

#endif
