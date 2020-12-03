#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int j = 0;
  int n = 0;
  int m = 0;
  int res = 0;
  
  map <int, int> ans;
  set <pair <int, int>> index;
  vector <int> A;
  vector <int> B;

  cin >> n >> m;
  A.resize (n);
  B.resize (m);
  
  for (int i = 0; i < n; i++)
    cin >> A[i];

  for (int i = 0; i < m; i++)
    {
      cin >> B[i];
      index.insert (make_pair (i, B[i]));
    }

  sort (A.begin (), A.end ());
  sort (B.begin (), B.end ());

  while (j < m && res < n)
    {
      if (A[res] <= B[j])
        res++;
      else
        {
          ans.insert (make_pair (B[j], res));
	  j++;
        }
    }

  if (res == n)
    {
      while (j < m)
        {
          ans.insert (make_pair (B[j], res));
	  j++;
	}
    }

for (auto it = index.begin (); it != index.end (); it++)
    cout << ans.find (it->second)->second << " ";

  cout << "\n";

  return 0;
}
