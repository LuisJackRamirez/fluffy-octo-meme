#include <bits/stdc++.h>
using namespace std;

int
ternaryString (string s, int n)
{
  int l = 0;
  int r = 0;
  int res = 1000000;

  while (l < n)
    {
      vector <bool> buck (3);

      buck[s[l] - '0' - 1] = true;
      while (r < n && s[l] == s[r])
        r++;

      if (r < n)
        buck[s[r] - '0' - 1] = true;
      
      if (l - 1 >= 0)
        buck[s[l - 1] - '0' - 1] = true;

      if (buck[0] && buck[1] && buck[2])
        res = min (res, r - (l - 1) + 1);
      
      l = r;
    }
  
  if (res == 1000000)
    return 0;
  else
    return res;
}

int
main (void)
{
  int res = 0;
  int t = 0;
  string s;

  cin >> t;
  while (t--)
    {
      cin >> s;
      res = ternaryString (s, s.length ());
      cout << res << "\n";
    }

  return 0;
}
