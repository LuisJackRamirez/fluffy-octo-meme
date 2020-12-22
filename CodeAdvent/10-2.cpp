#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int num = 0;

  vector <int> adapters;

  adapters.push_back (0);
  while (cin >> num)
    adapters.push_back (num);

  sort (adapters.begin (), adapters.end ());
  adapters.push_back (adapters[adapters.size () - 1] + 3);



  return 0;
}

int
possibleSolutions (vector <int> adapters, int i)
{
  int total = 0;

  if (i == adapters.size () - 1)
    return 1;

  for (int j = i + 1; j < min (i + 4, adapters.size ()); j++)
    {
      if (adapters[j] - nums[i] <= 3)
        total = total + possibleSolutions (adapters, j)
    }

  return total;
}
