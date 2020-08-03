#include <bits/stdc++.h>
#define pi 2 * asin (1)
using namespace std;

int score (vector < pair < double, double >>, double, double, double, double);

int
main (void)
{
  int n = 0;
  int w = 0;
  int b = 0;
  int d = 0;
  int s = 0;
  int t = 0;
  vector < pair < double, double >>darts;

  cin >> n;
  while (n--)
    {
      cin >> w >> b >> d >> s;

      cin >> t;
      darts.resize (t);

      for (int i = 0; i < t; i++)
	cin >> darts[i].first >> darts[i].second;

      cout << score (darts, w, b, d, s) << "\n";
    }

  return 0;
}

int
score (vector < pair < double, double >>darts, double w, double b, double d,
       double s)
{
  double distance = 0;
  double segment = 0;
  double angle = 0;
  double dot = 0;
  double det = 0;
  int region = 0;		//1. single ring; 2. double ring
  int res = 0;

  for (int i = 0; i < darts.size (); i++)
    {
      distance = sqrt (pow (darts[i].first, 2) + pow (darts[i].second, 2));

      if (distance > s)
	res = res + 0;
      else if (distance < b)
	res = res + 50;
      else
	{
	  if (distance > b && distance < d)
	    region = 2;
	  else if (distance > d && distance < s)
	    region = 1;

	  angle = acos (darts[i].second / distance);
	  if (darts[i].second < 0)
	    angle = pi + angle;

	  segment = (2 * pi) / w;

	  res = res + (((int) (angle / segment) + 1) * region);
	}
    }

  return res;
}
