#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int
segmentBigSum (vector <int> a, int n, lli s)
{
  int res = 100006;
  int l = 0;
  int r = 0;
  lli sum = 0;

  while (r < n)
    {
      sum = sum + a[r++];
      while (l < r && sum >= s)
        {
	  res = min (res, r - l);
	  sum = sum - a[l];
	  l++;
	}
    }

  if (res == 100006)
    return -1;

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
