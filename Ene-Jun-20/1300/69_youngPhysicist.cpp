#include<bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int num = 0;
  int forces[3] = {0, 0, 0};		//x = forces[0], y = forces[1], ...

  cin >> n;

  for (int i = 0; i < n; i++)
    {
      cin >> num;
      forces[0] = forces[0] + num;

      cin >> num;
      forces[1] = forces[1] + num;

      cin >> num;
      forces[2] = forces[2] + num;
    }

  if (forces[0] == 0 && forces[1] == 0 && forces[2] == 0)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}
