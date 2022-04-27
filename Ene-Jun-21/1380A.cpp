#include <bits/stdc++.h>
using namespace std;

void
threeIndex (vector <int> a)
{
  int ind1 = 0;
  int ind2 = 0;
  int ind3 = 0;

  for (int i = 0; i < a.size (); i++)
    {
      ind1 = -1;
      ind2 = i;
      ind3 = -1;

      for (int j = i - 1; j >= 0; j--)
        {
	  if (a[j] < a[i])
	    {
	      ind1 = j;
	      break;
	    }
	}
      
      for (int j = i + 1; j < a.size (); j++)
        {
	  if (a[j] < a[i])
	    {
	      ind3 = j;
	      break;
	    }
	}

      if (ind1 != -1 && ind3 != -1)
        {
	  cout << "YES\n";
	  cout << ind1 + 1 << " ";
	  cout << ind2 + 1 << " ";
	  cout << ind3 + 1 << "\n";

	  return;
	}
    }

  cout << "NO\n";
  return;
}

int
main (void)
{
  int n = 0;
  int t = 0;
  vector <int> a;

  cin >> t;

  while (t--)
    {
      cin >> n;
      a.resize (n);

      for (int i = 0; i < n; i++)
        cin >> a[i];

      threeIndex (a);
    }

  return 0;
}
