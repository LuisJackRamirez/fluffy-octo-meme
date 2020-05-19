#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  bool impossible = false;

  int t = 0;
  int n = 0;

  vector <int> a;
  vector <int> b;
  vector <int> ones;
  vector <int> mOnes;
  vector <int>::iterator it;

  cin >> t;

  while (t--)
    {
      cin >> n;
      a.resize (n);
      b.resize (n);

      for (int i = 0; i < n; i++)
        {
	  cin >> a[i];

	  if (a[i] == 1)
	    ones.push_back (i);
	  else if (a[i] == -1)
	    mOnes.push_back (i);
	}

      for (int i = 0; i < n; i++)
        cin >> b[i];

      for (int i = n - 1; i >= 0; i--)
        {
	  if (a[i] < b[i])
	    {
	      it = ones.end ();
	      it--;

	      while (i <= *it && ones.empty () == false)
	        {
	          ones.erase (it);
		  it--;
		}

	      if (ones.empty ())
	        {
		  impossible = true;
		  break;
		}
	    }
	  else if (a[i] > b[i])
	    {
	      it = mOnes.end ();
	      it--;

	      while (i <= *it && mOnes.empty () == false)
	        {
	          mOnes.erase (it);
		  it--;
		}

	      if (mOnes.empty ())
	        {
		  impossible = true;
		  break;
		}
	    }
	}

      if (impossible)
        cout << "NO\n";
      else
        cout << "YES\n";

      a.clear ();
      b.clear ();
      ones.clear ();
      mOnes.clear ();
      impossible = false;
    }

  return 0;
}
