#include <bits/stdc++.h>
#define max_int 46341
using namespace std;

vector <long int> primes;

vector <long int>
getPrimes (int n)
{
  vector <bool> is (n + 1, true);

  primes.push_back (2);
  is[0] = is[1] = false;

  for (int i = 4; i <= n; i += 2)
    is[i] = false;

  for (long int i = 3; i <= n; i += 2)
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
gcd (int a, int b)
{
  if (b == 0)
    return abs (a);
  else
    return gcd (b, a % b);
}

int
perfectPPower (long int n)
{
  int res = 0;
  long int temp = n;

  if (n < 0)
    n *= -1;

  for (int i = 0; primes[i] * primes[i] <= n; i++)
    {
      int exponent = 0;
      
      while (n % primes[i] == 0)
        {
	  exponent++;
	  n /= primes[i];
	}

      if (exponent != 0)
        {
	  if (res == 0)
	    res = exponent;
	  else
	    res = gcd (res, exponent);
	}
    }

  if (n != 1)
    res = 1;

  if (temp < 0)
    {
      while (!(res & 1))
        res /= 2;
    }

  return res;
}

int
main (void)
{
  int n = 0;

  primes = getPrimes (max_int);
  while (cin >> n && n)
    {
      cout << perfectPPower (n) << "\n";
    }

  return 0;
}
