#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int
main (void)
{
  lli j = 0;
  lli m = 0;
  lli n = 0;
  lli resA = 0;
  lli resB = 0;

  vector <lli> array;
  vector <lli> query;
  
  cin >> n;
  array.resize (n + 1);

  for (int i = 0; i < n; i++)
    {
      cin >> j;
      array[j] = i + 1;
    }

  cin >> m;
  query.resize (m);

  for (int i = 0; i < m; i++)
    cin >> query[i];

  for (int i = 0; i < m; i++)
    {
      resA = resA + array[query[i]];
      resB = resB + n - array[query[i]] + 1;
    }

  cout << resA << " " << resB << "\n";

  return 0;
}
