#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int flag = 0;
  string str;

  flag = -1;

  while (getline (cin, str))
    {
      for (int i = 0; i < str.length (); i++)
        {
	  if (str[i] == '"')
	    {
	      if (flag == -1)
	        cout << "``";
	      else
	        cout << "''";

	      flag *= -1;
	    }
	  else
	    cout << str[i];
	}

      cout << "\n";
    }

  return 0;
}
