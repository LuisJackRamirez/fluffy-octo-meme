#include <bits/stdc++.h>
using namespace std;

bool isDangerousSituations (string &);

int
main (void)
{
  bool isDangerous = false;
  string players;

  cin >> players;

  if (isDangerousSituations (players))
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}

bool
isDangerousSituations (string &players)
{
  int i = 0;
  int ones = 0;
  int zero = 0;

  while (i < players.size ())
    {
      if (players[i] == '1')
        {
          ones++;
	  zero = 0;
	}
      else
        {
	  zero++;
	  ones = 0;
	}

      if (ones == 7 || zero == 7)
        return true;

      i++;
    }

  return false;
}
