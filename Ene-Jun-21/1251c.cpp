#include <bits/stdc++.h>
using namespace std;

string
minimizeInt (string s)
{
  int l = 0;
  int r = 0;
  vector <int> o;
  vector <int> e;
  string res;

  for (int i = 0; i < s.length (); i++)
    {
      if ((s[i] - '0') % 2 == 0)
        e.push_back (s[i]);
      else
        o.push_back (s[i]);
    }

  while (l < e.size () && r < o.size ())
    {
      if (e[l] < o[r])
        {
          res.push_back (e[l]);
	  l++;
	}
      else
        {
          res.push_back (o[r]);
	  r++;
	}
    }

  while (l < e.size ())
    {
      res.push_back (e[l]);
      l++;
    }

  while (r < o.size ())
    {
      res.push_back (o[r]);
      r++;
    }

  return res;
}

int
main (void)
{
  int t = 0;
  string res;
  string str;

  cin >> t;
  while (t--)
    {
      cin >> str;
      res = minimizeInt (str);
      cout << res << "\n";
    }

  return 0;
}
