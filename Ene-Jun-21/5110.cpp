#include<bits/stdc++.h>
using namespace std;

vector <int>
factorize (int n, vector <int> gp)
{
  vector <int> fact;
  
  while (n > 1)
    {
      int p = gp[n];
      
      while (n % p == 0)
        {
	  n /= p;
          fact.push_back (p);
	}
    }

  return fact;
}

int
squareFreeNums (int n, vector <int> &gp)
{
  int res = 0;

  while (n > 1)
    {
      int p = gp[n];
      int exp = 0;
      
      while (n % p == 0)
        {
	  exp++;
	  res = max (res, exp);
	  n /= p;
	}
    }

  return res;
}

vector <int>
greatestPrime (int n)
{
  vector <int> gp (n + 1);
  iota (gp.begin (), gp.end (), 0);

  for (int i = 2; i <= n; i++)
    {
      if (gp[i] == i)
        {
	  for (int j = 2*i; j <= n; j += i)
	    gp[j] = i;
	}
    }

  return gp;
}

int
main (void)
{
  int t = 0;
  int n = 0;
  vector <int> gp = greatestPrime (1e6);

  cin >> t;
  while (t--)
    {
      cin >> n;
      cout << squareFreeNums (n, gp) << "\n";
    }

  return 0;
}
