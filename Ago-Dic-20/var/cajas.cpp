#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

int
main (void)
{
  int n = 0;
  int sum = 0;
  vector <pair <int, int>> boxes;

  cin >> n;
  boxes.resize (n);

  for (int i = 0; i < n; i++)
    {
      cin >> boxes[i].f >> boxes[i].s;
      sum += boxes[i].f;
    }

  sort (boxes.rbegin (), boxes.rend ());

  cout << (sum - boxes[0].f) - boxes[0].s << "\n";

  return 0;
}
