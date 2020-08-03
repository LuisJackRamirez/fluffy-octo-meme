#include <bits/stdc++.h>
using namespace std;

vector <int> restorePerm (vector <int>);

int
main (void)
{
  int t = 0;
  int n = 0;

  vector <int> perm;
  vector <int> results;

  cin >> t;
  while (t--)
    {
      cin >> n;
      perm.resize (2 * n);

      for (int i = 0; i < 2 * n; i++)
        cin >> perm[i];

      results = restorePerm (perm);

      for (int i = 0; i < n; i++)
        cout << results[i] << " ";

      cout << "\n";
    }

  return 0;
}

vector <int>
restorePerm (vector <int> perm)
{
  set<int> aux;
  vector <int> results;

  for (int i = 0; i < perm.size (); i++)
    {
      if (aux.find (perm[i]) == aux.end ())
        {
	  aux.insert (perm[i]);
	  results.push_back (perm[i]);
	}
    }

  return results;
}
