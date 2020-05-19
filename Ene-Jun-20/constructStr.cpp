#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  char aux = '0';
  int t = 0;
  int a = 0;
  int b = 0;
  int i = 0;
  int j = 0;
  int n = 0;

  string str;

  cin >> t;

  while (t--)
    {
      cin >> n >> a >> b;

      while (i < n)
        {
	  string aux (1, (j % b) + 'a');
	  str.append (aux);
	  j++;

	  i++;
	}

      cout << str << "\n";

      str.clear ();
      j = 0;
      i = 0;
    }

  return 0;  
}
