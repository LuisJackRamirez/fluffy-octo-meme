#include <bits/stdc++.h>
using namespace std;

int socialDistance (void);

int
main (void)
{
  int t = 0;

  cin >> t;

  while (t--)
    cout << socialDistance () << "\n";
 
  return 0;
}

int
socialDistance (void)
{
  char x = '0';
  int n = 0;
  int k = 0;
  int l = 0;
  int r = 0;
  int res = 0;
  string str;

  cin >> n >> k;
  cin >> str;

  l = 0;

  while (r < n)
    {
      while (str[r] != '1' && r < n)
        r++;

      while (r - l >= k + 1)
        {
	  l = l + k + 1;
	  res++;
	}

      r++;
      l = r + k + 1;
    }

  return res;
}
