#include "cgeodesy/geodetic_position.h"
#include "cgeodesy/ellipsoid.h"
#include <math.h>

void Geodesy_TranslatePosLLH(PosLLH *pos,
                             const GeoVec *vec) {

  Radii radii = Ellipsoid_CalculateRadiiOfCurvature(pos->latitude_radians);
  /* Just breaking out height to make calculation lines shorter/cleaner */
  const double h = pos->height_metres;
  const double cos_lat = cos(pos->latitude_radians);

  pos->latitude_radians += vec->north_metres / (radii.meridian_metres + h);
  pos->longitude_radians += vec->east_metres / ((radii.transverse_metres + h) * cos_lat);
  pos->height_metres -= vec->down_metres;
}