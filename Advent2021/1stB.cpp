#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  // How many times the current number is bigger
  // than the last one?
  
  int increments = 0;
  int seaLevel = 0;
  int sumOld = 0;
  int sumNew = 0;

  queue <int> window;
  
  for (int i = 0; i < 3; i++)
    {
      cin >> seaLevel;
      window.push (seaLevel);
      sumOld = sumOld + seaLevel;
    }

  while (cin >> seaLevel)
    {
      sumNew = sumOld + seaLevel - window.front ();
      window.pop ();
      window.push (seaLevel);
      if (sumNew > sumOld)
        increments++;

      sumOld = sumNew;
    }

  cout << increments << "\n";

  return 0;
}
