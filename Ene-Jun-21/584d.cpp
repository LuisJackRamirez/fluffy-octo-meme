#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

bool
isPrime (int n)
{
  if (n == 1)
    return false;

  for (int d = 2; d * d <= n; d++)
    {
      if (n % d == 0)
	return false;
    }

  return true;
}

int
main (void)
{
  int n = 0;

  cin >> n;

  if (isPrime (n))
    cout << "1\n" << n << "\n";
  else if (isPrime (n - 2))
    cout << "2\n" << 2 << " " << n - 2 << "\n";
  else
    {
      for (int i = 3; i <= n; i += 2)
	{
	  int m = n - i;
	  for (int j = 3; j < m; j += 2)
	    {
	      if (isPrime (m - j) && isPrime (j) && isPrime (i))
		{
		  printf ("3\n%d %d %d\n", m - j, j, i);
		  return 0;
		}
	    }
	}
    }

  return 0;
}
