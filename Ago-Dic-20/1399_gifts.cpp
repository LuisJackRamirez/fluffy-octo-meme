#include <bits/stdc++.h>
#define lli long long int
using namespace std;

lli gifts (vector <int>, vector <int>, int, int);

int
main (void)
{
  int iA = 0;
  int iB = 0;
  int t = 0;
  int n = 0;

  vector <int> candies;
  vector <int> oranges;

  cin >> t;
  while (t--)
    {
      cin >> n;
      candies.resize (n);
      oranges.resize (n);

      cin >> candies[0];
      iA = 0;
      for (int i = 1; i < n; i++)
        {
	  cin >> candies[i];

	  if (candies[iA] > candies[i])
	    iA = i;
	}

      cin >> oranges[0];
      iB = 0;
      for (int i = 1; i < n; i++)
        {
	  cin >> oranges[i];

	  if (oranges[iB] > oranges[i])
	    iB = i;
	}

      cout << gifts (candies, oranges, iA, iB) << "\n";
    }

  return 0;
}

lli 
gifts (vector <int> candies, vector <int> oranges, int iA, int iB)
{
  lli res = 0;

  for (int i = 0; i < candies.size (); i++)
    {
      if (i != iA)
        res = res + candies[i] - candies[iA];
    }

  for (int i = 0; i < oranges.size (); i++)
    {
      if (i != iB)
        res = res + oranges[i] - oranges[iB];
    }

  for (int i = 0; i < oranges.size (); i++)
    {
      if (i != iA && i != iB)
	res = res - min (candies[i] - candies[iA], oranges[i] - oranges[iB]);
    }

  return res;
}
