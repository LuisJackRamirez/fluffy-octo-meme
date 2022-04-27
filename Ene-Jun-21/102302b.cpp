#include <bits/stdc++.h>
#define lli long long int
using namespace std;

set <lli>
divples (lli a, lli b)
{
  set <lli> divisors;

  for (lli i = 1; i*i <= a; i++)
    {
      if (a % i == 0)
        {
	  lli n = a / i;

	  if (i % b == 0)
	    divisors.insert (i);

	  if (i != n && n % b == 0)
	    divisors.insert (n);
	}
    }

  return divisors;
}

int
main (void)
{
  lli a = 0;
  lli b = 0;

  cin >> a >> b;

  set <lli> divisors = divples (a, b);
  for (lli i : divisors)
    cout << i << " ";

  cout << "\n";

  return 0;
}
