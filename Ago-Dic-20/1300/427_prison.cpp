#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int num = 0;
  int t = 0;
  int c = 0;
  int res = 0;

  vector <int> prisoners;
  cin >> n >> t >> c;

  for (int i = 0; i < n; i++)
    {	
      cin >> num;

      if (num > t)
        prisoners.push_back (i);
    }

  if (prisoners.size () == 0)
    {
      cout << n - c + 1 << "\n";
      return 0;
    }

  for (int i = 0; i < prisoners.size (); i++)
    {
      if (i == 0)
        {
	  if (prisoners[0] + 1 >= c && prisoners[0] != 0)
	    res = res + prisoners[i] - c + 1;
	}
      else
        {
	  if (prisoners[i] - prisoners[i - 1] >= c)
 	    res = res + prisoners[i] - prisoners[i - 1] - c;
	}
    }
      
  if (n - (prisoners[prisoners.size () - 1] + 1) >= c && 
		  prisoners[prisoners.size () - 1] != n - 1)
    res = res + n - (prisoners[prisoners.size () - 1] + 1) - c + 1;

  cout << res << "\n";

  return 0;
}
