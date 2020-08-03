#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int mode = 0;
  int n = 0;
  int num = 0;
  deque <int> numbers;

  cin >> n;
  for (int i = 0; i < n; i++)
    {
      cin >> num;
      numbers.push_back (num);
    }

  mode = 1;

  sort (numbers.begin (), numbers.end ());
  while (numbers.size () != 1)
    {
      if (mode > 0)
        numbers.pop_back ();
      else
        numbers.pop_front ();

      mode *= -1;
    }

  cout << numbers.front () << "\n";

  return 0;
}
