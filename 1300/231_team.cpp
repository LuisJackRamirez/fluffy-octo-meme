#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int a = 0;
  int b = 0;
  int c = 0;
  int n = 0;
  int res = 0;

  cin >> n;

  for (int i = 0; i < n; i++)
    {
      cin >> a >> b >> c;

      if (a + b + c >= 2)
        res++;
    }

  cout << res << "\n";

  return 0;
}
