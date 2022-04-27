#include <bits/stdc++.h>
using namespace std;

int
fourSegments (vector <int> a)
{
  sort (a.begin (), a.end ());

  return min (a[0], a[1]) * min (a[2], a[3]);
}

int
main (void)
{
  int t = 0;
  vector <int> a (4);

  cin >> t;
  while (t--)
    {
      for (int i = 0; i < 4; i++)
        cin >> a[i];

      cout << fourSegments (a) << "\n";
    }

  return 0;
}
