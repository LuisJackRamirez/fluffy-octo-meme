#include <bits/stdc++.h>
using namespace std;

int getMaxCost (multiset < int >, int);
int getMinCost (multiset < int >, int);

int
main (void)
{
  int a = 0;
  int n = 0;
  int m = 0;
  int costs[2] = { 0, 0 };

  multiset < int >seats;

  cin >> n >> m;

  for (int i = 0; i < m; i++)
    {
      cin >> a;
      seats.insert (a);
    }

  costs[0] = getMaxCost (seats, n);
  costs[1] = getMinCost (seats, n);

  cout << costs[0] << " " << costs[1] << "\n";

  return 0;
}

int
getMaxCost (multiset < int >seats, int n)
{
  int a = 0;
  int res = 0;
  multiset <int>::iterator it;

  while (n--)
    {
      it = seats.end ();
      it--;

      a = *it;
      res = res + a;
      seats.erase (it);
      a--;
      seats.insert (a);
    }

  return res;
}

int
getMinCost (multiset < int >seats, int n)
{
  int a = 0;
  int res = 0;

  while (n--)
    {
      a = *seats.begin (); 
      res = res + a;
      seats.erase (seats.begin ());
      a--;

      if (a > 0)
        seats.insert (a);
    }

  return res;
}
