#ifndef CGEODESY_TESTS_ELLIPSOID_TESTS_H_
#define CGEODESY_TESTS_ELLIPSOID_TESTS_H_

#include "ctest/unit_test.h"
#include "cgeodesy/ellipsoid.h"

void radii_tests() {
  Radii radii = Ellipsoid_CalculateRadiiOfCurvature(0.890117918517108);
  UNIT_TEST_EXPECT_EQ_DOUBLE_EPS("", radii.meridian_metres, 6374056.74593700, 1.0e-8);
  UNIT_TEST_EXPECT_EQ_DOUBLE_EPS("", radii.transverse_metres, 6391069.98485802, 1.0e-8);
}

void ellipsoid_tests_run() {
  UNIT_TEST_SETUP("Ellipsoid");
  UNIT_TEST_RUN_TEST("Radii", radii_tests);
  UNIT_TEST_FINISH("Ellipsoid");
}

#endif
