#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int t = 0;
  int n = 0;

  cin >> t;
  while (t--)
    {
      cin >> n;

      if (n <= 30)
        cout << "NO\n";
      else
        {
	  cout << "YES\n";
	  if (n == 36 || n == 40 || n == 44)
	    cout << "6 10 15 " << n - 31 << "\n";
	  else
	    cout << "6 10 14 " << n - 30 << "\n";
	}
    }

  return 0;
}
