#include <bits/stdc++.h>
using namespace std;

int pileStones (string);

int
main (void)
{
  int n = 0;
  string stones;

  cin >> n;
  cin >> stones;

  cout << pileStones (stones) << "\n";

  return 0;	
}

int
pileStones (string stones)
{
  int res = 0;

  for (int i = 0; i < stones.length (); i++)
    {
      if (stones[i] == '+')
        res++;
      else
        res--;

      if (res < 0)
        res = 0;
    }

  return res;
}
