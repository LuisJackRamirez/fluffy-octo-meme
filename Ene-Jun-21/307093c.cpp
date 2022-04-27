#include <bits/stdc++.h>
#define lli long long int
using namespace std;

lli
segmentBigSum (vector <int> a, int n, lli s)
{
  lli res = 0;
  int l = 0;
  int r = 0;
  lli sum = 0;

  while (r < n)
    {
      sum = sum + a[r];
      while (sum > s)
        {
	  sum = sum - a[l];
	  l++;
	}

      res = res + r - l + 1;
      r++;
    }

  return res;
}

int
main (void)
{
  int n = 0;
  lli s = 0;

  cin >> n >> s;
  vector <int> a (n);

  for (int i = 0; i < n; i++)
    cin >> a[i];

  cout << segmentBigSum (a, n, s) << "\n";
  return 0;
}
