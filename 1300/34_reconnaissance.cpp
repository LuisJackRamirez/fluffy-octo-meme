#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int a1 = 0;
  int a2 = 0;
  int difference = 1000;

  vector <int> soldiers;

  cin >> n;
  soldiers.resize (n);
  
  for (int i = 0; i < n; i++)
    cin >> soldiers[i];

  for (int i = 1; i < n; i++)
    {
      if (abs (soldiers[i] - soldiers[i - 1]) < difference)
        {
	  a1 = i;
	  a2 = i + 1;

	  difference = abs (soldiers[i] - soldiers[i - 1]);
	}
    }

  if (abs (soldiers[n - 1] - soldiers[0]) < difference)
    {
      a1 = n;
      a2 = 1;
    }

  cout << a1 << " " << a2 << "\n";

  return 0;
}
