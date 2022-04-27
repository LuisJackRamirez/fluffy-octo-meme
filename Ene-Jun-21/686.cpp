#include <bits/stdc++.h>
#include <cstdio>
#define max_int 32768
using namespace std;

vector <int> primes;

vector <int>
getPrimes (int n)
{
  vector <bool> is (n + 1, true);
  primes.push_back (2);
  is[0] = is[1] = false;

  for (int i = 4; i <= n; i += 2)
    is[i] = false;

  for (int i = 3; i <= n; i += 2)
    {
      if (is[i])
        {
	  primes.push_back (i);
	  if ((long long) i*i <= n)
	    {
	      for (long long int j = i*i; j <= n; j += 2*i)
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
  int res = 0;

  primes = getPrimes (max_int);
  while (cin >> n && n != 0)
    {
      int l = 0;
      int r = primes.size () - 1;
      res = 0;

      while (l <= r)
        {
	  if (primes[r] + primes[l] > n)
	    r--;
	  else if (primes[r] + primes[l] < n)
	    l++;
	  else
	    {
	      l++;
	      r--;
	      res++;
	    }
	}

      cout << res << "\n";
    }

  return 0;
}
