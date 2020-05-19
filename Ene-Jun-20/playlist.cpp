#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  long long int beauty = 0;
  long long int res = 0;
  long long int j = 0;
  long long int n = 0;
  long long int k = 0;

  vector <long long int> suffix;
  vector <long long int> lengths;
  vector <pair <long long int, long long int>> songs;	//beauty, index

  cin >> n >> k;
  lengths.resize (n);
  suffix.resize (n);

  for (int i = 0; i < n; i++)
    {
      cin >> lengths[i] >> beauty;
      songs.push_back (make_pair (beauty, i));
    }
 
  //sort (songs.begin (), songs.end (), greater <>());
  sort (songs.rbegin (), songs.rend ());

  for (int i = 0; i < n; i++)
    {
      if (i == 0)
        suffix[j] = lengths[songs[i].second];
      else
        suffix[j] = suffix[j - 1] + lengths[songs[i].second];

      j++;
    }
    
  for (int i = 0; i < k; i++)
    {
      j = suffix[i] * (songs[0].first);

      if (j > res)
        {
	  res = j;
	  songs.erase (songs.begin ());
	}
      else
        break;
    }

  cout << res << "\n";

  return 0;
}
