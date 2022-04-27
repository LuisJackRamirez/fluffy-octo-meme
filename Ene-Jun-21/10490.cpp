#include <bits/stdc++.h>
#define max_n 46340
using namespace std;

vector < int >primes;

bool
isPrime (unsigned long long int n)
{
  if (n == 1)
    return false;

for (int i:primes)
    {
      if ((long long) i * i > n)
	break;

      if (n % i == 0)
	return false;
    }

  return true;
}

vector < int >
getPrimes (int n)
{
  vector < bool > is (n + 1, true);
  vector < int >primes = { 2 };

  is[0] = is[1] = false;

  for (int i = 4; i <= n; i += 2)
    is[i] = false;

  for (int i = 3; i <= n; i += 2)
    {
      if (is[i])
	{
	  primes.push_back (i);
	  if ((long long) i * i <= n)
	    {
	      for (int j = i * i; j <= n; j += 2 * i)
		is[j] = false;
	    }
	}
    }

  return primes;
}

int
main (void)
{
  int n = 0;

  primes = getPrimes (max_n);

  while (cin >> n)
    {
      if (!n)
        break;

      if (isPrime (n))
	{
	  if (isPrime (pow (2, n) - 1))
	    {
	      unsigned long long res = pow (2, n - 1) * (pow (2, n) - 1);
	      cout << "Perfect: " << res << "!" << endl;
	    }
	  else
	    cout <<
	      "Given number is prime. But, NO perfect number is available." <<
	      endl;
	}
      else
	cout << "Given number is NOT prime! NO perfect number is available."
	  << endl;
    }

  return 0;
}
