#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int num = 0;
  int k = 0;

  set <int> convos;
  deque <int> screen;

  cin >> n >> k;

  for (int i = 0; i < n; i++)
    {
      cin >> num;
      
      if (convos.find (num) == convos.end ())
        {
	  if (screen.size () == k)
	    {
	      convos.erase (*(screen.end () - 1));
 	      screen.pop_back ();
	    }
	  
	  screen.push_front (num);
	  convos.insert (num);
	}
    }

  cout << screen.size () << "\n";

  for (int i = 0; i < screen.size (); i++)
    cout << screen[i] << " ";

  cout << "\n";

  return 0;
}
