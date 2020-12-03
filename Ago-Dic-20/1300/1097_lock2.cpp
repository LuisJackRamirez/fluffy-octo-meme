#include <bits/stdc++.h>
using namespace std;

bool lock (vector <int> &, int, int);

int
main (void)
{
  int n = 0;
  vector <int> a;

  cin >> n;
  a.resize (n);

  for (int i = 0; i < n; i++)
    cin >> a[i];

  if (lock (a, 0, 0))
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}

bool
lock (vector <int> &a, int sum, int i)
{
  if (i == a.size () - 1)
    {
      if ((sum + a[i]) % 360 == 0 || (sum - a[i]) % 360 == 0)
        return true;
      else
        return false;
    }

  if (lock (a, sum + a[i], i + 1) || lock (a, sum - a[i], i + 1))
    return true;
  else
    return false;
}
