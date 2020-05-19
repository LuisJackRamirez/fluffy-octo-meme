#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int beauty = 0;
  int k = 0;
  int length = 0;
  int n = 0;
  long long int res = 0;
  long long int sum = 0;

  set <pair<int, int>> s;
  vector <pair <int, int>> songs;

  cin >> n >> k;
  
  for (int i = 0; i < n; i++)
    {
      cin >> length >> beauty;
      songs.push_back (make_pair (beauty, length));
    }

  sort (songs.begin (), songs.end ());

  for (int i = n - 1; i >= 0; --i)
    {
      s.insert (make_pair (songs[i].second, i));
      sum = sum + songs[i].second;

      while (s.size () > k)
        {
	  sum = sum - s.begin ()->first;
	  s.erase (s.begin ());
	}

      res = max (res, sum * songs[i].first);
    }

  cout << res << "\n";

  return 0;
}
