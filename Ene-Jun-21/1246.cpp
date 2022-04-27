#include <bits/stdc++.h>
using namespace std;

map <int, int>
factorize (int n, vector <int> lp)
{
  map <int, int> fact;

  while (n > 1)
    {
      int p = lp[n];
      int exp = 0;

      while (n % p == 0)
        {
          n /= p;
	  exp++;
	}

      fact[p] = exp;
    }

  return fact;
}

vector <int>
lpSieve (int n)
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
  int l = 0;
  int h = 0;
  int numFactors = 0;
  bool flag = false;

  vector <int> lp = lpSieve (10000);

  cin >> t;
  while (t--)
    {
      vector <int> res;
      flag = false;
      cin >> l >> h;

      for (int i = l; i <= h; i++)
        {
          numFactors = 1;
	  map <int, int> fact = factorize (i, lp);

	  for (auto it : fact)
	    numFactors = numFactors * (it.second + 1);

	  if (numFactors != 1 && numFactors == lp[numFactors])
	    res.push_back (i);
	}

      if (res.size () == 0)
        cout << "-1";
      else
        {
	  for (int i = 0; i < res.size (); i++)
	    {
	      cout << res[i];
	      if (i < res.size () - 1)
	        cout << " ";
	    }
	}

      cout << "\n";
    }

  return 0;
}
