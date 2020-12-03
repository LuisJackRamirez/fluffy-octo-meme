#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int i = 0;
  int init = 0;
  int n = 0;
  int m = 0;
  int limit = 0;

  queue <int> baskets;

  cin >> n >> m;

  i = 1;
  init = (m + 1) / 2;
  baskets.push (init);
  limit = ceil ((double) m / (double) 2);

  for (int j = 1; j < limit; j++)
    {
      baskets.push (init - i);
      baskets.push (init + i);
      i++;
    }

  while (n--)
    {
      cout << baskets.front () << "\n";
      baskets.push (baskets.front ());
      baskets.pop ();
    }

  return 0;
}
