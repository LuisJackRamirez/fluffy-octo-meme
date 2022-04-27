#include <bits/stdc++.h>
using namespace std;

void
permutations (int n)
{
  int i = 0;
  int r = 0;

  if (n == 2 || n == 3)
    {
      cout << "NO SOLUTION\n";
      return;
    }
  else if (n == 4)
    {
      cout << "2 4 1 3\n";
      return;
    }

  i = 1;
  r = ((n - 1) / 2) + 2;
  
  while (r <= n)
    cout << i++ << " " << r++ << " ";

  if (n % 2 == 1)
    cout << i;

  cout << "\n";

  return;
}

int
main (void)
{
  int n = 0;

  cin >> n;
  permutations (n);

  return 0;
}
