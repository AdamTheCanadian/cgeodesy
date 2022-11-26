#ifndef CGEODESY_INCLUDE_CGEODESY_ELLIPSOID_H_
#define CGEODESY_INCLUDE_CGEODESY_ELLIPSOID_H_

typedef struct Radii {
  double meridian_metres;
  double transverse_metres;
} Radii;

/**
 * Calculate the radii of curvature at a given latitude.
 * Assumes WGS84 ellipsoid
 * \param latInRadians
 * \return
 */
Radii Ellipsoid_CalculateRadiiOfCurvature(double latInRadians);

#endif
