#include <bits/stdc++.h>
using namespace std;

bool isMagicNumber (int);

int
main (void)
{
  int n = 0;

  cin >> n;

  if (isMagicNumber (n))
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}

bool
isMagicNumber (int n)
{
  int i = 0;
  string str;

  str = to_string (n);

  while (i < str.length ())
    {
      if (str[i] != '1')
        {
          if (str[i] == '4')
	    {
	      if (str[i - 1] != '1')
		{ 
		  if (str[i - 1] == '4')
		    {
		      if (str[i - 2] != '1')
		        return false;
		    }
		  else
	            return false;
		}
	    }
	  else
	    return false;
	}

      i++;
    }

  return true;
}
