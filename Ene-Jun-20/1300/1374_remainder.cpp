#include <bits/stdc++.h>
using namespace std;

int requiredRemainder (int, int, int);

int
main (void)
{
  int x = 0;
  int y = 0;
  int n = 0;
  int t = 0;
  int k = 0;

  cin >> t;

  while (t--)
    {
      cin >> x >> y >> n;
      
      k = requiredRemainder (x, y, n);
      cout << k << "\n";
    }

  return 0;
}

int
requiredRemainder (int x, int y, int n)
{
  int res = 0;

  res = n % x;

  if (res == y)
    return n;
  else if (res > y)
    return n - (res - y);
  else if (res < y)
    return n + (y - res) - x;
}
