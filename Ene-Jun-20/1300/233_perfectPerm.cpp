#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  vector <int> v1;

  cin >> n;
  v1.resize (n);

  if (n % 2 == 1)
    {
      cout << "-1\n";
      return 0;
    }

  for (int i = 1; i <= n; i++)
    v1[i - 1] = i;

  for (int i = 1; i < n; i = i + 2)
    {
      v1[i] = v1[i] ^ v1[i - 1];
      v1[i - 1] = v1[i - 1] ^ v1[i];
      v1[i] = v1[i] ^ v1[i - 1];
    }

  for (int i = 0; i < n; i++)
    cout << v1[i] << " ";

  cout << "\n";

  return 0;
}
