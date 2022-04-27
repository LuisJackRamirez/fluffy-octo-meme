#include <bits/stdc++.h>
#define max_int 31622
using namespace std;

vector <int> primes;

vector <int>
getPrimes (int n)
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

long long int 
factorize (int n, vector <int> &primes)
{
  long long fact = 1;

  for (int p : primes)
    {
      if (n % p == 0)
        {
	  int exp = 0;
	  while (n % p == 0)
	    {
	      n /= p;
	      exp++;
	    }

	  fact = fact * ((long long) exp + 1);
	}
    }

  return fact;
}

bool
isNDivisorNum (int a, int n)
{
  long long fact = factorize (a, primes);

  return fact == n;
}

int
main (void)
{
  int a = 0;
  int b = 0;
  int n = 0;
  int res = 0;

  ios_base::sync_with_stdio (false);
  cin.tie (NULL);

  primes = getPrimes (max_int);
  cin >> a >> b >> n;

  for (int i = a; i <= b; i++)
    {
      if (isNDivisorNum (i, n))
	res++;
    }

  cout << res << "\n";
  return 0;
}
