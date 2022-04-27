#include <bits/stdc++.h>
#define f first
#define s second
#define max_int 1e6
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

void
notSoFlat (int a, int b, vector <int> &lp, int i)
{
  int sum = 0;
  map <int, int> factA = factorize (a, lp);
  map <int, int> factB = factorize (b, lp);
  map <int, int> res = factA;

  for (auto i : factB)
    {
      if (res.find (i.f) == res.end ())
        res[i.f] = i.s;
      else
	res[i.f] = abs (res[i.f] - i.s);
    }

  for (auto i : res)
    sum = sum + i.s;

  printf ("%d. %lu:%d\n", i, res.size (), sum);
  return;
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
  int a = 0;
  int b = 0;
  int i = 0;

  vector <int> lp = lowestPrime (max_int);

  while (cin >> a >> b && (a != 0 && b != 0))
    notSoFlat (a, b, lp, ++i);

  return 0;
}
