#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int problems[4] = {0, 0, 0, 0};
  string result;

  cin >> n;

  for (int i = 0; i < n; i++)
    {
      cin >> result;

      if (result == "AC")
        problems[0]++;
      else if (result == "WA")
        problems[1]++;
      else if (result == "TLE")
        problems[2]++;
      else if (result == "RE")
        problems[3]++;
    }

  cout << "AC x " << problems[0] << "\n";
  cout << "WA x " << problems[1] << "\n";
  cout << "TLE x " << problems[2] << "\n";
  cout << "RE x " << problems[3] << "\n";

  return 0;
}
