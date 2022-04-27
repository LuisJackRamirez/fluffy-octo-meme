#include <bits/stdc++.h>
using namespace std;

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

  vector <int> lp = lowestPrimes (1e7);
  vector <long long int> aps = {0, 0};
 
  for (int i = 2; i <= 1e7; i++)
    aps.push_back (aps[i - 1] + lp[i]);

  cin >> t;
  while (t--)
    {
      cin >> n;
      cout << aps[n] << "\n";
    }

  return 0;
}
