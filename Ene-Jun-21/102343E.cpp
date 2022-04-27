#include <bits/stdc++.h>
#define max_int 2*1000000
using namespace std;

bool
isSolution (int n, vector <int> &primes)
{
  for (int i : primes)
    {
      if (n % i == 0)
        return false;
    }

  return true;
}

int
giveAGnocchi (int n, int k)
{
  int lastPrime = 2;
  vector <int> primes = {2};
  vector <bool> is (max_int + 1, true);
  is[0] = is[1] = false;

  for (int i = 4; i <= max_int; i += 2)
    is[i] = false;

  for (int i = 3; i <= max_int; i += 2)
    {
      if (is[i])
        {
	  primes.push_back (i);

	  if ((long long) i*i <= max_int)
	    {
	      for (int j = i*i; j <= max_int; j += 2*i)
	        is[j] = false;
	    }
	}
    }

  int i = 0;
  while (primes[i] <= n)
    i++;

  int firstComposite = primes[i] * primes[i];
  k--;
  primes.resize (i);
  i = firstComposite;
  while (k > 0)
    {
      i++;
      if (is[i] == false && isSolution (i, primes))
	k--;
    }

  return i;
}

int
main (void)
{
  int n = 0;
  int k = 0;

  cin >> n >> k;
  cout << giveAGnocchi (n, k) << "\n";

  return 0;
}
