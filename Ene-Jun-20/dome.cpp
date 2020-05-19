#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int k = 0;
  double x = 0;
  double y = 0;
  double z = 0;

  multiset <double> clouds;
  multiset <double>::iterator it;

  cin >> n >> k;

  for (int i = 0; i < n; i++)
    {
      cin >> x >> y >> z;

      clouds.insert (sqrt (pow (x, 2) + pow (y, 2) + pow (z, 2)));
    }

  int i = 1;
  it = clouds.begin ();

  while (i < k)
    {
      it++;
      i++;
    }

  cout << setprecision(9) << *it << "\n";

  return 0;
}
