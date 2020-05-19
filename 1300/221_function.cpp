#include <bits/stdc++.h>
using namespace std;

vector <int> obtainPermutation (int);

int
main (void)
{
  int n = 0;

  vector <int> permutation;

  cin >> n;

  permutation = obtainPermutation (n);
 
  for (int i = 0; i < permutation.size (); i++)
    cout << permutation[i] << " ";

  cout << "\n";

  return 0;
}

vector <int>
obtainPermutation (int n)
{
  vector <int> res;

  res.push_back (n);

  for (int i = 1; i < n; i++)
    res.push_back (i);

  return res;
}
