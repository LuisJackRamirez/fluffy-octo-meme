#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  bool allSatisfied = true;
  int a = 0;
  int b = 0;
  int n = 0;
  int m = 0;
  
  vector <bool> members;

  while (cin >> n >> m)
    {
      allSatisfied = true;
      members.resize (n);

      for (int i = 0; i < m; i++)
        {
	  cin >> a >> b;

	  members[b] = true;
	}

      for (int i = 0; i < n; i++)
        {
	  if (members[i] == false)
	    {
	      allSatisfied = false;
	      break;
	    }
	}

      if (allSatisfied)
        cout << "YES\n";
      else
        cout << "NO\n";
    }

  return 0;
}
