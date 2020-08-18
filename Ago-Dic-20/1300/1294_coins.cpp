#include <bits/stdc++.h>
using namespace std;

bool coins (int, int, int, int);

int
main (void)
{
  int a = 0;
  int b = 0;
  int c = 0;
  int n = 0;
  int t = 0;

  cin >> t;
  while (t--)
    {
      cin >> a >> b >> c >> n;

      if (coins (a, b, c, n))
        cout << "YES";
      else
        cout << "NO";

      cout << "\n";
    }

  return 0;
}

bool
coins (int a, int b, int c, int n)
{
  int missingCoins = 0;

  vector <int> e = {a, b, c};

  sort (e.rbegin (), e.rend ());
  
  missingCoins = (2 * e[0]) - e[1] - e[2];

  if (missingCoins <= n && (n - missingCoins) % 3 == 0)
    return true;
  else
    return false;
}
