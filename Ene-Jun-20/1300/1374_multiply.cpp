#include <bits/stdc++.h>
using namespace std;

int multiplyDivide (int);

int
main (void)
{
  int t = 0;
  int n = 0;

  cin >> t;

  while (t--)
    {
      cin >> n;
      cout << multiplyDivide (n) << "\n";
    }

  return 0;
}

int multiplyDivide (int n)
{
  int threeC = 0;
  int twoC = 0;
  int res = 0;
  int div = 0;

  div = 2;

  while (n != 1)
    {
      if (div == 2)
        {
	  if (n % div == 0)
	    {
	      n = n / div;
	      twoC++;
	    }
	  else
	    div = 3;
	}
      else if (div == 3)
        {
	  if (n % div == 0)
	    {
	      n = n / div;
	      threeC++;
	    }
	  else
	    return -1;
	}
    }

  if (twoC > threeC)
    return -1;
  else
    return (threeC - twoC) + threeC;
}
