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
TEST(CircleMethods, DistanceMethod)
{
	Lab2::ASpiral a1;
	const double err = 0.00001;
	ASSERT_EQ(0, a1.distance(0));
	ASSERT_EQ(1, a1.distance(1));
	Lab2::ASpiral a2(5);
	ASSERT_EQ(0, a2.distance(0));
	ASSERT_EQ(a2.getA(), a2.distance(1));
}

TEST(CircleMethods, CurvatureMethod)
{
	Lab2::ASpiral a1;
	const double err = 0.00001;
	ASSERT_NEAR(0.5, a1.curvature(0), err);
	ASSERT_NEAR(0.5291336, a1.curvature(1), err);
	Lab2::ASpiral a2(5);
	ASSERT_NEAR(2.5, a2.curvature(0), err);
	ASSERT_NEAR(0.5291336 * 5, a2.curvature(1), err);
}

TEST(CircleMethods, CurveLengthMethod)
{
	Lab2::ASpiral a1;
	const double err = 0.00001;
	ASSERT_EQ(0, a1.curveLength(0));
	ASSERT_NEAR(0.613974, a1.curveLength(1), err);
	Lab2::ASpiral a2(5);
	ASSERT_EQ(0, a2.curveLength(0));
	ASSERT_NEAR(0.613974 * 5, a2.curveLength(1), err);
}

TEST(CircleMethods, SectorAreaMethod)
{
	Lab2::ASpiral a1;
	const double err = 0.00001;
	ASSERT_NEAR(1.33333, a1.sectorArea(0, 2), err);
	ASSERT_NEAR(36.33333, a1.sectorArea(5, 7), err);
	ASSERT_NEAR(36.33333, a1.sectorArea(7, 5), err);
	EXPECT_THROW({
	try {
		a1.sectorArea(-3, 3);
	}
	catch (std::exception& e) {
		EXPECT_STREQ("invalid radius1", e.what());
		throw;
	}
	}, std::exception);
	EXPECT_THROW({
	try {
		a1.sectorArea(3, -3);
	}
	catch (std::exception& e) {
		EXPECT_STREQ("invalid radius2", e.what());
		throw;
	}
	}, std::exception);
	Lab2::ASpiral a2(5);
	ASSERT_NEAR(0.266667, a2.sectorArea(0, 2), err);
	ASSERT_NEAR(7.266667, a2.sectorArea(5, 7), err);
	ASSERT_NEAR(7.266667, a2.sectorArea(7, 5), err);
	EXPECT_THROW({
	try {
		a2.sectorArea(-3, 3);
	}
	catch (std::exception& e) {
		EXPECT_STREQ("invalid radius1", e.what());
		throw;
	}
		}, std::exception);
	EXPECT_THROW({
	try {
		a2.sectorArea(3, -3);
	}
	catch (std::exception& e) {
		EXPECT_STREQ("invalid radius2", e.what());
		throw;
	}
		}, std::exception);
	Lab2::ASpiral a3(0);
	ASSERT_EQ(0, a3.sectorArea(7, 5));
}

TEST(CircleMethods, FigureAreaTurnMethod)
{
	Lab2::ASpiral a1;
	const double err = 0.00003;
	ASSERT_NEAR(1116.2259585, a1.figureAreaTurn(3), err);
	ASSERT_EQ(0, a1.figureAreaTurn(0));
	EXPECT_THROW({
	try {
		a1.figureAreaTurn(-3);
	}
	catch (std::exception& e) {
		EXPECT_STREQ("invalid turn count", e.what());
		throw;
	}
	}, std::exception);
	Lab2::ASpiral a2(5);
	ASSERT_NEAR(27905.6489625, a2.figureAreaTurn(3), err);
	ASSERT_EQ(0, a2.figureAreaTurn(0));
	EXPECT_THROW({
	try {
		a2.figureAreaTurn(-3);
	}
	catch (std::exception& e) {
		EXPECT_STREQ("invalid turn count", e.what());
		throw;
	}
	}, std::exception);
}

TEST(CircleMethods, FigureRingAreaTurnMethod)
{
	Lab2::ASpiral a1;
	const double err = 0.00003;
	ASSERT_NEAR(785.492341167, a1.figureRingAreaTurn(3), err);
	ASSERT_EQ(0, a1.figureRingAreaTurn(0));
	EXPECT_THROW({
	try {
		a1.figureRingAreaTurn(-3);
	}
	catch (std::exception& e) {
		EXPECT_STREQ("invalid turn count", e.what());
		throw;
	}
	}, std::exception);
	Lab2::ASpiral a2(5);
	ASSERT_NEAR(19637.3085292, a2.figureRingAreaTurn(3), err);
	ASSERT_EQ(0, a2.figureRingAreaTurn(0));
	EXPECT_THROW({
	try {
		a2.figureRingAreaTurn(-3);
	}
	catch (std::exception& e) {
		EXPECT_STREQ("invalid turn count", e.what());
		throw;
	}
	}, std::exception);
}

int _tmain(int argc, _TCHAR* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
