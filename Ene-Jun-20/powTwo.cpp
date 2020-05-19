#include <bits/stdc++.h>
using namespace std;

int nums[1000000005];

int
main (void)
{
  int a = 0;
  int n = 0;
  int powsTwo[32];
  int res = 0;

  vector <int> v;

  for (int i = 0; i < 32; i++)
    powsTwo[i] = pow (2, i);

  cin >> n;
  v.resize (n);

  for (int i = 0; i < n; i++)
    {
      cin >> v[i];
      nums[v[i]]++;
    }

  for (int i = 0; i < v.size (); i++)
    {
      a = v[i];

      for (int j = 0; j < 32; j++)
        {
	  if (powsTwo[j] - a == a)
	    res = res + (nums[a] * (nums[a] - 1));
	  else
	    res = res + (nums[powsTwo[j] - a] * nums[a]);
	}
    }

  res = res / 2;

  cout << res << "\n";

  return 0;
}
