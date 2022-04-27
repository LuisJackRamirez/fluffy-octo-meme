#include <bits/stdc++.h>
using namespace std;

vector <int>
factorize (int n)
{
  vector <int> fact;

  for (int p = 2; p*p <= n; p++)
    {
      while (n % p == 0)
        {
	  fact.push_back (p);
	  n /= p;
	}
    }

  if (n > 1)
    fact.push_back (n);

  return fact;
}

int
main (void)
{
  int n = 0;
  int k = 0;

  cin >> n >> k;

  if (k == 1)
    {
      cout << n << "\n";
      return 0;
    }

  vector <int> fact = factorize (n);


  if (k > fact.size ())
    cout << "-1";
  else if (k == fact.size ())
    {
      for (int i : fact)
        cout << i << " ";
    }
  else
    {
      int i = 0;
      int product = 1;

      for (i = 0; i < k - 1; i++)
        cout << fact[i] << " ";

      while (i < fact.size ())
        {
	  product = product * fact[i];
	  i++;
	}

      cout << product;
    }
  
  cout << "\n";
  return 0;
}
