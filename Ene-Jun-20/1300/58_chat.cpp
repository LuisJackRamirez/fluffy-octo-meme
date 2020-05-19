#include <bits/stdc++.h>
using namespace std;

bool saidHello (string &);

int
main (void)
{
  string str;

  cin >> str;

  if (saidHello (str))
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;  
}

bool
saidHello (string &str)
{
  int hello[4] = {0, 0, 0, 0};

  for (int i = 0; i < str.length (); i++)
    {
      if (str[i] == 'h')
        hello[0]++;
      else if (str[i] == 'e')
        {
	  if (hello[0] > 0)
	    hello[1]++;
	}
      else if (str[i] == 'l')
        {
	  if (hello[0] > 0 && hello[1] > 0)
	    hello[2]++;
	}
      else if (str[i] == 'o')
        {
	  if (hello[0] > 0 && hello[1] > 0 && hello[2] >= 2)
	    hello[3]++;
	}
    }

  if (hello[0] > 0 && hello[1] > 0 && hello[2] > 0 && hello[3] > 0)
    return true;
  else
    return false;
}
