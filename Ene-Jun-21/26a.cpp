#include <bits/stdc++.h>
using namespace std;

bool
almostPrime (int n)
{
  int res = 0;

  for (int p = 2; p*p <= n; p++)
    {
      if (n % p == 0)
        {
	  while (n % p == 0)
	    n /= p;

	  res++;
	}
    }

  if (n > 1)
    res++;

  return res == 2;
}

int
main (void)
{
  int n = 0;
  int res = 0;

  cin >> n;
  for (int i = 1; i <= n; i++)
    {
      if (almostPrime (i))
        res++;
    }

  cout << res << "\n";

  return 0;
}
