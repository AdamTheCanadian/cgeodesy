#ifndef CGEODESY_TESTS_GEODETIC_POSITION_TESTS_H_
#define CGEODESY_TESTS_GEODETIC_POSITION_TESTS_H_

#include "ctest/unit_test.h"
#include "cgeodesy/geodetic_position.h"

void shift_position_tests() {
  PosLLH pos = {
      .latitude_radians = 0.890117918520000,
      .longitude_radians = 0,
      .height_metres = 10
  };
  GeoVec shift = {
      .north_metres = 1.2,
      .east_metres = 3.4,
      .down_metres = 5.6
  };

  Geodesy_TranslatePosLLH(&pos, &shift);
  UNIT_TEST_EXPECT_EQ_DOUBLE_EPS("", pos.latitude_radians, 0.890118106782854, 1.0e-8);
  UNIT_TEST_EXPECT_EQ_DOUBLE_EPS("", pos.longitude_radians, 8.45342804603127e-07, 1.0e-8);
  UNIT_TEST_EXPECT_EQ_DOUBLE_EPS("", pos.height_metres, 4.400, 1.0e-5);
}

void geodetic_position_tests_run() {
  UNIT_TEST_SETUP("Geodetic Position");
  UNIT_TEST_RUN_TEST("Shift Position", shift_position_tests);
  UNIT_TEST_FINISH("Geodetic Position");
}
#endif
