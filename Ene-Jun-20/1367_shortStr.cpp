#include <bits/stdc++.h>
using namespace std;

string shortSubStr (string &);

int
main (void)
{
  int t = 0;
  string str;

  cin >> t;

  while (t--)
    {
      cin >> str;

      cout << shortSubStr (str) << "\n";
    }

  return 0;
}

string
shortSubStr (string &str)
{
  string res;

  res.append (str.substr (0, 1));

  for (int i = 1; i <= str.length () - 1; i = i + 2)
    res.append (str.substr (i, 1));

  return res;
}
