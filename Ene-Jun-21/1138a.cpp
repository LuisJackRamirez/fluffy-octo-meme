#include <bits/stdc++.h>
using namespace std;

int
sushiForTwo (vector <int> fish, int n)
{
  int i = 0;
  int l = 0;
  int r = 0;
  int res = 0;

  while (i < n)
    {
      while (i < n && fish[i] == fish[i - 1])
        i++;

      r = i;
      l = r - 1;
      while (l > 0 && r < n - 1 && (fish[l - 1] == fish[l] && fish[r + 1] == fish[r]))
        {
	  l--;
	  r++;
	}

      res = max (res, r - l + 1);
      i++;
    }

  return res;
}

int
main (void)
{
  int n = 0;

  cin >> n;
  vector <int> fish (n);

  for (int i = 0; i < n; i++)
    cin >> fish[i];

  cout << sushiForTwo (fish, n) << "\n";

  return 0;
}
