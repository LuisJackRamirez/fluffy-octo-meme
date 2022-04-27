#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int num = 0;
  int res = 0;

  cin >> n;
  for (int i = 1; i <= n; i++)
    {
      cin >> num;

      if (num == i)
        res++;
    }

  cout << res << "\n";

  return 0;
}
