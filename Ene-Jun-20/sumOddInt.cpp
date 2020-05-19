#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int t = 0;
  int n = 0;
  int k = 0;
  int comp = 0;
  int num = 0;
  int res = 0;

  set <int> nums;

  num = 1;
  cin >> t;

  while (t--)
    {
      num = 1;
      res = 0;
      cin >> n >> k;

      if ((n % 2 == 0 && k % 2 == 0) || (n % 2 == 1 && k % 2 == 1))
        {
	  if (k <= sqrt (n))
	    cout << "YES\n";
	  else
	    cout << "NO\n";
	}
      else
        cout << "NO\n";

      nums.clear ();
    }

  return 0;
}
