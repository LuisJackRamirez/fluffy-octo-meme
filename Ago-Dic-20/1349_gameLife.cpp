#include <bits/stdc++.h>
using namespace std;

int query (vector <string> &, int);

int
main (void)
{
  int i = 0;
  int j = 0;
  int p = 0;
  int n = 0;
  int m = 0;
  int t = 0;

  string str;
  vector <string> strings;

  cin >> n >> m >> t;
  for (int l = 0; l < n; l++)
    {
      cin >> str;
      strings.push_back (str);
    }

  vector <vector <bool>> states (n, vector <bool> (m));
  for (int l = 0; l < n; l++)
    {
      for (int k = 0; k < m; k++)
        states[l][k] = isGood (strings, n, m);
    }

  while (t--)
    {
      cin >> i >> j >> p;

      cout << query (strings, p) << "\n";
    }

  return 0;
}

int
query (vector <string> &strings, int p)
{
  int res = 0;

  return res;
}
