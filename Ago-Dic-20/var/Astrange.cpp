#include <bits/stdc++.h>
#define lli long long int
using namespace std;

vector < bool > notPrimes;

lli
countPrimes (int n)
{
  lli j = 0;
  lli res = 0;

  notPrimes.resize (n + 1);

  for (int p = 2; p * p <= n; p++)
    {
      if (notPrimes[p] == false)
	{
	  for (int i = p * p; i <= n; i = i + p)
	    {
	      notPrimes[i] = true;
	      res++;
	    }
	}
    }

  return n - res - 1;
}

bool
isPrime (int n)
{
  return !notPrimes[n];
}

int
main (void)
{
  lli s = 0;
  lli p = 0;
  lli c = 0;
  lli n = 0;
  lli t = 0;
  lli numVueltas = 0;
  lli primeNums = 0;
  lli compNums = 0;

  cin >> n >> t;
  cin >> s >> p >> c;

  primeNums = countPrimes (n);
  compNums = n - primeNums - 1;

  numVueltas = t / n;

  p = p - (((numVueltas % n) * (primeNums % n)) % n);
  c = c - (((numVueltas % n) * (compNums % n)) % n);

  if (p < 0)
    p += n;
  
  if (c < 0)
    c += n;

  t = t % n;

  while (t--)
    {
      s = (s - 1) % n;
      if (s == 0)
	s = n;

      if (s != 1)
	{
	  if (isPrime (s))
	    {
	      p = (p - 1) % n;
	      if (p == 0)
		p = n;
	    }
	  else
	    {
	      c = (c + 1) % n;
	      if (c == 0)
		c = n;
	    }
	}
    }

  cout << s << " ";
  cout << p << " ";
  cout << c << "\n";

  return 0;
}
