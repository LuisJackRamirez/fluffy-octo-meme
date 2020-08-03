#include <bits/stdc++.h>
using namespace std;

int shovelsSwords (int, int);

int
main (void)
{
  int t = 0;
  int a = 0;
  int b = 0;

  cin >> t;

  while (t--)
    {
      cin >> a >> b;

      cout << shovelsSwords (a, b) << "\n";
    }

  return 0;
}

int
shovelsSwords (int a, int b)
{
  return min (a, min (b, (a + b) / 3));
}
