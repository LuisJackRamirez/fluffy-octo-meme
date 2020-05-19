#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int t = 0;
  int n = 0;
  int a = 0;
  int distinct = 0;
  int equal = 0;

  vector <int> bucket;

  cin >> t;

  while (t--)
    {
      cin >> n;
      bucket.resize (n + 1);

      for (int i = 0; i < n; i++)
        {
	  cin >> a;

	  if (bucket[a] == 0)
	    {
	      bucket[a]++;
	      distinct++;
	    }
	  else
	    {
	      bucket[a]++;

	      if (bucket[a] > equal)
	        equal = a;
	    }
	}

      cout << max (min (distinct - 1, equal), min (distinct, equal - 1)) << "\n";

      bucket.clear ();
      distinct = 0;
      equal = 0;
    }

  return 0;
}
