#include <bits/stdc++.h>
using namespace std;

void
weirdAlgorithm (long long int n)
{
  cout << n << " ";
  while (n != 1)
    {
      if (n % 2 == 0)
        n = n / 2;
      else
        n = (3 * n) + 1;

      cout << n << " ";
    }

  cout << "\n";

  return;
}

int
main (void)
{
  int n = 0;

  cin >> n;
  weirdAlgorithm ((long long) n);
	
  return 0;
}
