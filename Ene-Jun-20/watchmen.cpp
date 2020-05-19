#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int
main (void)
{
  int n = 0;
  int x = 0;
  int y = 0;
  long long int res = 0;

  map <pair <lli, lli>, lli> points;
  map <pair <lli, lli>, lli>::iterator it;
  map <lli, lli> exs;
  map <lli, lli> ohs;
  map <lli, lli>::iterator ot;

  cin >> n;

  for (int i = 0; i < n; i++)
    {
      cin >> x >> y;

      ot = exs.find (x);
      if (ot == exs.end ())
        exs.insert (make_pair (x, 1));
      else
        ot->second++;

      ot = ohs.find (y);
      if (ot == ohs.end ())
        ohs.insert (make_pair (y, 1));
      else
        ot->second++;

      it = points.find (pair <lli, lli> (x, y));
      if (it == points.end ())
        points.insert (make_pair (make_pair (x, y), 1));
      else
        it->second++;
    }

  for (auto i = exs.begin (); i != exs.end (); i++)
    res = res + (((i->second) * (i->second - 1)) / 2);

  for (auto i = ohs.begin (); i != ohs.end (); i++)
    res = res + (((i->second) * (i->second - 1)) / 2);

  for (auto i = points.begin (); i != points.end (); i++)
    res = res - (((i->second) * (i->second - 1)) / 2);

  cout << res << "\n";

  return 0;
}
