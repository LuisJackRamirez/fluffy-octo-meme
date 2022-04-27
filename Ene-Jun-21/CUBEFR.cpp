#include <bits/stdc++.h>
#define max_int 1e6
using namespace std;

bool
isCubeFree (int n, vector <int> &lp)
{
  while (n > 1)
    {
      int p = lp[n];
      int exp = 0;
      
      while (n % p == 0)
        {
	  n /= p;
	  exp++;

	  if (exp == 3)
	    return false;
	}
    }

  return true;
}

vector <int>
cubeFreeNumbers (int n, vector <int> &lp)
{
  vector <int> cubeFree = {0};
  int position = 1;

  for (int i = 1; i <= n; i++)
    {
      if (isCubeFree (i, lp))
        cubeFree.push_back (position++);
      else
        cubeFree.push_back (-1);
    }

  return cubeFree;
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
  int n = 0;
  int i = 1;

  vector <int> lp = lowestPrime (max_int);
  vector <int> cubeFree = cubeFreeNumbers (max_int, lp);
  
  cin >> t;
  fflush (stdin);
  while (t--)
    {
      cin >> n;

      printf ("Case %d: ", i++);
      if (cubeFree[n] == -1)
        printf ("Not Cube Free\n");
      else
        printf ("%d\n", cubeFree[n]);
    }

  return 0;
}
