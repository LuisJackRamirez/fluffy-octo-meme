#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int dec = 0;
  int inc = 0;
  int i = 0;
  int t = 0;
  int n = 0;

  vector < int >nums;

  cin >> t;

  while (t--)
    {
      cin >> n;
      nums.resize (n + 1);

      for (i = 1; i <= n; i++)
	cin >> nums[i];

      inc = 0;
      for (i = 1; i <= n; i++)
        if (nums[i] >= (i - 1))
	  inc++;
        else
	  break;

      dec = n + 1;
      for (i = n; i > 0; i--)
        if (nums[i] >= (n - i))
	  dec--;
        else
	  break;

      if (inc >= dec)
	cout << "Yes\n";
      else
	cout << "No\n";

      nums.clear ();
    }

  return 0;
}
