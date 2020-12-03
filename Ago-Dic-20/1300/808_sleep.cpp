#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  double finale = 0;
  int k = 0;
  int l = 0;
  int n = 0;
  int r = 0;
  long long int res = 0;
  long long int sum = 0;

  vector <int> a;

  cin >> n >> k;
  a.resize (n);

  for (int i = 0; i < n; i++)
    cin >> a[i];

  while (r < k)
    {
      sum = sum + a[r];
      r++;
    }
  r--;

  res = sum;

  while (r < n - 1)
    {
      sum = sum - a[l];
      l++;
      r++;
      sum = sum + a[r];

      res = res + sum;
    }

  finale = (double) res / (double) ((double) n - (double) k + 1);

  cout << setprecision (15) << finale << "\n";

  return 0;
}
