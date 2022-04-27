#include <bits/stdc++.h>
#define max_int 1299709
using namespace std;

bool
isPrime (int n, vector <int> primes)
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
	  if ((long long) i * i <= n)
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
  int n = 0;
  vector <int> primes;

  primes = getPrimes (max_int);

  while (cin >> n && n != 0)
    {
      if (isPrime (n, primes) == true)
        cout << "0\n";
      else
        {
          for (int i = 0; i < primes.size (); i++)
            {
 	      if (primes[i] > n)
	        {
	          cout << primes[i] - primes[i - 1] << "\n";
		  break;
		}
	    }
	}
    }

  return 0;
}
