#include <bits/stdc++.h>
using namespace std;

bool isReversed (string &, string &);

int
main (void)
{
  string s;
  string t;

  cin >> s;
  cin >> t;

  if (isReversed (s, t))
    cout << "YES\n";
  else
    cout << "NO\n";
	 
  return 0;	
}

bool
isReversed (string &s, string &t)
{
  int length = 0;

  if (s.length () != t.length ())
    return false;

  length = t.length () - 1;

  for (int i = 0; i <= length; i++)
    {
      if (s[i] != t[length - i])
        return false;
    }

  return true;
}
