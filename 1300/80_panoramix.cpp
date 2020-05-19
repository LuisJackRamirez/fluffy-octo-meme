#include <bits/stdc++.h>
using namespace std;

vector < int >primes;
vector < bool > isPrime;

void primesSieve (int);

int
main (void)
{
  int n = 0;
  int m = 0;

  primesSieve (50);

  cin >> n >> m;

  if (isPrime[m] == false)
    cout << "NO\n";
  else
    {
      for (int i = n + 1; i < 50; i++)
        if (isPrime[i])
	  {
	    if (i == m)
	      cout << "YES\n";
	    else
	      cout << "NO\n";

	    break;
	  }
    }

  return 0;
}

void
primesSieve (int n)
{
  isPrime.resize (n + 1, true);
  isPrime[0] = isPrime[1] = false;
  primes.push_back (2);

  for (int i = 4; i <= n; i += 2)
    isPrime[i] = false;

  int limit = sqrt (n);

  for (int i = 3; i <= n; i += 2)
    {
      if (isPrime[i])
	{
	  primes.push_back (i);
	  if (i <= limit)
	    for (int j = i * i; j <= n; j += 2 * i)
	      isPrime[j] = false;
	}
    }
}
