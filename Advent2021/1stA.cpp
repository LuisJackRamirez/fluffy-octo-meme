#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  // How many times the current number is bigger
  // than the last one?
  
  int increments = 0;
  int seaLevelOld = 0;
  int seaLevelNew = 0;
  
  cin >> seaLevelOld;
  while (cin >> seaLevelNew)
    {
      if (seaLevelNew > seaLevelOld)
        increments++;

      seaLevelOld = seaLevelNew;
    }

  cout << increments << "\n";

  return 0;
}
