#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int letterCount = 0;
  string s;

  cin >> n;

  while (n--)
    {
      cin >> s;
      letterCount = s.length ();

      if (letterCount > 10)
	cout << s[0] << letterCount - 2 << s[letterCount - 1] << "\n";
      else
	cout << s << "\n";
    }

  return 0;
}
