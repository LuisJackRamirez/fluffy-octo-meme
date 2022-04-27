#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int
segmentSmallSum (vector <int> a, int n, lli s)
{
  int l = 0;
  int r = 0;
  int res = 0;
  lli sum = 0;

  while (r < n)
    {
      sum = sum + a[r++];
      while (l < r && sum > s)
        {
	  sum = sum - a[l];
	  l++;
	}

      res = max (res, r - l);
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

  cout << segmentSmallSum (a, n, s) << "\n";
  return 0;
}
