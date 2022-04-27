#include <bits/stdc++.h>
using namespace std;

long long int
increasingArray (vector <int> x, int n)
{
  long long int res = 0;

  for (int i = 1; i < n; i++)
    {
      if (x[i] < x[i - 1])
        {
	  res = res + x[i - 1] - x[i];
	  x[i] = x[i - 1];
	}
    }

  return res;
}

int
main (void)
{
  int n = 0;

  cin >> n;
  vector <int> x (n);

  for (int i = 0; i < n; i++)
    cin >> x[i];

  cout << increasingArray (x, n) << "\n";

  return 0;
}
