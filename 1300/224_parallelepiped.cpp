#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  float a = 0;
  float b = 0;
  float c = 0;
  float res = 0;
  int x = 0;
  int y = 0;
  int z = 0;

  cin >> x >> y >> z;

  b = sqrt ((z * y) / x);
  a = y / b;
  c = z / b;

  cout << 4 * (a + b + c) << "\n";

  return 0;
}
