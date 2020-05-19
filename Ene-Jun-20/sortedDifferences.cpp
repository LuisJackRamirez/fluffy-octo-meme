#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int l = 0;
  int n = 0;
  int r = 0;
  int t = 0;
  
  vector <int> a;
  vector <int> finale;
  vector <int> differences;

  cin >> t;

  while (t--)
    {
      cin >> n;
      a.resize (n);

      for (int i = 0; i < n; i++)
        cin >> a[i];

      sort (a.begin (), a.end ());

      l = 0;
      r = n - 1;

      while (l < r)
        {
	  finale.push_back (a[r]);
	  finale.push_back (a[l]);
	  r--;
	  l++;

	  if (l == r)
	    {
	      finale.push_back (a[r]);
	      break;
	    }
	}

      for (int i = finale.size () - 1; i >= 0; i--)
        cout << finale[i] << " ";

      cout << "\n";
      a.clear ();
      finale.clear ();
    }

  return 0;
}
