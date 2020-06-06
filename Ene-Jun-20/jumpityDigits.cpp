#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  bool flag = false;
  string res = "0";
  string str;

  cin >> str;

  for (int i = 0; i < str.length (); i++)
    {
      for (int j = i + 1; j < str.length (); j++)
	{
	  if (str[i] > str[j])
	    {
	      string str2 = str;
	      swap (str2[i], str2[j]);

	      if (str2[0] != '0')
		{
		  if (str2 < str)
		    {
		      flag = true;

		      if (str2 > res)
			res = str2;
		    }
		}
	    }
	}
    }

  if (flag)
    cout << res;
  else
    cout << "-1";

  cout << "\n";

  return 0;
}
