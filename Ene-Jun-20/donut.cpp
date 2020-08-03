#include <bits/stdc++.h>
using namespace std;

void donuts (int, int, int);

int
main (void)
{
  int t = 0;
  int a = 0;
  int b = 0;
  int c = 0;

  cin >> t;

  while (t--)
    {
      cin >> a >> b >> c;

      donuts (a, b, c);
    }

  return 0;
}

void
donuts (int a, int b, int c)
{
  if (c <= a)
    cout << "-1";
  else if (c > a)
    cout << "1";

  cout << " ";

  if (c <= a)
    cout << b;
  else
    {
      if (c < 2 * a)
        cout << b;
      else
        cout << "-1";
    }

  cout << "\n";
}
