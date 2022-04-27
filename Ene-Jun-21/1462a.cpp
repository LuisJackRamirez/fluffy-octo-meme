#include <bits/stdc++.h>
using namespace std;

vector <int>
favoriteSequence (vector <int> a, int n)
{
  int l = 0;
  int r = 0;
  vector <int> res;

  r = n - 1;
  while (l < r)
    {
      res.push_back (a[l++]);
      res.push_back (a[r--]);
    }

  if (n % 2 == 1)
    res.push_back (a[l]);

  return res;
}

int
main (void)
{
  int t = 0;
  int n = 0;

  cin >> t;
  while (t--)
    {
      cin >> n;
      vector <int> sequence (n);

      for (int i = 0; i < n; i++)
        cin >> sequence[i];

      vector <int> res = favoriteSequence (sequence, n);

      for (int i = 0; i < n; i++)
        cout << res[i] << " ";

      cout << "\n";
    }

  return 0;
}
