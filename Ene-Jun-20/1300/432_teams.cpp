#include <bits/stdc++.h>
using namespace std;

int choosingTeams (vector <int>, int);	

int
main (void)
{
  int n = 0;
  int k = 0;

  vector <int> times;

  cin >> n >> k;
  times.resize (n);

  for (int i = 0; i < n; i++)
    cin >> times[i];

  cout << choosingTeams (times, k) << "\n";

  return 0;
}

int
choosingTeams (vector <int> times, int k)
{
  int res = 0;

  sort (times.begin (), times.end ());

  for (int i = 0; i < times.size (); i++)
    {
      if (times[i] <= 5 - k)
        res++;
    }

  return res / 3;
}
