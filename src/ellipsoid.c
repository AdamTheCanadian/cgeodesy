#include "cgeodesy/ellipsoid.h"
#include "cgeodesy/wgs84.h"
#include <math.h>

Radii Ellipsoid_CalculateRadiiOfCurvature(double latInRadians) {
  double temp = WGS84_ECCENTRICITY * sin(latInRadians);
  /* Square value */
  temp *= temp;
  temp = 1.0 - temp;

  Radii radii;
  radii.meridian_metres = WGS84_SEMI_MAJOR_AXIS * (1.0 - WGS84_ECCENTRICITY_SQR) / pow(temp, 1.5);
  radii.transverse_metres = WGS84_SEMI_MAJOR_AXIS / sqrt(temp);
  return radii;
}