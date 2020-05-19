#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int t = 0;
  int m = 0;
  int n = 0;

  cin >> t;

  while (t--)
    {
      cin >> n >> m;

      for (int i = 0; i < m; i++)
        cout << "B";

      cout << "\n";

      for (int i = 0; i < n - 1; i++)
        {
	  cout << "B";

	  for (int j = 0; j < m - 1; j++)
	    cout << "W";

	  cout << "\n";
	}
    }

  return 0;
}
