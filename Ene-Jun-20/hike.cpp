#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int res = 0;
  int mini = 0;
  vector <int> vacations;

  mini = 41;

  cin >> n;
  vacations.resize (n);

  for (int i = 0; i < n; i++)
    cin >> vacations[i];

  for (int i = 0; i < n - 2; i++)
    {
      if (max (vacations[i], vacations[i + 2]) < mini)
        {
          mini = max (vacations[i], vacations[i + 2]);
	  res = i;
	}
    }

  cout << res + 1 << " " << max (vacations[res], vacations[res + 2]) << "\n"; 

  return 0;
}
