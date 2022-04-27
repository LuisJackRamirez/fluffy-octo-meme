#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

vector <int> primes;

vector <int>
getPrimes (int n)
{
  vector <bool> is (n + 1, true);
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

  primes = getPrimes (1000000);
  while (cin >> n && n != 0)
    {
      int l = 0;
      int r = primes.size () - 1;

      while (l <= r)
        {
	  if (primes[r] + primes[l] > n)
	    r--;
	  else if (primes[r] + primes[l] < n)
	    l++;
	  else
	      break;
	}
     
      if (primes[r] + primes[l] == n)
        printf ("%d = %d + %d\n", n, primes[l], primes[r]);
      else
        cout << "Goldbach's conjecture is wrong.\n";
    }

  return 0;
}
