#include <bits/stdc++.h>
#include <cmath>
using namespace std;

bool sqrtIsInt (int);
int pairsOfSolutions (int, int);

int
main (void)
{
  int n = 0;
  int m = 0;
  int res = 0;

  cin >> n >> m;

  res = pairsOfSolutions (n, m);

  cout << res << "\n";

  return 0;
}

bool
sqrtIsInt (int z)
{
  if (sqrt (z) - (int) sqrt (z) == 0)
    return true;
}

int
pairsOfSolutions (int n, int m)
{
  int a = 0;
  int b = 0;
  int res = 0;

  for (b = 0; b <= n; b++)
    {
      a = n - b;

      if (sqrtIsInt (a) && b * b == m - sqrt (a))
        res++;
    }

  return res;
}
