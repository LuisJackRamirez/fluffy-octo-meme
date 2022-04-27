#include <bits/stdc++.h>
#define max_int 10000000
#define f first
#define s second
using namespace std;
  
int ans[max_int + 1];

int
factorize (int n, vector <int> &lp)
{
  int fact = 1;

  while (n > 1)
    {
      int p = lp[n];
      int exp = 0;
      int sum = 1;
      int base = 1;

      while (n % p == 0)
        {
	  n /= p;
	  exp++;
	  base *= p;
	  sum = sum + base;
	}

      fact = fact * sum;
    }

  return fact;
}

vector <int>
shortTask (vector <int> &lp)
{
  vector <int> d (max_int + 1);
  d[1] = 1;

  for (int i = 2; i <= max_int; i++)
    d[i] = factorize (i, lp);

  return d;
}

vector <int>
lowestPrime (int n)
{
  vector <int> lp (n + 1);
  iota (lp.begin (), lp.end (), 0);

  for (int i = 4; i <= n; i += 2)
    lp[i] = 2;

  for (int i = 3; i*i <= n; i += 2)
    {
      if (lp[i] == i)
        {
	  for (int j = i*i; j <= n; j += 2*i)
	    lp[j] = min (lp[j], i);
	}
    }

  return lp;
}

int
main (void)
{
  int t = 0;
  int c = 0;

  vector <int> lp = lowestPrime (max_int);
  vector <int> d = shortTask (lp);

  memset (ans, -1, sizeof (ans));

  for (int i = max_int; i > 0; i--)
    {
      if (d[i] <= max_int)
        ans[d[i]] = i;
    }

  cin >> t;
  while (t--)
    {
      cin >> c;
      cout << ans[c] << "\n";
    }

  return 0;
}
