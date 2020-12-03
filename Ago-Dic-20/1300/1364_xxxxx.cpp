#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int t = 0;
  int n = 0;
  int x = 0;
  int num = 0;
  int sum = 0;

  deque < int >a;

  cin >> t;

  while (t--)
    {
      cin >> n >> x;

      for (int i = 0; i < n; i++)
	{
	  cin >> num;
	  a.push_back (num);
	  sum = sum + num;
	}

      if (a.size () == 1)
	{
	  if (a.front () % x == 0)
	    cout << "-1\n";
	  else
	    cout << "1\n";
	}
      else
	{
	  while (sum % x == 0 && a.size () != 0)
	    {
	      if ((sum - a.back ()) % x != 0)
		{
		  sum = sum - a.back ();
		  a.pop_back ();
		}
	      else if ((sum - a.front ()) % x != 0)
		{
		  sum = sum - a.front ();
		  a.pop_front ();
		}
	      else
		{
		  sum = sum - a.front () - a.back ();
		  a.pop_front ();
		  a.pop_back ();
		}
	    }


	  if (a.size () == 0)
	    cout << "-1\n";
	  else
	    cout << a.size () << "\n";
	}
      a.clear ();
      sum = 0;
    }

  return 0;
}
