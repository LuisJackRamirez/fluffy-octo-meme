#include <bits/stdc++.h>
using namespace std;

bool consecutiveNumbers (int);

int
main (void)
{
  int q = 0;
  int x = 0;

  cin >> q;

  while (q--)
    {
      cin >> x;

      if (consecutiveNumbers (x))
        cout << "Yes\n";
      else
        cout << "No\n";
    }

  return 0;
}

bool
consecutiveNumbers (int x)
{
  if (x > 2)
    return true;
  else
    return false;
}
