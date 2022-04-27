/*
 * Codeforces 101490i - Older Brother
 */

#include <bits/stdc++.h>
#define max_int 46341
#define epsilon 1e-9
using namespace std;

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

	  if ((long long) i*i <= n)
	    {
	      for (int j = i*i; j <= n; j += 2*i)
	        is[j] = false;
	    }
	}
    }

  return primes;
}

bool
olderBrother (int q)
{
  vector <int> primes = getPrimes (max_int);
  
  for (int i : primes)
    {
      if (i > q)
        return false;

      if (q % i == 0)
        {
	  while (q % i == 0)
	    q /= i;

	  return q == 1;
	}
    }

  return true;
}

int
main (void)
{
  int q = 0;

  cin >> q;
  if (olderBrother (q))
    cout << "yes\n";
  else
    cout << "no\n";
  
  return 0;
}
