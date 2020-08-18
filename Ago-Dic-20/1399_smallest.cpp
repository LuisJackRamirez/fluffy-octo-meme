#include <bits/stdc++.h>
using namespace std;

bool smallest (vector <int>);

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

      sort (a.begin (), a.end ());

      if (smallest (a))
        cout << "YES\n";
      else
        cout << "NO\n";
    }

  return 0;
}

bool
smallest (vector <int> a)
{
  for (int i = 1; i < a.size (); i++)
    {
      if (a[i] - a[i - 1] > 1)
        return false;
    }

  return true;
}
