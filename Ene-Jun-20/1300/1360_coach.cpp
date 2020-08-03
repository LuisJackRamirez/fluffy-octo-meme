#include <bits/stdc++.h>
using namespace std;

int honestCoach (vector <int> strength);

int
main (void)
{
  int t = 0;
  int n = 0;
  vector <int> strength;

  cin >> t;

  while (t--)
    {
      cin >> n;
      strength.resize (n);

      for (int i = 0; i < n; i++)
        cin >> strength[i];

      cout << honestCoach (strength) << "\n";
    }

  return 0;
}

int
honestCoach (vector <int> strength)
{
  int aux = 0;
  int res = 0;

  res = 2000;

  sort (strength.begin (), strength.end ());

  for (int i = strength.size () - 1; i > 0; i--)
    {
      aux = strength[i] - strength[i - 1];

      if (aux < res)
        res = aux;
    }

  return res;
}
