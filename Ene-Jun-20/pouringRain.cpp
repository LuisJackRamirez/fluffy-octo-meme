#include <bits/stdc++.h>
#define pi 2 * asin (1)
using namespace std;

int
main (void)
{
  float d = 0;
  float descent = 0;
  float h = 0;
  float height = 0;
  float v = 0;
  float e = 0;
  double t = 0;

  cin >> d >> h >> v >> e;

  height = 4 * v / (d * d * pi);

  descent = height - e;

  if (descent <= 0)
    cout << "NO\n";
  else
    {
      cout << "YES\n";
      t = h / descent;
      cout << setprecision (16) << t << "\n";
    }

  return 0;
}
