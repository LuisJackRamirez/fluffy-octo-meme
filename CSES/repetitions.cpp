#include <bits/stdc++.h>
using namespace std;

int
repetitions (string s)
{
  int i = 0;
  int l = 0;
  int res = 0;

  if (s.length () == 1)
    return 1;

  i = 1;
  while (i < s.length ())
    {
      while (s[i] == s[i - 1])
        i++;

      res = max (res, i - l);
      l = i;
      i++;
    }

  return res;
}

int
main (void)
{
  string s;

  cin >> s;
  cout << repetitions (s) << "\n";

  return 0;
}
