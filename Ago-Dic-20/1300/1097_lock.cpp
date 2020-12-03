#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  vector <int> a;
  vector <int> sumD;
  vector <int> sumI;

  cin >> n;
  a.resize (n);
  sumD.resize (n);
  sumI.resize (n);
  
  for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      
      if (i == 0)
        sumD[0] = a[i];
      else
        sumD[i] = a[i] + sumD[i - 1];
    }

  if (sumD[n - 1] == 360)
    {
      cout << "YES\n";
      return 0;
    }

  for (int i = n - 1; i >= 0; i--)
    {
      if (i == n - 1)
        sumI[n - 1] = a[i];
      else
        sumI[i] = a[i] + sumI[i + 1];
    }

  for (int i = 0; i < n - 1; i++)
    {
      if (sumD[i] == sumI[i + 1])
        {
	  cout << "YES\n";
	  return 0;
	}
    }

  cout << "NO\n";

  return 0;
}
