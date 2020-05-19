#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int odd = 0;
  vector<int> chars(27);
  int xorSum = 0;

  string str;

  cin >> str;
  n = str.length ();

  for (int i = 0; i < n; i++)
    chars[str[i] - 'a']++;

  if (n % 2 != 0)
    cout << "First\n";
  else
    {
      for (int i = 0; i < 27; i++)
        {
	  if (chars[i] % 2 != 0)
	    odd++;

	  if (odd == 2)
	    break;
	}

      if (odd == 2)
        cout << "Second\n";
      else
        cout << "First\n";
    }

  return 0;
}
