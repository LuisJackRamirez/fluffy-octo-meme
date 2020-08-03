#include <bits/stdc++.h>
using namespace std;

int threeAmigos (int, int, int);

int
main (void)
{
  int t = 0;
  int a = 0;
  int b = 0;
  int c = 0;

  cin >> t;
  while (t--)
    {
      cin >> a >> b >> c;

      cout << threeAmigos (a, b, c) << "\n";
    }

  return 0;
}

int
threeAmigos (int a, int b, int c)
{
  int na[3] = { a - 1, a, a + 1 };
  int nb[3] = { b - 1, b, b + 1 };
  int nc[3] = { c - 1, c, c + 1 };

  long long int res = 10000000000;
  long long int finale = 0;

  for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
	{
	  for (int k = 0; k < 3; k++)
	    {
	      finale = abs (na[i] - nb[j]) + abs (na[i] - nc[k]) +
		abs (nb[j] - nc[k]);

	      if (finale < res)
		res = finale;
	    }
	}
    }

  return res;
}
