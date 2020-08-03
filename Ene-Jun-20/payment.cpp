#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int aux = 0;

  cin >> n;

  aux = n % 1000;
  if (aux == 0)
    cout << "0\n";
  else
    cout << 1000 - (n % 1000) << "\n";

  return 0;
}
