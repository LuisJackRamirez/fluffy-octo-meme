#include <bits/stdc++.h>
using namespace std;

int badPrices (vector <int> &a, int n);

int
main (void)
{
  int t = 0;
  int n = 0;
  vector <int> a;

  cin >> t;
  while (t--)
    {
      cin >> n;
      a.resize (n);

      for (int i = 0; i < n; i++)
	cin >> a[i];

      cout << badPrices (a, n) << "\n";
    }

  return 0;
}

int
badPrices (vector <int> &a, int n)
{
  int res = 0;
  stack <int> prices;
  
  for (int i = 0; i < n; i++)
    {
      if (prices.empty () != true)
        {
          while (a[i] < prices.top ())
            {
	      prices.pop ();
  	      res++;

	      if (prices.empty () == true)
	        break;
 	    }
        }

      prices.push (a[i]);
    }

  return res;
}
