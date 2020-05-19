#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int res = 0;
  string s;

  cin >> n;
  cin >> s;

  for (int i = 1; i < n; i++)
    {
      if (s[i - 1] == s[i])
        res++;
    }

  cout << res << "\n";

  return 0;
}
