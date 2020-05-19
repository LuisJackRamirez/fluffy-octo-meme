#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int m = 0;
  int n = 0;
  int num = 0;
  int res = 0;

  vector <int> boys;
  vector <int> girls;

  cin >> n;
  for (int i = 0; i < n; i++)
    {
      cin >> num;
      boys.push_back (num);
    }

  cin >> m;
  for (int i = 0; i < m; i++)
    {
      cin >> num;
      girls.push_back (num);
    }

  sort (boys.begin (), boys.end ());
  sort (girls.begin (), girls.end ());

      for (int i = 0; i < boys.size (); i++)
        {
	  for (int j = 0; j < girls.size (); j++)
	    {
	      if (abs (boys[i] - girls[j]) <= 1)
	        {
		  res++;
		  boys.erase(boys.begin () + i);
		  girls.erase(girls.begin () + j);
		  i--;
		  j--;
		  break;
		}	
	    }
	}

      cout << res << "\n";

  return 0;
}
