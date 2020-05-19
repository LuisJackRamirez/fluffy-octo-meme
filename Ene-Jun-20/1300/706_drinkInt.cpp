#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int q = 0;
  int res = 0;
  
  map <int, int> results;
  map <int, int> order;
  vector <int> prices;
  vector <int> coins;

  cin >> n;
  prices.resize (n);

  for (int i = 0; i < n; i++)
    cin >> prices[i];

  sort (prices.begin (), prices.end ());

  cin >> q;
  coins.resize (q);

  for (int i = 0; i < q; i++)
    {
      cin >> coins[i];

      order.insert (make_pair (i, coins[i]));
    }

  sort (coins.begin (), coins.end ());

  int j = 0;

  for (int i = 0; i < q; i++)
    {
      while (prices[j] <= coins[i] && j < n)
	j++;

      results.insert (make_pair (coins[i], j));
      res = 0;
    }

  for (int i = 0; i < q; i++)
    cout << results.find (order.find (i)->second)->second << "\n";
 
  return 0;
}
