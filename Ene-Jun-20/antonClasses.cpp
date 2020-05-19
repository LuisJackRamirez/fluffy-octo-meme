#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int closestLC = 0;
  int farthestLC = 0;
  int closestRC = 0;
  int farthestRC = 0;
  int closestLP = 0;
  int farthestLP = 0;
  int closestRP = 0;
  int farthestRP = 0;
  int l = 0;
  int m = 0;
  int n = 0;
  int r = 0;
  int resA = 0;
  int resB = 0;

  cin >> n;

  for (int i = 0; i < n; i++)
    {
      cin >> l >> r;

      if (l < closestLC || closestLC == 0)
        closestLC = l;
      if (l > farthestLC)
        farthestLC = l;

      if (r < closestRC || closestRC == 0)
        closestRC = r;
      if (r > farthestRC)
        farthestRC = r;
    }

  cin >> m;

  for (int i = 0; i < m; i++)
    {
      cin >> l >> r;

      if (l < closestLP || closestLP == 0)
        closestLP = l;
      if (l > farthestLP)
        farthestLP = l;

      if (r < closestRP || closestRP == 0)
        closestRP = r;
      if (r > farthestRP)
        farthestRP = r;
    }

  resA = closestRC - closestLP;
  if (resA < 0)
    resA = 0;

  resB = closestRP - closestLC;
  if (resB < 0)
    resB = 0;

  cout << max (resA, resB) << "\n";
  
  return 0;
}
