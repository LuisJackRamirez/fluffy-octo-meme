#include <bits/stdc++.h>
using namespace std;

int possibilities (vector <int> &, int);

int
main (void)
{
  int n = 0;
  int res = 0;
  int w = 0;

  vector <int> changes;

  cin >> n >> w;
  changes.resize (n);

  for (int i = 0; i < n; i++)
    cin >> changes[i];

  res = possibilities (changes, w);

  cout << res << "\n";

  return 0;
}

int
possibilities (vector <int> &changes, int w)
{
  int superior = 0;
  int inferior = 0;
  
  superior = w;

  if (changes[changes.size () - 1] < 0)
    inferior = 0 - changes[changes.size () - 1];
  else if (changes[changes.size () - 1] > 0)
    superior = w - changes[changes.size () - 1];

  for (int i = changes.size () - 2; i >= 0; i--)
    {
      if (changes[i] < 0)
        {
	  if (changes[i + 1] < 0)
	    inferior = inferior - changes[i];
	  else if (changes[i + 1] > 0)
	    {
	      superior = w;
	      inferior = 0 - changes[i];
	    }

	  if (inferior > w)
	    return 0;
	}
      else if (changes[i] > 0)
        {
	  if (changes[i + 1] > 0)
	    superior = superior - changes[i];
	  else if (changes[i + 1] < 0)
	    {
	      inferior = 0;
	      superior = w - changes[i];
	    }

	  if (superior < 0)
	    return 0;
	}
    }
	  
  return superior - inferior + 1;
}
