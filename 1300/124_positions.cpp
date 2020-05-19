#include <bits/stdc++.h>
using namespace std;

int obtainPositions (int, int, int);

int
main (void)
{
  int n = 0;
  int a = 0;
  int b = 0;

  cin >> n >> a >> b;

  cout << obtainPositions (n, a, b) << "\n";

  return 0;
}

int
obtainPositions (int n, int a, int b)
{
  return n - max (a + 1, n - b) + 1;
}
