#include <bits/stdc++.h>
using namespace std;

int dpa (int);

int
main (void)
{
  int t = 0;
  int n = 0;
  int res = 0;
 
  cin >> t;
  while (t--)
    {
      cin >> n;
      res = dpa (n);

      if (res < n)
        cout << "deficient";
      else if (res == n)
        cout << "perfect";
      else
        cout << "abundant";

      cout << "\n";
    }

  return 0;
}

int
dpa (int n)
{
  int sum = 0;

  for (int i = 1; i * i <= n; i++)
    {
      if (n % i == 0)
        {
	  if (n / i == n)
	    sum++;
	  else if (n / i == i)
	    sum = sum + i;
	  else
	    sum = sum + i + (n / i);
	}
    }

  return sum;
}
