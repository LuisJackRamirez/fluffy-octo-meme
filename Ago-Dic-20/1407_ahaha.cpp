#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int num = 0;
  int ones = 0;
  int t = 0;
  int zeroes = 0;

  cin >> t;

  while (t--)
    {
      cin >> n;

      for (int i = 0; i < n; i++)
        {
          cin >> num;
          if (num == 1)
            ones++;
	  else
	    zeroes++;
	}

      if (ones % 2 != 0)
        ones--;

      cout << ones + zeroes << "\n";

      for (int i = 0; i < ones; i++)
        cout << "1 ";

      for (int i = 0; i < zeroes; i++)
        cout << "0 ";

      cout << "\n";

      ones = 0;
      zeroes = 0;
    }

  return 0;
}
