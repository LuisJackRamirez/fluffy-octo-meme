#include <bits/stdc++.h>
#define epsilon 1e-19
using namespace std;

vector<int> approximate (double, int);

int
main (void)
{
  vector<int> frac (2);
  int t = 0;
  int M = 0;
  double x = 0;

  cin >> t;

  while (t--)
    {
      cin >> M >> x;

      frac = approximate (x, M);
      
      cout << frac[0] << "/" << frac[1] << "\n";
    }

  return 0;
}

vector<int>
approximate (double x, int M)
{
  int a = 0;
  int b = 1;
  int c = 1;
  int d = 1;
  vector<int> res(2);
  double med = 0;

  while (b <= M && d <= M)
    {
      med = ((double) (a + c)) / ((double) (b + d));

      if (fabs (x - med) <= 0 + epsilon)
        {
	  if (b + d <= M)
	    {
	      res[0] = a + c;
	      res[1] = b + d;
	      return res;
	    }
	  else if (d > b)
	    {
	      res[0] = c;
	      res[1] = d;
	      return res;
	    }
	  else
	    {
	      res[0] = a;
	      res[1] = b;
	      return res;
	    }
	}
      else if (x - med > 0 + epsilon)
        {
	  a = a + c;
	  b = b + d;
	}
      else
        {
	  c = a + c;
	  d = b + d;
	}
    }

  if (b > M)
    {
      res[0] = c;
      res[1] = d;
      return res;
    }
  else
    {
      res[0] = a;
      res[1] = b;
      return res;
    }
}
