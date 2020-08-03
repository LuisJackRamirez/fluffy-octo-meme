#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int L = 0;
  int R = 0;
  int P = 0;
  float aux = 0;

  cin >> L >> R >> P;

  if (L == R)
    cout << "Ambidextrous\n";
  else if (L > R)
    {
      aux = (L * P) / 100;

      if (100 * R >= (L * P))
        cout << "Ambidextrous\n";
      else
        cout << "Left-handed\n";
    }
  else if (L < R)
    {
      aux = (R * P) / 100;

      if (100 * L >= (R * P))
        cout << "Ambidextrous\n";
      else
        cout << "Right-handed\n";
    }

  return 0;
}
