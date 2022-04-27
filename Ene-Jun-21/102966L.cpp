#include <bits/stdc++.h>
#define lli long long int
#define max_int 10000000
using namespace std;

vector <int> lp;

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

map <int, int>
factorize (int n)
{
  map<int, int> fact;

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

int
letsCountFactors (int a, int b)
{
  map <int, int> aFact = factorize (a); 
  map <int, int> bFact = factorize (b);
  set <int> s;

  for (auto i : aFact)
    s.insert (i.first);
  
  for (auto i : bFact)
    s.insert (i.first);

  return s.size ();
}

int
main (void)
{
  int n = 0;
  lli a = 0;
  lli b = 0;
  int t = 0;

  ios_base::sync_with_stdio (false);
  cin.tie (NULL);

  lp = lpSieve (max_int);

  cin >> t;
  while (t--)
    {
      cin >> a >> b;
      cout << letsCountFactors (a, b) << "\n";
    }

  return 0;
}
