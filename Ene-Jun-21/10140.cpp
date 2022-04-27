#include <bits/stdc++.h>
#include <cstdio>
#define MAX_INT 46340		//(2^31 - 1)
#define f first
#define s second
using namespace std;

vector < int >
getPrimes (long int n)
{
  vector < bool > is (n + 1, true);
  vector < int >primes = { 2 };
  is[0] = is[1] = false;

  for (long int i = 4; i <= n; i += 2)
    is[i] = false;

  for (long int i = 3; i <= n; i += 2)
    {
      if (is[i])
	{
	  primes.push_back (i);
	  if ((long long) i * i <= n)
	    {
	      for (long int j = i * i; j <= n; j += 2 * i)
		is[j] = false;
	    }
	}
    }

  return primes;
}

bool
isPrime (int n, vector < int >primes)
{
  if (n == 1)
    return false;

for (int p:primes)
    {
      if ((long long) p * p > n)
	break;

      if (n % p == 0)
	return false;
    }

  return true;
}

int
main (void)
{
  int l = 0;
  int u = 0;
  int min = std::numeric_limits < int >::max ();
  int max = 0;
  vector < int >primes;

  //ios_base::sync_with_stdio (false);
  //cin.tie (NULL);

  primes = getPrimes (MAX_INT);
  while (cin >> l >> u)
    {
      int min = std::numeric_limits < int >::max ();
      int max = 0;
      pair <int, int> maxRes = {-1, -1};
      pair <int, int> minRes = {-1, -1};

      int prev = -1;
      for (long int i = l; i <= u; i++)
	{
	  if (isPrime (i, primes))
	    {
	      if (prev != -1)
	        {
		  if (i - prev < min)
		    {
		      min = i - prev;
		      minRes.f = prev;
		      minRes.s = i;
		    }
		  
		  if (i - prev > max)
		    {
		      max = i - prev;
		      maxRes.f = prev;
		      maxRes.s = i;
		    }
		}

	      prev = i;
	    }
	}

      if (maxRes.f == -1 || minRes.f == -1)
        printf ("There are no adjacent primes.\n");
      else
        printf ("%d,%d are closest, %d,%d are most distant.\n", 
		      minRes.f, minRes.s, maxRes.f, maxRes.s);
    }

  return 0;
}
