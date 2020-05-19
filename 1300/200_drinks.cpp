#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int orangeTotal = 0;
  float res = 0;
  vector <int> orange;

  cin >> n;
  orange.resize (n);

  for (int i = 0; i < n; i++)
    {
      cin >> orange[i];
      orangeTotal = orangeTotal + orange[i];
    }

  res = ((float) orangeTotal) / ((float) n);

  cout << res << "\n";

  return 0;
}
