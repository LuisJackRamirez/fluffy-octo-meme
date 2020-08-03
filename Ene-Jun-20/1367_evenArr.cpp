#include <bits/stdc++.h>
using namespace std;

int evenArray (void);

int
main (void)
{
  int t = 0;

  cin >> t;

  while (t--)
    cout << evenArray () << "\n";

  return 0;
}

int
evenArray (void)
{
  int n = 0;
  int even = 0;
  int odd = 0;
  int res = 0;

  vector <int> array;

  cin >> n;
  array.resize (n);

  for (int i = 0; i < n; i++)
    {
      cin >> array[i];

      if (array[i] % 2 == 0)
        even++;
      else
        odd++;
    }

  if (n % 2 == 0)
    {
      if (even != odd)
        return -1;
    }
  else
    {
      if (even != odd + 1)
        return -1;
    }

  for (int i = 0; i < n; i++)
    {
      if (array[i] % 2 != i % 2)
        res++;
    }

  return res / 2;
}
