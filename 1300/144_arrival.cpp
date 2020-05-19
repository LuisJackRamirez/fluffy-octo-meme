#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int max = 0;
  int maxNum = 0;
  int min = 0;
  int minNum = 0;
  int res = 0;
  vector <int> soldiers;

  maxNum = 1;
  minNum = 100;

  cin >> n;
  soldiers.resize (n);

  for (int i = 0; i < n; i++)
    {
      cin >> soldiers[i];

      if (soldiers[i] <= minNum)
        {
          min = i;
	  minNum = soldiers[i];
	}

      if (soldiers[i] > maxNum)
        {
          max = i;
	  maxNum = soldiers[i];
	}
    }

  if (min == (n - 1) && max == 0)
    {
      cout << "0\n";
      return 0;
    }
  else
    {
      res = max + ((n - 1) - min);

      if (max > min)
        res--;
    }

  cout << res << "\n";

  return 0;
}
