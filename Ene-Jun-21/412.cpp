#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int validPairs = 0;

void
solve (int index, int k, vector <int> nums, vector <int> aux)
{
  if (k == 0)
    {
      int gcd = __gcd (aux[0], aux[1]);
      
      if (gcd == 1)
        validPairs++;

      return;
    }

  for (int i = index; i <= nums.size () - k; i++)
    {
      aux.push_back (nums[i]);
      solve (i + 1, k - 1, nums, aux);
      aux.pop_back ();
    }
}

int
main (void)
{
  int n = 0;

  scanf ("%d", &n);
  while (n != 0)
    {
      int index = 0;
      int pairNums = (n * (n - 1)) / 2;
      vector <int> nums (n);
      vector <int> aux;

      validPairs = 0;

      for (int i = 0; i < n; i++)
        scanf ("%d", &nums[i]);

      solve (index, 2, nums, aux);

      if (validPairs == 0)
        cout << "No estimate for this data set.\n";
      else
        {
	  double res = 0;

	  res = ((double) (pairNums * 6)) / ((double) validPairs);
	  res = sqrt (res);

	  printf ("%.6f\n", res);
	}

      cin >> n;
    }

  return 0;
}
