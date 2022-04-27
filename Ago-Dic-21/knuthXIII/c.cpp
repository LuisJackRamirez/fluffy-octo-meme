#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int x = 0;
  string s;

  cin >> n;
  while (n--)
    {
      cin >> s;

      for (int i = 0; i < 3; i++)
        {
	  if (s[i] == '+')
	    {
	      x++;
      	      break;
	    }
	  else if (s[i] == '-')
	    {
	      x--;
      	      break;
	    }
	}
    }

  cout << x << "\n";

  return 0;
}
