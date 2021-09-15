//#include "stdafx.h"
#include <iostream>
#include "../StaticLib1/ACurve.h"
#include "gtest/gtest.h"
#include "tchar.h"

TEST(ACurveConstructor, DefaultConstructor)
{
	Lab2::ASpiral a1;
	ASSERT_EQ(1, a1.getA());
}
TEST(ACurveConstructor, InitConstructors)
{
	Lab2::ASpiral a2(3);
	ASSERT_EQ(3, a2.getA());
	Lab2::ASpiral a3(-5);
	ASSERT_EQ(-5, a3.getA());
}
TEST(CircleMethods, Setters)
{
	Lab2::ASpiral a;
	a.setA(3);
	ASSERT_EQ(3, a.getA());
}
TEST(CircleMethods, Parameters)
{
	Lab2::ASpiral a1;
	const double err = 0.00001;
	ASSERT_EQ(0, a1.distance(0));
	ASSERT_EQ(1, a1.distance(1));
	ASSERT_NEAR(0.5, a1.curvature(0), err);
	ASSERT_NEAR(0.5291336, a1.curvature(1), err);
	ASSERT_EQ(0, a1.curveLength(0));
	ASSERT_NEAR(0.613974, a1.curveLength(1), err);
	ASSERT_NEAR(4 / 3, a1.sectorArea(0, 2), err);
	ASSERT_NEAR(118 / 6, a1.sectorArea(5, 7), err);
	ASSERT_NEAR(118 / 6, a1.sectorArea(7, 5), err);
	ASSERT_ANY_THROW(a1.sectorArea(-3, 3));
	ASSERT_ANY_THROW(a1.sectorArea(3, -3));
	ASSERT_NEAR(1116.2259585, a1.figureAreaTurn(3), err);
	ASSERT_EQ(0, a1.figureAreaTurn(0));
	ASSERT_ANY_THROW(a1.figureAreaTurn(-3));
	ASSERT_NEAR(785.492341167, a1.figureRingAreaTurn(3), err);
	ASSERT_EQ(0, a1.figureRingAreaTurn(0));
	ASSERT_ANY_THROW(a1.figureRingAreaTurn(-3));
	Lab2::ASpiral a2(5);
	ASSERT_EQ(0, a2.distance(0));
	ASSERT_EQ(a2.getA(), a2.distance(1));
	ASSERT_NEAR(2.5, a2.curvature(0), err);
	ASSERT_NEAR(0.5291336 * 5, a2.curvature(1), err);
	ASSERT_EQ(0, a2.curveLength(0));
	ASSERT_NEAR(0.613974 * 5, a2.curvature(1), err);
	ASSERT_NEAR(4 / 3 / 5, a2.sectorArea(0, 2), err);
	ASSERT_NEAR(118 / 6 / 5, a2.sectorArea(5, 7), err);
	ASSERT_NEAR(118 / 6 / 5, a2.sectorArea(7, 5), err);
	ASSERT_ANY_THROW(a2.sectorArea(-3, 3));
	ASSERT_ANY_THROW(a2.sectorArea(3, -3));
	ASSERT_NEAR(1116.2259585 * 5, a2.figureAreaTurn(3), err);
	ASSERT_EQ(0, a2.figureAreaTurn(0));
	ASSERT_ANY_THROW(a2.figureAreaTurn(-3));
	ASSERT_NEAR(785.492341167 * 5, a2.figureRingAreaTurn(3), err);
	ASSERT_EQ(0, a2.figureRingAreaTurn(0));
	ASSERT_ANY_THROW(a1.figureRingAreaTurn(-3));
	Lab2::ASpiral a3(0);
	ASSERT_EQ(0, a1.sectorArea(7, 5));
}

int _tmain(int argc, _TCHAR* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}