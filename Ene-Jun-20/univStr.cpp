#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  bool flag = false;
  char x = 0;
  char y = 0;

  int t = 0;
  string s1;

  cin >> t;

  while (t--)
    {
      cin >> s1;

      x = s1[0];
      if (x == 'z')
        y = 'a';
      else
        y = x + 1;

      for (int i = 1; i < s1.length (); i++)
        {
	  x = s1[i];

	  if (x == y)
	    {
      	      if (x == 'z')
	        y = 'a';
	      else
	        y = x + 1;
	    }
	  else
	    {
	      flag = true;
	      break;
	    }
	}

      if (flag)
        cout << "NO\n";
      else
        cout << "YES\n";

      flag = false;
    }

  return 0;
}
