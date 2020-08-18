#include <bits/stdc++.h>
using namespace std;

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

      sort (a.rbegin (), a.rend ());

      for (int i = 0; i < n; i++)
        cout << a[i] << " ";

      cout << "\n";
    }

  return 0;
}
