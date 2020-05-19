#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  float h = 0;
  float x = 0;

  cin >> n >> h;

  for (int i = 1; i < n; i++)
    {
      x = h * sqrt (i / (float) n);
      cout << setprecision (14) << x << " ";
    }

  cout << "\n";

  return 0;
}
