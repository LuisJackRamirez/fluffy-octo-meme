#include <bits/stdc++.h>
using namespace std;

void factors (int, int);

int
main (void)
{
  int t = 0;
  int n = 0;
  int k = 0;

  cin >> t;
  while (t--)
    {
      cin >> n >> k;
      factors (n, k);
    }

  return 0;
}

void
factors (int n, int k)
{
  int j = 0;

  j = 1;

  if (n % 2 == 0)
    cout << n + (2 * k) << "\n";
  else
    {
      for (int i = 3; i <= n; i = i + 2)
        {
	  if (n % i == 0)
	    {
	      n = n + i;
	      cout << n + (2 * (k - 1)) << "\n";
	      break;
	    }
	}
    }

  return;
}
