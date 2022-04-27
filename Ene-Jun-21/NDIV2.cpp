#include <bits/stdc++.h>
#define max_int 31622
using namespace std;

vector <int> primes;

vector <int>
getPrimes (int n)
{
  vector <bool> is (n + 1, true);
  vector <int> primes = {2};
  is[0] = is[1] = false;

  for (int i = 4; i <= n; i += 2)
    is[i] = false;

  for (int i = 3; i <= n; i += 2)
    {
      if (is[i])
        {
	  primes.push_back (i);

	  if ((long long) i*i <= n)
	    {
	      for (int j = i*i; j <= n; j += 2*i)
	        is[j] = false;
	    }
	}
    }

  return primes;
}

bool
isNDivisorNum (int a, int n)
{
  int num = a;
  int ans = 1;

  for (int i : primes)
    {
      if ((long long) i*i > num)
        break;

      int exp = 0;
      if (num % i == 0)
        {
	  while (num % i == 0)
	    {
	      num /= i;
	      exp++;
	    }
	}

      ans *= (exp + 1);
    }

  if (num > 1)
    ans <<= 1;

  return ans == n;
}

int
main (void)
{
  int a = 0;
  int b = 0;
  int n = 0;
  int res = 0;

  ios_base::sync_with_stdio (false);
  cin.tie (NULL);

  primes = getPrimes (max_int);
  cin >> a >> b >> n;

  for (int i = a; i <= b; i++)
    {
      if (isNDivisorNum (i, n))
	res++;
    }

  cout << res << "\n";
  return 0;
}
