#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int
main (void)
{
  int t = 0;
  double a = 0;
  lli i = 0;
  lli x = 0;
  lli y = 0;
  lli k = 0;
  lli res = 0;

  cin >> t;
  while (t--)
    {
      cin >> x >> y >> k;

      a = (((double) k / (double) (x - 1)) * (double) y);
      a = a + ((double) (k - 1) / (double) (x - 1));
      i = ceil (a);
      res = i + k;
      cout << res << "\n";
    }

  return 0;
}
