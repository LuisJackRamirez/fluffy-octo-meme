#include <bits/stdc++.h>
using namespace std;

int heist (vector <int>);

int
main (void)
{
  int n = 0;
  int res = 0;
  vector <int> index;

  cin >> n;
  index.resize (n);
  
  for (int i = 0; i < n; i++)
    cin >> index[i];

  res = heist (index);
  cout << res << "\n";

  return 0;
}

int
heist (vector <int> index)
{
  sort (index.begin (), index.end ());

  return (index[index.size () - 1] - index[0] + 1 - index.size ());
}
