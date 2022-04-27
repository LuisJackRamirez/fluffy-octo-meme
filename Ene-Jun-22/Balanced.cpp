#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int w = 0;

  vector <int> bucket (200001);
  vector <int> sums (200001);

  cin >> n;

  for (int i = 0; i < n; i++)
    {
      cin >> w;
      bucket[w]++;
    }

  for (int i = 1; i <= 200000; i++)
    sums[i] = sums[i - 1] + (i * bucket[i]);

  for (int i = 1; i <= 200000; i++)
    {
      if (sums[i - 1] == (sums [200000] - sums[i]))
        {
          cout << i << "\n";
	  break;
	}
    }

  return 0;
}
