#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int aux = 0;
  int k = 0;
  int n = 0;
  int res = 0;
  int num = 0;
  int sum = 0;

  cin >> n;

  for (int i = 0; i < n; i++)
    {
      cin >> num;
      sum = sum + num;
    }

  n++;
  k = (sum - 1) / n;

//  if (sum % ((k * n) + 1) != 0)
    k++;

  aux = k * n + 1;

  for (int i = 1; i <= 5; i++)
    {
      if ((sum + i) % aux != 0)
        {
	  cout << i << "\n";
	  break;
	}
    }

  return 0;
}
