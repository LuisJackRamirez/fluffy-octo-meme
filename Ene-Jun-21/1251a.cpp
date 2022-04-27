#include <bits/stdc++.h>
using namespace std;

string
brokenKeyboard (string s, int n)
{
  string res;
  vector <int> bucket (26);

  for (int i = 0; i < n; i++)
    {
      if (bucket[s[i] - 'a'] != 1)
        {
	  if (s[i] == s[i + 1])
	    {
	      bucket[s[i] - 'a'] = 2;
	      i++;
	    }
	  else
	    bucket[s[i] - 'a'] = 1;
	}
    }

  for (int i = 0; i < 26; i++)
    {
      if (bucket[i] == 1)
        res.push_back (i + 'a');
    }


  return res;
}

int
main (void)
{
  int t = 0;
  string str;
  string res;

  cin >> t;
  while (t--)
    {
      cin >> str;
      res = brokenKeyboard (str, str.length ());
      cout << res << "\n";
    }

  return 0;
}
