#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int r = 0;
  int salary = 0;
  int fixed = 0;
  int doubled = 0;

  cin >> n >> r;

  while (n--)
    {
      cin >> salary;

      if (salary + r > (2 * salary))
        fixed++;
      else if (salary + r < (2 * salary))
        doubled++;
    }

  if (fixed > doubled)
    cout << "1\n";
  else if (doubled > fixed)
    cout << "2\n";
  else
    cout << "0\n";

  return 0;
}
