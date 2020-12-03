#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int a = 0;
  int b = 0;
  int t = 0;
  int res = 0;

  cin >> t;

  while (t--)
    {
      cin >> a >> b;


      if (a == b)
        cout << "0\n";
      else
        {
          res = (abs (a - b)) / 10;

	  if (abs (a - b) % 10 != 0)
	    res++;

	  cout << res << "\n";
	}
    }

  return 0;
}
