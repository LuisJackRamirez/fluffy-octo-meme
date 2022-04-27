#include <bits/stdc++.h>
using namespace std;

vector <int>
mergingArrays (vector <int> a, vector <int> b, int n, int m)
{
  vector <int> res;

  int l = 0;
  int r = 0;

  while (l < n && r < m)
    {
      if (a[l] < b[r])
        {
          res.push_back (a[l]);
	  l++;
	}
      else
        {
          res.push_back (b[r]);
	  r++;
	}
    }

  while (l < n)
    {
      res.push_back (a[l]);
      l++;
    }

  while (r < m)
    {
      res.push_back (b[r]);
      r++;
    }

  return res;
}

int
main (void)
{
  int n = 0;
  int m = 0;

  cin >> n >> m;
  vector <int> a (n);
  vector <int> b (m);

  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < m; i++)
    cin >> b[i];

  vector <int> res = mergingArrays (a, b, n, m);

  for (int i = 0; i < n + m; i++)
    cout << res[i] << " ";

  cout << "\n";

  return 0;
}
