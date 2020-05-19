#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int num = 0;
  int max = 0;
  int min = 0;
  int amazing = 0;

  cin >> n;

  cin >> num;
  max = num;
  min = num;
	  
  for (int i = 0; i < n - 1; i++)
    {
      cin >> num;

      if (num < min)
        {
	  min = num;
	  amazing++;
	}
      else if (num > max)
        {
	  max = num;
	  amazing++;
	}
    }

  cout << amazing << "\n";

  return 0;
}
