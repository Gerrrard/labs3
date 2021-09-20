#include <strstream>
#include <cstring>
#include <iostream>
#include "ACurve.h"
#include <cmath>

namespace Lab2 {
	void ASpiral::setA(double _a)
	{
		a = _a;
	}

	double ASpiral::distance(double angle) const {
		return abs(a * angle);
	}

	double ASpiral::sectorArea(double radius1, double radius2) const {
		if (radius1 < 0) throw std::exception("invalid radius1");
		if (radius2 < 0) throw std::exception("invalid radius2");

		return a == 0 ? 0 : (abs(pow(radius1, 3) - pow(radius2, 3)) / 6 / abs(a));
	}

	double ASpiral::curvature(double angle) const {
		double ang = angle * angle;
		return (a * pow(1 + ang, (double)2 / 3) / (ang + 2));
	}

	double ASpiral::curveLength(double angle) const {
		double temp = sqrt(1 + angle * angle);
		return abs(a) / 2 * abs(angle * log(temp) + log(angle + temp));
	}

	double ASpiral::figureAreaTurn(int turn) const {
		if(turn < 0) throw std::exception("invalid turn count");

		double _2pi_pow3_div6 = 41.3417022;
		return turn == 0 ? 0 : a * a * _2pi_pow3_div6 * pow(turn, 3);
	}

	double ASpiral::figureRingAreaTurn(int turn) const {
		if (turn < 0) throw std::exception("invalid turn count");

		double _2pi_pow3_div6 = 41.3417022;
		return turn == 0 ? 0 : a * a * _2pi_pow3_div6 * (double)(3 * turn * (turn - 1) + 1);
	}
}
