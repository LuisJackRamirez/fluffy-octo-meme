#include <bits/stdc++.h>
using namespace std;

long long
numberSpiral (long long int row, long long int col)
{
  long long int beginInNumber = 0;

  if (col > row)
    {
      if (col % 2 == 1)
        {
	  beginInNumber = col * col;
	  return beginInNumber - row + 1;
	}
      else
        {
	  beginInNumber = ((col - 1) * (col - 1)) + 1;
	  return beginInNumber + row - 1;
	}
    }
  else
    {
      if (row % 2 == 0)
        {
	  beginInNumber = row * row;
	  return beginInNumber - col + 1;
	}
      else
        {
	  beginInNumber = ((row - 1) * (row - 1)) + 1;
	  return beginInNumber + col - 1;
	}
    }
}

int
main (void)
{
  int t = 0;
  int x = 0;
  int y = 0;
  cin >> t;

  while (t--)
    {
      cin >> y >> x;
      cout << numberSpiral ((long long) y, (long long) x) << "\n";
    }

  return 0;
}
