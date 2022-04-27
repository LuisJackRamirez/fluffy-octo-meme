#include <bits/stdc++.h>
#define max_int 1000
using namespace std;

vector <int> lp;

bool
isLucky (int n)
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

      if (fact.size () >= 3)
        return true;
    }

  return false;
}

vector <int>
luckyNumbers (int n)
{
  int i = 30;
  vector <int> luckys = {0};

  while (luckys.size () <= n)
    {
      if (isLucky (i))
        luckys.push_back (i);

      i++;
    }

  return luckys;
}

vector <int>
lowestPrimes (int n)
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
  int n = 0;
  int t = 0;

  lp = lowestPrimes (1e6);
  vector <int> luckys = luckyNumbers (max_int);

  cin >> t;
  while (t--)
    {
      cin >> n;
      cout << luckys[n] << "\n";
    }

  return 0;
}
