#include <bits/stdc++.h>
using namespace std;

bool isSupercentral (int, int, vector <pair <int, int>> &, int);

int
main (void)
{
  int n = 0;
  int a = 0;
  int b = 0;
  int res = 0;

  vector <pair <int, int>> points;

  cin >> n;
  points.resize (n);

  for (int i = 0; i < n; i++)
    cin >> points[i].first >> points[i].second;

  sort (points.begin (), points.end ());

  for (int i = 0; i < n; i++)
    {
      if (isSupercentral (points[i].first, points[i].second, points, i))
        res++;
    }

  cout << res << "\n";

  return 0;
}

bool
isSupercentral (int x, int y, vector <pair <int, int>> &points, int i)
{
  bool lNeighbor = false;
  bool rNeighbor = false;
  bool uNeighbor = false;
  bool dNeighbor = false;

  for (int j = 0; j < points.size (); j++)
    {
      if (j != i)
        {
	  if (points[j].first == x)
	    {
	      if (points[j].second > y)
	        uNeighbor = true;
	      else if (points[j].second < y)
	        dNeighbor = true;
	    }
	  else if (points[j].second == y)
	    {
	      if (points[j].first > x)
	        rNeighbor = true;
	      else if (points[j].first < x)
	        lNeighbor = true;
	    }
	}
    }

  if (lNeighbor && rNeighbor && uNeighbor && dNeighbor)
    return true;
  else
   return false;
}
