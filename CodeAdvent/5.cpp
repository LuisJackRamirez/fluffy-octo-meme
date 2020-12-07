#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int i = 0;
  int upperBound = 0;
  int lowerBound = 0;
  int res = 0;
  int max = 0;
  int col = 0;
  int row = 0;
  string str;
  set < int >seats;

  while (cin >> str)
    {
      i = 0;
      upperBound = 128;
      lowerBound = 0;

      while (i < 6)
	{
	  if (str[i] == 'F')
	    upperBound = (upperBound + lowerBound) / 2;
	  else
	    lowerBound = (upperBound + lowerBound) / 2;

	  i++;
	}

      if (str[i] == 'F')
	row = lowerBound;
      else
	row = upperBound - 1;

      i++;
      upperBound = 8;
      lowerBound = 0;

      while (i < 9)
	{
	  if (str[i] == 'L')
	    upperBound = (upperBound + lowerBound) / 2;
	  else
	    lowerBound = (upperBound + lowerBound) / 2;

	  i++;
	}

      if (str[i] == 'L')
	col = lowerBound;
      else
	col = upperBound - 1;

      if ((row * 8) + col > max)
	max = (row * 8) + col;

      seats.insert ((row * 8) + col);
    }

  for (i = 0; i <= max; i++)
    {
      if (seats.find (i) == seats.end ())
	{
	  if (seats.find (i + 1) != seats.end ()
	      && seats.find (i - 1) != seats.end ())
	    res = i;
	}
    }

  cout << res << "\n";

  return 0;
}
