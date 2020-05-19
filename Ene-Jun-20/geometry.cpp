#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int t = 0;
  int height = 0;
  int width = 0;

  cin >> t;

  while (t--)
    {
      cin >> height >> width;

      if (height == width)
        cout << "Square\n";
      else
        cout << "Rectangle\n";
    }

  return 0;	
}
