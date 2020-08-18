#include <bits/stdc++.h>
using namespace std;

int twoCakes (int, int, int);
bool check (int, int, int);

int
main (void)
{
  int n = 0;
  int a = 0;
  int b = 0;
  int res = 0;

  cin >> n >> a >> b;

  res = twoCakes (n, a, b);

  cout << res << "\n";

  return 0;	
}

int
twoCakes (int n, int a, int b)
{
  int l = 0;
  int m = 0;
  int r = 0;
  int res = 0;

  if (n == a + b)
    return 1;

  r = a + b;

  while (l <= r)
    {
      m = l + (r - l) / 2;

      if (check (m, a, b))
        {
	  res = m;
	  l = m + 1;
	}
      else
        r = m - 1;
    }

  return res;
}

bool
check (int x, int a, int b)
{
  if (a / x > 1 && b / x > 1)
    return true;
  else
    return false;
}
