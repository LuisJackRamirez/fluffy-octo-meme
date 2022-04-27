#include <bits/stdc++.h>
using namespace std;

vector <bool>
sieve (int n)
{
  vector <bool> is (n + 1, true);
  is[0] = is[1] = false;

  for (int i = 4; i <= n; i += 2)
    is[i] = false;

  for (int i = 3; i*i <= n; i += 2)
    {
      if (is[i])
        {
	  for (int j = i*i; j <= n; j += 2*i)
	    is[j] = false;
	}
    }

  return is;
}

int
main (void)
{
  int n = 0;

  cin >> n;
  vector <bool> primes = sieve (1e6);

  int l = 4;
  int r = n - 4;

  while (l <= r)
    {
      if (!primes[l] && !primes[r])
        {
          cout << l << " " << r << "\n";
	  return 0;
	}

      l++;
      r--;
    }

  return 0;
}
