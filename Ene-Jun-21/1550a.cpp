#include <bits/stdc++.h>
using namespace std;

int
solve (int s)
{
  int res = 0;
  int sum = 0;

  for (int i = 1; sum != s; i = i + 2)
    {
      if (sum + i > s)
        {
	  res++;
	  break;
	}

      sum = sum + i;
      res++;

      /*if (s - sum == 1 || s - sum == 2)
        {
	  res++;
	  break;
	}*/
    }

  return res;
}

int
main (void)
{
  int t = 0;
  int s = 0;

  cin >> t;
  while (t--)
    {
      cin >> s;

      cout << solve (s) << "\n";
    }

  return 0;
}
