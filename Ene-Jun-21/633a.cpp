#include <bits/stdc++.h>
using namespace std;

int
gcd (int a, int b, int &x, int &y)
{
  int g = 0;

  if (b == 0)
    {
      if (a > 0)
        {
	  g = a;
	  x = 1;
	  y = 0;
	}
      else
        {
	  g = -a;
	  x = -1;
	  y = 0;
	}

      return g;
    }

  g = gcd (b, a % b, x, y);
  
  int auxX = x;
  int auxY = y;
  x = auxY;
  y = auxX - (a / b) * auxY;

  return g;
}

int
main (void)
{
  int a = 0;
  int b = 0;
  int c = 0;
  int g = 0;

  cin >> a >> b >> c;

  int x = max (a, b);
  int y = min (a, b);

  a = x;
  b = y;

  g = gcd (a, b, x, y);

  if (c % g == 0)
    {
      int x0 = 0;
      int y0 = 0;

      for (int k = - (x * c) / b; k <= (y * c) / a; k++)
        {
	  x0 = (x * (c / g)) + ((b / g) * k);
	  y0 = (y * (c / g)) - ((a / g) * k);

	  if (x0 >= 0 && y0 >= 0)
	    {
	      cout << "Yes\n";
	      return 0;
	    }
	}

      cout << "No\n";
      return 0;
    }
  else
    cout << "No\n";

  return 0;
}
