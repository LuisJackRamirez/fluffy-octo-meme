#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  char c = '0';
  int l = 0;
  int pos = 0;
  int q = 0;
  int query = 0;
  int r = 0;
  int res = 0;
  
  string s;
  vector <set <int>> letters (26);

  cin >> s;
  cin >> q;

  for (int i = 0; i < s.size (); i++)
    letters[s[i] - 'a'].insert (i);

  while (q--)
    {
      cin >> query;

      if (query == 1)
        {
	  cin >> pos >> c;
	  pos--;

	  letters[s[pos] - 'a'].erase (pos);
	  letters[c - 'a'].insert (pos);

	  s[pos] = c;
	}
      else 
        {
	  cin >> l >> r;
	  l--;
	  r--;

	  for (int i = 0; i < 26; i++)
	    {
	      auto j = letters[i].lower_bound (l);

	      if (j != letters[i].end () && *j <= r)
	        res++;
	    }

	  cout << res << "\n";
	}

      res = 0;
    }

  return 0;
}
