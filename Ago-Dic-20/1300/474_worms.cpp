#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair <int, int>
using namespace std;

int
main (void)
{
  int a = 0;
  int it = 0;
  int n = 0;
  int m = 0;

  vector <int> piles;
  vector <int> res;
  vector <pii> queries;

  cin >> n;

  cin >> a;
  piles.push_back (a);
  for (int i = 1; i < n; i++)
    {
      cin >> a;
      piles.push_back (piles[i - 1] + a);
    }

  cin >> m;
  queries.resize (m);
  res.resize (m);

  for (int i = 0; i < m; i++)
    {
      cin >> queries[i].f;
      queries[i].s = i;
    }

  sort (queries.begin (), queries.end ());

  for (int i = 0; i < m; i++)
    {
      while (queries[i].f > piles[it])
        it++;

      res[queries[i].s] = it + 1;
    }

  for (int i = 0; i < m; i++)
    cout << res[i] << "\n";

  return 0;	
}
