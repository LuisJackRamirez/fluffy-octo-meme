#include <bits/stdc++.h>
using namespace std;

bool
isPrime (long long n)
{
  if (n == 1)
    return false;

  if (n > 2 && n % 2 == 0)
    return true;

  for (long long d = 3; d*d <= n; d += 2)
    {
      if (n % d == 0)
        return false;
    }

  return true;
}

int
main (void)
{
  long long a = 0;
  long long b = 0;
  int t = 0;

  cin >> t;
  while (t--)
    {
      cin >> a >> b;

      if (a - b == 1)
        {
	  if (isPrime (a + b))
	    cout << "yes\n";
	  else
	    cout << "no\n";
	}
      else
        cout << "no\n";
    }

  return 0;
}
