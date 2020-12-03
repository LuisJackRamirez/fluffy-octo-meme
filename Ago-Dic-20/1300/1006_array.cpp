#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int
main (void)
{
  int i = 0;
  int j = 0;
  lli sumI = 0;
  lli sumJ = 0;
  lli res = 0;
  int n = 0;
  vector<int> d;

  cin >> n;
  d.resize (n);

  for (int k = 0; k < n; k++)
    cin >> d[k];

  j = n - 1;

  sumI = d[i];
  i++;
  sumJ = d[j];
  j--;

  while (i < j)
    {
      if (sumJ > sumI)
        {
	  sumI = sumI + d[i];
	  i++;
	}
      else if (sumJ < sumI)
        {
	  sumJ = sumJ + d[j];
	  j--;
	}
      else if (sumJ == sumI)
        {
	  res = sumI;
	  sumI = sumI + d[i];
	  sumJ = sumJ + d[j];
	  i++;
	  j--;
	}
    }

  if (sumJ == sumI)
    res = sumI;

  cout << res << "\n";

  return 0;
}
