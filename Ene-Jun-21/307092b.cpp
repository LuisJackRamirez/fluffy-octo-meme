#include <bits/stdc++.h>
using namespace std;

vector <int>
numberOfSmaller (vector <int> a, vector <int> b, int n, int m)
{
  int l = 0;
  int r = 0;

  vector <int> res;

  for (r = 0; r < m; r++)
    {
      while (l < n && a[l] < b[r])
        l++;

      res.push_back (l);
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

  vector <int> res = numberOfSmaller (a, b, n, m);

  for (int i = 0; i < res.size (); i++)
    cout << res[i] << " ";

  cout << "\n";

  return 0;
}
