#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int start = 0;
  int lock[3] = {0, 0, 0};
  int res = 0;

  while (cin >> start >> lock[0] >> lock[1] >> lock[2])
    {
      if (start == lock[0] && start == lock[1] && start == lock[2] && start == 0)
        break;

      res = 720;

      while (start != lock[0])
        {
	  start = (start + 1) % 40;
	  res = res + 9;
	}

      res = res + 360;

      while (lock[0] != lock[1])
        {
	  lock[0] = (lock[0] - 1) % 40;
	  res = res + 9;
	}

      while (lock[1] != lock[2])
        {
	  lock[1] = (lock[1] + 1) % 40;
	  res = res + 9;
	}

      cout << res << "\n";
    }

  return 0;
}
