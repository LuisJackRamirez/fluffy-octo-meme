#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int t = 0;
  int r = 0;
  int n = 0;
  int c = 0;
  int m = 0;
  int NW = 0;
  int WS = 0;
  int SE = 0;
  int EN = 0;

  cin >> t;
  while (t--)
    {
      cin >> n >> m >> r >> c;
      NW = c + r - 2;
      WS = c + n - 1 - r;
      SE = n + m - r - c;
      EN = m - c + r - 1;

      cout << max (max (NW, WS), max (SE, EN)) << "\n";
    }

  return 0;
}
