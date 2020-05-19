#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int a = 0;
  int res = 0;

  set <pair <int, int>> times;
  set <pair <int, int>>::iterator it;

  cin >> n;

  for (int i = 0; i < n; i++)
    {
      cin >> a;

      times.insert (make_pair (a, i));
    }

  it = times.begin ();
  res = it->second + 1;
  
  if (n == 1)
    {
      cout << res << "\n";
      return 0;
    }

  if (it->first == (++it)->first)
    cout << "Still Rozdil\n";
  else
    cout << res << "\n";

  return 0;
}
