#include <bits/stdc++.h>
using namespace std;

int
missingNumber (vector <int> a, int n)
{
  vector <bool> bucket (n + 1);

  for (int i = 0; i < a.size (); i++)
    bucket[a[i]] = true;

  for (int i = 1; i <= n; i++)
    {
      if (bucket[i] == false)
        return i;
    }
}

int
main (void)
{
  int n = 0;

  cin >> n;
  vector <int> a (n);
  for (int i = 0; i < n - 1; i++)
    cin >> a[i];

  cout << missingNumber (a, n) << "\n";

  return 0;
}
