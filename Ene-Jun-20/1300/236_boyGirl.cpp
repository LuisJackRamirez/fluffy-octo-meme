#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int distinctChars = 0;
  string s;

  cin >> s;

  sort (s.begin (), s.end ());

  for (int i = 1; i < s.length (); i++)
    {
      if (s[i] != s[i - 1])
        distinctChars++;
    }

  if (distinctChars % 2 == 0)
    cout << "IGNORE HIM!\n";
  else
    cout << "CHAT WITH HER!\n";

  return 0;
}
