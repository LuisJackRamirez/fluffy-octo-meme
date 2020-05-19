#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int
main (void)
{
  int j = 0;
  int k = 0;
  int n = 0;
  int res = 0;
  int sumRes = 0;

  vector < int >nums;
  vector < int >sums;

  while (cin >> n >> k)
    {
      nums.resize (n + 1);
      sums.resize (n + 1);

      for (int i = 0; i < n; i++)
	{
	  cin >> nums[i];
	  sums[i + 1] = sums[i] + nums[i];
	}

      if (sums[n] < k)
	cout << 0 << "\n";
      else
	{
	  res = n;

	  for (int i = 0; sums[i] + k <= sums[n]; i++)
	    {
	      sumRes =
		lower_bound (sums.begin (), sums.end (),
			     sums[i] + k) - sums.begin ();
	      res = min (res, sumRes - i);
	    }

	  cout << res << "\n";
	}

      nums.clear ();
      sums.clear ();
      res = 0;
      sumRes = 0;
    }

  return 0;
}
