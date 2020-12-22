#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int threeNums = 0;
  int num = 0;
  int oneNums = 0;

  vector <int> adapters;

  adapters.push_back (0);
  while (cin >> num)
    adapters.push_back (num);

  sort (adapters.begin (), adapters.end ());
  adapters.push_back (adapters[adapters.size () - 1] + 3);

  for (int i = 1; i < adapters.size (); i++)
    {
      if (adapters[i] - adapters[i - 1] == 3)
        threeNums++;
      else if (adapters[i] - adapters[i - 1] == 1)
        oneNums++;
    }

  cout << threeNums * oneNums << "\n";

  return 0;
}
