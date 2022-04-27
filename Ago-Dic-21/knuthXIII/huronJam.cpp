#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int sum = 0;
  int x = 0;
  int y = 0;

  cin >> n;

  for (int i = 0; i < n; i += 2)
    {
      cin >> x >> y;
      sum = sum + (y - x);
    }

  cout << sum << "\n";

  return 0;
}
