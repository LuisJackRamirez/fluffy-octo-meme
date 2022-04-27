#include <bits/stdc++.h>
#define max_int 1e7
using namespace std;

vector <bool>
sieve (int n)
{
  vector <bool> is (n + 1, true);
  is[0] = is[1] = false;

  for (int i = 4; i <= n; i += 2)
    is[i] = false;

  for (int i = 3; i*i <= n; i += 2)
    {
      if (is[i])
        {
	  for (int j = i*i; j <= n; j += 2*i)
	    is[j] = false;
	}
    }

  return is;
}

int
main (void)
{
  int m = 0;
  int n = 0;
  vector <bool> is = sieve (max_int);

  cin >> n;

  for (m = 1; m <= 1000; m++)
    {
      int res = (n * m) + 1;

      if (is[res] == false)
        break;
    }

  cout << m << "\n";
  return 0;
}
