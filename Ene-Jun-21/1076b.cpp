#include <bits/stdc++.h>
#define lli long long int
using namespace std;

bool
isPrime (lli n, vector <int> &primes)
{
  if (n == 1)
    return false;

  for (int p : primes)
    {
      if ((long long) p*p > n)
        break;

      if (n % p == 0)
        return false;
    }

  return true;
}

vector <int>
sieve (int n)
{
  vector <bool> is (n + 1, true);
  vector <int> primes = {2};
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

int
main (void)
{
  lli n = 0;
  lli res = 0;

  vector <int> primes = sieve (1e5);

  cin >> n;

  while (n != 0)
    {
      if (n % 2 == 0)
        {
	  res = res + (n / 2);
	  break;
	}
      else if (isPrime (n, primes))
        {
	  res++;
	  break;
	}
      else
	{
	  for (int i : primes)
	    {
	      if (n % i == 0)
	        {
		  n = n - i;
		  res++;
		  break;
		}
	    }
	}
    }

  cout << res << "\n";
  return 0;
}
