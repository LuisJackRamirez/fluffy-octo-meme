#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int winnerPower (map < int, int >&, queue < int >&, int);

int
main (void)
{
  lli n = 0;
  lli k = 0;
  int maxPower = 0;
  int power = 0;
  int res = 0;

  map < int, int >powers;
  queue < int >matches;

  cin >> n >> k;

  for (int i = 0; i < n; i++)
    {
      cin >> power;

      if (power > maxPower)
	maxPower = power;

      if (k < n - 1)
	{
	  powers.insert (make_pair (i + 1, power));
	  matches.push (i + 1);
	}
    }

  if (k >= n - 1)
    cout << maxPower << "\n";
  else
    {
      res = winnerPower (powers, matches, k);
      cout << res << "\n";
    }

  return 0;
}

int
winnerPower (map < int, int >&powers, queue < int >&matches, int k)
{
  int a = 0;
  int b = 0;
  int rowWins = 0;
  int currentWinner = 0;

  a = matches.front ();
  matches.pop ();
  b = matches.front ();
  matches.pop ();

  if (powers.find (a)->second > powers.find (b)->second)
    {
      currentWinner = a;
      rowWins++;
      matches.push (b);
    }
  else 
    {
      currentWinner = b;
      rowWins++;
      matches.push (a);
    }


  while (rowWins < k)
    {
      b = matches.front ();
      matches.pop ();

      if (powers.find (currentWinner)->second > powers.find (b)->second)
        {
          rowWins++;
          matches.push (b);
	}
      else
        {
	  matches.push (currentWinner);
	  currentWinner = b;
	  rowWins = 1;
	}
    }

  return powers.find (currentWinner)->second;
}
