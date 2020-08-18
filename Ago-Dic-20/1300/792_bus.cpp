#include <bits/stdc++.h>
#define pii pair <int, int>
using namespace std;

int
main (void)
{
  int n = 0;
  int a = 0;
  int b = 0;

  map <int, int> diff;
  map <int, int>::iterator it;
  vector <int> cities;

  cin >> n;
  cities.resize (n);

  for (int i = 0; i < n; i++)
    cin >> cities[i];

  sort (cities.begin (), cities.end ());

  for (int i = 1; i < n; i++)
    {
      it = diff.find (abs (cities[i] - cities[i - 1]));

      if (it != diff.end ())
        it->second++;
      else
        diff.insert (pii (abs (cities[i] - cities[i -1]), 1));
    }

  cout << diff.begin ()->first << " " << diff.begin ()->second << "\n";

  return 0;
}
