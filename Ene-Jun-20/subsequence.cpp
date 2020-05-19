#include <iostream>
#include <vector>
using namespace std;

int
main (void)
{
  int k = 0;
  int l = 0;
  int maxNum = 0;
  int maxNumIt = 0;
  int n = 0;
  int r = 0;
  int res = 0;
  int sumRes = 0;

  vector <int> nums;

  while (cin >> n >> k)
    {
      nums.resize (n + 2);

      for (int i = 1; i <= n; i++)
        {
          cin >> nums[i];

	  if (nums[i] > maxNum)
	    {
	      maxNum = nums[i];
	      maxNumIt = i;
	    }
	}

      l = maxNumIt;
      r = maxNumIt;

      for (int i = 1; i <= n; i++)
        {
	  sumRes = sumRes + nums[maxNumIt];
	  res++;

	  if (nums[l - 1] > nums[r + 1])
	    {
	      l--;
	      maxNumIt = l;
	    }
	  else
	    {
	      r++;
	      maxNumIt = r;
	    }

	  if (sumRes > k)
	    break;
	}

      if (sumRes < k)
        cout << 0 << "\n";
      else
        cout << res << "\n";

      nums.clear ();
      res = 0;
      maxNum = 0;
      maxNumIt = 0;
      sumRes = 0;
    }

  return 0;
}
