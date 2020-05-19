#include <bits/stdc++.h>
using namespace std;

int maxMoney (vector <int> &, int);

int
main (void)
{
  int n = 0;
  int m = 0;
  int res = 0;

  vector <int> prices;

  cin >> n >> m;
  prices.resize (n);

  for (int i = 0; i < n; i++)
    cin >> prices[i];

  res = maxMoney (prices, m);

  cout << res << "\n";

  return 0;
}

int
maxMoney (vector <int> &prices, int m)
{
  int sum = 0;

  sort (prices.begin (), prices.end ());

  for (int i = 0; i < m; i++)
    {
      if (sum + prices[i] < sum)
        sum = sum + prices[i];
    }

  return -sum;
}
