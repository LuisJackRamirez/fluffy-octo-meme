#include<bits/stdc++.h>
using namespace std;

string texQ (string &);

int type;

int
main (void)
{
  string s;
  
  type = 1;

  while (getline (cin, s))
    cout << texQ (s) << "\n";

  return 0;
}

string 
texQ (string &s)
{
  string res;

  for (int i = 0; i < s.length (); i++)
    {
      if (s[i] == '"')
        {
 	  if (type == 1)
	    res.append ("``");
	  else
	    res.append ("''");

	  type = -type;
	}
      else
        res.push_back (s[i]);
    }

  return res;
}
