#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int a = 0;
  int b = 0;
  int c = 0;
  int spec = 0;
  vector <vector <int>> teams (3);

  cin >> n;
  for (int i = 0; i < n; i++)
    {
      cin >> spec;
      teams[spec - 1].push_back (i + 1);
    }

  a = teams[0].size ();
  b = teams[1].size ();
  c = teams[2].size ();

  if (a == 0 || b == 0 || c == 0)
    cout << "0\n";
  else
    {
      cout << min (a, min (b, c)) << "\n";

      for (int i = 0; i < min (a, min (b, c)); i++)
        {
	  for (int j = 0; j < 3; j++)
	    cout << teams[j][i] << " ";

	  cout << "\n";
	}
    }

  return 0;
}
