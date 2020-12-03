#include <bits/stdc++.h>
using namespace std;

int quaseEquals (vector <string>, string, int);

int
main (void)
{
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);

  int n = 0;
  int q = 0;
  int l = 0;
  int res = 0;

  vector <string> a;
  string str;

  while (cin >> n >> q >> l)
    {
      a.resize (n);

      for (int i = 0; i < n; i++)
        cin >> a[i];

      for (int i = 0; i < q; i++)
        {
          cin >> str;

	  for (int j = 0; j < l; j++)
	    res = res + quaseEquals (a, str, j);
	}

      cout << res << "\n";
      res = 0;
    }

  return 0;
}

int 
quaseEquals (vector <string> a, string str, int j)
{
  int res = 0;

  str.erase (j, 1);

  for (int i = 0; i < a.size (); i++)
    {
      a[i].erase (j, 1);

      if (a[i] == str)
        res++;
    }

  return res;
}
