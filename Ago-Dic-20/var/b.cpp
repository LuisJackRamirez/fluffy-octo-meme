#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int q = 0;
  int l = 0;
  int r = 0;
  int res = 0;
  int num = 0;
  
  vector <int> sum;

  cin >> n;
  sum.resize (n);

  for (int i = 0; i < n; i++)
    {
      cin >> num;

      if (i == 0)
        sum[i] = num;
      else
        sum[i] = sum[i - 1] + num;
    }

  cin >> q;
  for (int i = 0; i < q; i++)
    {
      cin >> l >> r;
      res = sum[r];
      if (l > 0)
        res = res - sum[l - 1];
      cout << res << "\n";
    }
}
