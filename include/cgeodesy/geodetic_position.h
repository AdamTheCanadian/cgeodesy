#ifndef CGEODESY_INCLUDE_CGEODESY_GEODETIC_POSITION_H_
#define CGEODESY_INCLUDE_CGEODESY_GEODETIC_POSITION_H_

typedef struct CurvlinearPosition {
  double latitude_radians;
  double longitude_radians;
  double height_metres;
} PosLLH;

typedef struct EcefPosition {
  double x_metres;
  double y_metres;
  double z_metres;
} PosXYZ;

#endif
