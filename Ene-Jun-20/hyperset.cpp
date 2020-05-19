#include <bits/stdc++.h>
using namespace std;

set < string > strDb;

bool check (string, string, int);

int
main (void)
{
  int n = 0;
  int k = 0;
  int finale = 0;

  vector < string > cards;

  cin >> n >> k;
  cards.resize (n);

  for (int i = 0; i < n; i++)
    {
      cin >> cards[i];
      strDb.insert (cards[i]);
    }

  if (n < 3)
    {
      cout << "0\n";
      return 0;
    }

  for (int i = 0; i < n - 1; ++i)
    {
      for (int j = i + 1; j < n; ++j)
	{
	  if (check (cards[i], cards[j], k))
	    finale++;
	}
    }

  cout << finale / 3 << "\n";
  return 0;
}

bool
check (string a, string b, int k)
{
  string thirdCard;

  for (int m = 0; m < k; ++m)
    {
      if (a[m] == b[m])
	thirdCard += a[m];
      else
	{
	  if (a[m] > b[m])
	    swap (a[m], b[m]);

	  if (a[m] == 'E' && b[m] == 'S')
	    thirdCard += 'T';
	  else if (a[m] == 'E' && b[m] == 'T')
	    thirdCard += 'S';
	  else
	    thirdCard += 'E';
	}
    }

  if (strDb.find (thirdCard) == strDb.end ())
    return false;
  else
    return true;
}
