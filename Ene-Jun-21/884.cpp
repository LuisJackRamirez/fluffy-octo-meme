#include <bits/stdc++.h>
#include <cstdio>
#define max_int 1000000
using namespace std;

vector <int> primes;

int
legendre (int n, int p)
{
  int sum = 0;
  int term = n / p;
  
  while (term > 0)
    {
      sum = sum + term;
      term = term / p;
    }
  
  return sum;
}

int
factorialFactors (int n)
{
  map <int, int> factor;
  int sum = 0;

  for (int p : primes)
    {
      if (p > n)
        break;

      sum = sum + legendre (n, p);
    }

  return sum;
}

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

  ios_base::sync_with_stdio (false);
  cin.tie (NULL);

  primes = getPrimes (max_int);
  while (scanf ("%d", &n) != EOF)
    cout << factorialFactors (n) << "\n";

  return 0;
}
