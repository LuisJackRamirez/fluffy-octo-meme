#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int r = 0;
  int lastOne = 0;
  int max = 0;

  vector < int >nums;
  vector < int >differences;
  vector < int >dp;

  cin >> n;
  nums.resize (n);
  differences.resize (n);
  dp.resize (n);

  dp[0] = 1;

  for (int i = 0; i < n; i++)
    cin >> nums[i];

  for (int i = 1; i < n; i++)
    {
      differences[i] = nums[i] - nums[i - 1];

      if (abs (differences[i]) == 1)
	{
	  if ((differences[i] == 1 && differences[lastOne] == 1)
	      || (differences[i] == -1 && differences[lastOne] == -1))
	    r = lastOne;

	  lastOne = i;
	}

      dp[i] = i - r + 1;
    }

  sort (dp.rbegin (), dp.rend ());

  cout << dp[0] << "\n";

  return 0;
}
