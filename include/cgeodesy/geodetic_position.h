#ifndef CGEODESY_INCLUDE_CGEODESY_GEODETIC_POSITION_H_
#define CGEODESY_INCLUDE_CGEODESY_GEODETIC_POSITION_H_

typedef struct GeodeticVector {
  double north_metres;
  double east_metres;
  double down_metres;
} GeoVec;

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

/**
 * Shift/translate a geodetic position LLH by a given geodetic vector.
 * For example shift a latitude (pos) by N metres (vec)
 * Modifies (pos) in place
 */
void Geodesy_TranslatePosLLH(PosLLH *pos,
                             const GeoVec *vec);

#endif
