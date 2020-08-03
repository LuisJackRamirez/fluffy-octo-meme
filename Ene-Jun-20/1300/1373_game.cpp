#include <bits/stdc++.h>
using namespace std;

bool game (string);

int
main (void)
{
  bool aliceWin = false;
  int t = 0;
  string s;

  cin >> t;

  while (t--)
    {
      cin >> s;

      aliceWin = game (s);

      if (aliceWin)
        cout << "DA\n";
      else
        cout << "NET\n";
    }

  return 0;
}

bool
game (string s)
{
  int ones = 0;
  int zeroes = 0;

  for (int i = 0; i < s.length (); i++)
    {
      if (s[i] == '0')
        zeroes++;
      else if (s[i] == '1')
        ones++;
    }

  if (min (zeroes, ones) % 2 == 0)
    return false;
  else
    return true;
}
