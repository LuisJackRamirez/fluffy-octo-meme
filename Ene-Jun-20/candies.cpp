#include <bits/stdc++.h>
#define lli long long int
using namespace std;

long long int getCandies (int);

int
main (void)
{
  int n = 0;
  int t = 0;
  lli res = 0;

  cin >> t;

  while (t--)
    {
      cin >> n;

      res = getCandies (n);

      cout << res << "\n";
    }

  return 0;
}

long long int
getCandies (int n)
{
  long long int den = 0;
  long long int lastSum = 0;

  lastSum = 2;
  den = 3;

  if (n % den == 0)
    return n / den;
  else
    {
      while (n % den != 0)
        {
	  lastSum = lastSum * 2;
	  den = den + lastSum;
	}

      return n / den;
    }
}
