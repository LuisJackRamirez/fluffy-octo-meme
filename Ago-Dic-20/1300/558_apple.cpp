#include <bits/stdc++.h>
#define pii pair <int, int>
#define f first
#define s second
using namespace std;

int
main (void)
{
  int n = 0;
  int a = 0;
  int b = 0;
  int i = 0;
  int res = 0;

  vector <pii> posApples;
  vector <pii> negApples;

  cin >> n;
  
  for (int j = 0; j < n; j++)
    {
      cin >> a >> b;

      if (a < 0)
        negApples.push_back (pii (a, b));
      else 
        posApples.push_back (pii (a, b));
    }

  sort (posApples.begin (), posApples.end ());
  sort (negApples.rbegin (), negApples.rend ());

  if (posApples.size () == 0)
    {
      cout << negApples[0].s << "\n";
      return 0;
    }
  else if (negApples.size () == 0)
    {
      cout << posApples[0].s << "\n";
      return 0;
    }
      
  while (i < posApples.size () && i < negApples.size ())
    {
      res = res + posApples[i].s + negApples[i].s;
      i++;
    }
 
  if (posApples.size () < negApples.size ())
    res = res + negApples[i].s;
  else if (posApples.size () > negApples.size ())
    res = res + posApples[i].s;

  cout << res << "\n";

  return 0;
}
