#include <bits/stdc++.h>
using namespace std;

string champWinner (int);

int
main (void)
{
  int n = 0;

  string winner;

  cin >> n;

  winner = champWinner (n);

  cout << winner << "\n";

  return 0;
}

string
champWinner (int n)
{
  int res = 0;  
  string team;
  string winner;

  map <string, int> goals;
  map <string, int>::iterator it;

  for (int i = 0; i < n; i++)
    {
      cin >> team;

      if (goals.find (team) == goals.end ())
        goals.insert (make_pair (team, 1));
      else
        goals.find (team)->second++;
    }

  for (auto i = goals.begin (); i != goals.end (); i++)
    {
      if (i->second > res)
        {
	  winner = i->first;
	  res = i->second;
	}
    }

  return winner;
}
