#include <bits/stdc++.h>
#include <cstdio>
#define pi (double) 3.14159265358979
using namespace std;

double
gauge (double squareSide, double circleRadius)
{
  double adyacentCathetus = 0;
  double sectorArea = 0;
  double sectorAngle = 0;
  double triangleAngle = 0;
  double triangleArea = 0;

  if (abs (circleRadius - squareSide) < 1e-9)
    return (double) 1.0;
  else if (circleRadius < ((squareSide) / 2.0))
    return double(pi * circleRadius * circleRadius);

  adyacentCathetus = squareSide / 2.0;

  // Get area of triangles surrounding circle sector
  triangleArea =
    adyacentCathetus * sqrt ((circleRadius * circleRadius) -
			     (adyacentCathetus * adyacentCathetus));

  // Angle of the triangles surrounding the circle sector
  triangleAngle = acos (adyacentCathetus / circleRadius);

  // We use triangleAngle to get the angle of the circle sector
  sectorAngle = abs ((pi / 2.0) - (2.0 * triangleAngle));

  // We finale use sectorAngle to get area of circle sector
  sectorArea = ((circleRadius * circleRadius) * sectorAngle) / 2.0;

  return (triangleArea + sectorArea) * 4.0;
}

int
main (void)
{
  int n = 0;
  int s = 0;
  int r = 0;

  cin >> n;
  while (n--)
    {
      cin >> s >> r;
      printf ("%.2f\n", gauge ((double) s, (double) r));
    }

  return 0;
}
