#include <bits/stdc++.h>
using namespace std;

void
solveEuclidProblem (int a, int b, int &x, int &y, int &d)
{
  if (b == 0)
    {
      if (a > 0)
	{
	  x = 1;
	  y = 0;
	  d = a;
	  return;
	}
      else
	{
	  x = -1;
	  y = 0;
	  d = -a;
	  return;
	}
    }

  solveEuclidProblem (b, a % b, x, y, d);
  int oldX = x;
  x = y;
  y = oldX - ((a / b) * y);
  return;
}

int
main (void)
{
  int a = 0;
  int b = 0;
  int c = 0;
  int i = 1;
  int t = 0;

  cin >> t;
  while (t--)
    {
      cin >> a >> b >> c;
      int x = 0;
      int y = 0;
      int d = 0;

      fflush (stdin);

      solveEuclidProblem (a, b, x, y, d);
      printf ("Case %d: ", i++);

      if (c % d == 0)
        printf ("Yes\n");
      else
        printf ("No\n");
    }

  return 0;
}
