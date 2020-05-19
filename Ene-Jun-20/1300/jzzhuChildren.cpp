#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int allSatisfied = true;
  int a = 0;
  int aux = 0;
  int cres = 0;
  int m = 0;
  int n = 0;
  int res = 0;

  cin >> n >> m;

  for (int i = 0; i < n; i++)
    {
      cin >> a;

      if (ceil ((float) a / (float) m) >= cres)
        {
	  allSatisfied = false;
	  res = i + 1;
	  cres = ceil ((float) a / (float) m);
	}
    }

  cout << res << "\n";

  return 0;  
}
