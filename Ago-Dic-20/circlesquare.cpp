#include <bits/stdc++.h>
#define epsilon 1e-6
#define x first
#define y second
using namespace std;

double distance (pair < int, int >, pair < int, int >);
double ptLine (pair < double, double >, pair < double, double >,
	       pair < double, double >);

//RPC07 - 2020

int
main (void)
{
  bool noPoint = false;
  bool onePoint = false;

  double r = 0;
  int tx = 0;
  int ty = 0;
  int s = 0;
  int points = 0;

  pair < int, int >center;
  vector < pair < int, int >>square;

  cin >> center.x >> center.y >> r;
  cin >> tx >> ty >> s;

  square.push_back (make_pair (tx, ty));
  square.push_back (make_pair (tx, ty + s));
  square.push_back (make_pair (tx + s, ty + s));
  square.push_back (make_pair (tx + s, ty));

  noPoint = true;

  for (int i = 0; i < 4; i++)
    {
      if (distance (square[i], center) < r - epsilon)
	{
	  cout << "2\n";
	  return 0;
	}
      else if (abs (distance (square[i], center) - r) < epsilon)
	{
	  double A = ptLine (center, square[i], square[(i + 1) % 4]);
	  double B = ptLine (center, square[i], square[(i + 3) % 4]);

	  //if (A == distance (center, square[i]) && B == 1)
	  if (abs (distance (center, square[i])) - A < epsilon
	      && abs (distance (center, square[i]) - B) < epsilon)
	    {
	      cout << "1\n";
	      return 0;
	    }
	  else
	    {
	      cout << "2\n";
	      return 0;
	    }
	}
    }

  for (int i = 0; i < 4; i++)
    {
      if (abs (ptLine (center, square[i], square[(i + 1) % 4]) - r) < epsilon)
	{
	  cout << "1\n";
	  return 0;
	}
      else if (ptLine (center, square[i], square[(i + 1) % 4]) < r - epsilon)
	{
	  cout << "2\n";
	  return 0;
	}
    }

  cout << "0\n";

  return 0;
}

double
ptLine (pair < double, double >E, pair < double, double >A, pair < double,
	double >B)
{
  double reqAns = 0;

  pair < double, double >AB;
  AB.x = B.x - A.x;
  AB.y = B.y - A.y;

  pair < double, double >BE;
  BE.x = E.x - B.x;
  BE.y = E.y - B.y;

  pair < double, double >AE;
  AE.x = E.x - A.x;
  AE.y = E.y - A.y;

  double AB_BE, AB_AE;

  AB_BE = ((AB.x * BE.x) + (AB.y * BE.y));
  AB_AE = ((AB.x * AE.x) + (AB.y * AE.y));

  if (AB_BE >= 0)
    {
      double ye = E.y - B.y;
      double eq = E.x - B.x;
      reqAns = sqrt (eq * eq + ye * ye);
    }
  else if (AB_AE <= 0)
    {
      double ye = E.y - A.y;
      double eq = E.x - A.x;
      reqAns = sqrt (eq * eq + ye * ye);
    }
  else
    {
      double x1 = AB.x;
      double y1 = AB.y;
      double x2 = AE.x;
      double y2 = AE.y;
      double mod = sqrt (x1 * x1 + y1 * y1);
      reqAns = abs (x1 * y2 - y1 * x2) / mod;
    }

  return reqAns;
}

double
distance (pair < int, int >point, pair < int, int >center)
{
  return sqrt (pow (point.x - center.x, 2) + pow (point.y - center.y, 2));
}
