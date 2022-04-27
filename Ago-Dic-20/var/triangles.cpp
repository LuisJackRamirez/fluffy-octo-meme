#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int
main (void)
{
  int t = 0;
  lli n = 0;
  lli k = 0;
  lli res = 0;

  cin >> t;
  while (t--)
    {
      cin >> n >> k;
      n++;
      k++;
      
      res = (n * (n + 1)) % 1000000007;
      res = res / 2;
      res = (res * k) % 1000000007;

      cout << res << "\n";
    }

  return 0;
}
