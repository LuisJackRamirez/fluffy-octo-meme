#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int k = 0;
  int l = 0;
  int m = 0;
  int n = 0;
  int d = 0;
  int res = 0;

  cin >> k >> l >> m >> n >> d;

  if (k == 1 || l == 1 || m == 1 || n == 1)
    {
      cout << d << "\n";
      return 0;
    }

  for (int i = 1; i <= d; i++)
    {
      if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0)
        res++;
    }

  cout << res << "\n";

  return 0;
}
