#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int l = 0;
  int r = 0;

  string movements;
  int stones[1000005];

  cin >> movements;

  l = 1;
  r = movements.size ();

  for (int i = 0; i < movements.size (); ++i)
    {
      if (movements[i] == 'l')
        stones[r--] = i + 1;
      else if (movements[i] == 'r')
        stones[l++] = i + 1;
    }

  for (int i = 0; i < movements.size (); ++i)
    cout << stones[i + 1] << "\n";

  return 0;
}
