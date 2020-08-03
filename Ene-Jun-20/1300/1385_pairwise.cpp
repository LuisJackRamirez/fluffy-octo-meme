#include <bits/stdc++.h>
using namespace std;

bool pairwiseMax (int, int, int);

int
main (void)
{
  int t = 0;
  int x = 0;
  int y = 0;
  int z = 0;

  cin >> t;
  while (t--)
    {
      cin >> x >> y >> z;

      if (pairwiseMax (x, y, z))
      	continue;
      else
        cout << "NO\n";
    }

  return 0;
}

bool
pairwiseMax (int x, int y, int z)
{
  if (x == y && x >= z)	
    {
      
      cout << "YES\n" << x << " " << z << " " << z << "\n";
      return true;
    }
  else if (x == z && x >= y)
    {
      cout << "YES\n" << x << " " << y << " " << y << "\n";
      return true;
    }
  else if (y == z && y >= x)
    {
      cout << "YES\n" << y << " " << x << " " << x << "\n";
      return true;
    }
  else
    return false;
}
