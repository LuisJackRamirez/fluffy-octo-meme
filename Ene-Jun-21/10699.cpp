#include <bits/stdc++.h>
#define max_int 46340
using namespace std;

vector <int>
getPrimes (int n)
{
  vector <bool> is (n + 1, true);
  vector <int> primes;
  primes.push_back (2);
  is[1] = is[1] = false;

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
	        {
		  if (j == 295129)
		    cout << i << "\n";

	          is[j] = false;
		}
	    }
	}
    }

  return primes;
}

int
main (void)
{
  int n = 0;
  vector <int> primes;

  ios_base::sync_with_stdio (false);
  cin.tie (NULL);

  primes = getPrimes (1000000);
  while (1)
    {
      int i = 0;
      int res = 0;
      cin >> n;

      if (n == 0)
        break;

      for (int i : primes)
        {
	  if (n % i == 0)
	    res++;
	}

      cout << n << " : " << res << "\n";
    }

  return 0;
}
