#include <bits/stdc++.h>
#include <cstdio>
#define pi 2 * asin(1)
using namespace std;

double toRads (double);

int
main (void)
{
  int N = 0;
  double n = 0;
  double l = 0;
  double d = 0;
  double g = 0;

  double angle = 0;
  double An = 0;
  double Ac = 0;
  double Ar = 0;
  double res = 0;

  cin >> N;

  while (N--)
    {
      cin >> n >> l >> d >> g;

      angle = 360 / (2 * n);

      An = (n * l * l)/(4 * tan (toRads (angle)));
      Ar = n * (l * d * g);
      Ac = pi * d * d * g * g;

      res = An + Ar + Ac;

      cout << setprecision (16) << res << "\n";
    }

  return 0;
}

double
toRads (double x)
{
  return (x * (pi / 180));
}
