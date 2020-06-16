#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int min = 0;
  int n = 0;
  int sum = 0;
  vector <int> stacks;

  cin >> n;
  stacks.resize (n);

  for (int i = 0; i < n; i++)
    {
      cin >> stacks[i];
      sum = sum + stacks[i];

      if (stacks[i] < min || min == 0)
        min = stacks[i];
    }

  if (n % 2 != 0)
    {
      if (sum % 2 == 0)
        cout << "imitater\n";
      else
        cout << "lowie\n";
    }
  else
    {
      if (sum % 2 == 0)
        {
	  if (min % 2 == 0)
	    cout << "imitater\n";
	  else
	    cout << "lowie\n";
	}
      else
        cout << "lowie\n";
    }
	
  return 0;
}
