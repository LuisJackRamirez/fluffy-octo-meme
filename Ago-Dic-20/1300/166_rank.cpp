#include <bits/stdc++.h>
#define pii pair<int, int> 
#define f first
#define s second
using namespace std;

bool comp (pii, pii);

int
main (void)
{
  int i = 0;
  int n = 0;
  int k = 0;
  int res = 0;
  vector <pii> teams;

  cin >> n >> k;
  teams.resize (n);

  for (int i = 0; i < n; i++)
    cin >> teams[i].f >> teams[i].s;

  sort (teams.begin (), teams.end (), comp);

  k--;
  res++;
  i = k - 1;
  while (teams[i] == teams[k])
    {
      res++;
      i--;
    }
    
  i = k + 1;
  while (teams[i] == teams[k])
    {
      res++;
      i++;
    }

  cout << res << "\n";

  return 0;
}

bool
comp (pii a, pii b)
{
  if (a.f != b.f)
    return a.f > b.f;

  return a.s < b.s;
}
