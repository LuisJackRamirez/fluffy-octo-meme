#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int t = 0;
  long long int n = 0;

  cin >> t;

  while (t--)
    {
      cin >> n;

      if (n % 2 == 0)
        cout << (n - 1) / 2 << "\n";
      else
	cout << n / 2 << "\n";
    }

  return 0;
}
