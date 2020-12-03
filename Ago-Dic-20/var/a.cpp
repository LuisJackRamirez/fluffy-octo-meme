#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int res = 0;

  vector < int >L;
  set < tuple < int, int, int >>A;

  cin >> n;
  L.resize (n);

  for (int i = 0; i < n; i++)
    cin >> L[i];

  for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
	{
	  if (L[i] == L[j])
	    continue;

	  for (int k = j + 1; k < n; k++)
	    {
	      if (L[i] == L[k] || L[j] == L[k])
		continue;

	      if (L[i] + L[j] > L[k]
		  && L[j] + L[k] > L[i] && L[k] + L[i] > L[j])
		A.insert (make_tuple (i, j, k));
	    }
	}
    }

  cout << A.size () << "\n";

  return 0;
}
