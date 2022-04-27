#include <bits/stdc++.h>
using namespace std;

long long
minInteger (int l, int r, int d)
{
  int res = 0;
  long long int i = 0;

  if (d < l || d > r)
    return d;

  i = (r / d) + 1;

  return d * i;
}

int
main (void)
{
  int q = 0;
  int l = 0;
  int r = 0;
  int d = 0;
  
  cin >> q;
  while (q--)
    {
      cin >> l >> r >> d;
      cout << minInteger (l, r, d) << "\n";
    }

  return 0;
}
