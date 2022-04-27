#include <bits/stdc++.h>
#define lli long long int
#define max_int 1e6
using namespace std;

bool
tPrimes (lli x, vector <int> &primes)
{
  int l = 0;
  int r = primes.size () - 1;
  int m = 0;

  while (l <= r)
    {
      m = l + ((r - l) / 2);
      lli res = (lli) primes[m] * (lli) primes[m];

      if (res == x)
        return true;
      else if (res < x)
        l = m + 1;
      else
        r = m - 1;
    }


  return false;
}

vector <int>
getPrimes (int n)
{
  vector <int> primes = {2};
  vector <bool> is (n + 1, true);
  is[0] = is[1] = false;

  for (int i = 4; i <= n; i += 2)
    is[i] = false;

  for (int i = 3; i <= n; i += 2)
    {
      if (is[i])
        {
	  primes.push_back (i);

	  if ((lli) i*i <= n)
	    {
	      for (lli j = i*i; j <= (lli) n; j += 2*i)
	        is[j] = false;
	    }
	}
    }

  return primes;
}

int
main (void)
{
  int n = 0;
  lli x = 0;

  vector <int> primes = getPrimes (max_int);

  cin >> n;
  for (int i = 0; i < n; i++)
    {
      cin >> x;
      if (tPrimes (x, primes))
        cout << "YES\n";
      else
        cout << "NO\n";
    }

  return 0;
}
