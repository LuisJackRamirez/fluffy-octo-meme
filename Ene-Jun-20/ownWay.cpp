#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int t = 0;
  int n = 0;
  int strSize = 0;

  string P;
  string R;

  cin >> t;

  for (int i = 1; i <= t; i++)
    {
      cin >> n;
      cin >> P;

      strSize = P.size ();

      R.resize (strSize);

      for (int j = 0; j < strSize; j++)
        {
	  if (P[j] == 'E')
	    R[j] = 'S';
	  else
	    R[j] = 'E';
	}

      cout << "Case #" << i << ": " << R << "\n";
      R.clear ();
      P.clear ();
    }

  return 0;
}
