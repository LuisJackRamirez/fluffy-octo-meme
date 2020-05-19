#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int k = 0;
  int l = 0;
  int c = 0;
  int d = 0;
  int p = 0;
  int nl = 0;
  int np = 0;
  int res = 0;

  cin >> n >> k >> l >> c >> d >> p >> nl >> np;

  res = min ((k * l) / nl, min (c * d, p / np)) / n;

  cout << res << "\n";

  return 0;
}
