#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int left = 0;
  int right = 0;
  int leftZ = 0;
  int leftO = 0;
  int rightZ = 0;
  int rightO = 0;
  int seconds = 0;

  cin >> n;

  for (int i = 0; i < n; i++)
    {
      cin >> left >> right;
      
      if (left == 0)
        leftZ++;
      else
        leftO++;

      if (right == 0)
        rightZ++;
      else
        rightO++;
    }

  seconds = min (leftZ, leftO) + min (rightZ, rightO);

  cout << seconds << "\n";

  return 0;
}
