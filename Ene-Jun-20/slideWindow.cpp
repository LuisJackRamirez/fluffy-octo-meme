#include <iostream>
#include <vector>
#include <set>
using namespace std;

int
main (void)
{
  int n = 0;
  int k = 0;
  int l = 0;

  set <pair <int, int>> s;
  set <pair <int, int>>::reverse_iterator max;
  vector <int> v;

  cin >> n;
  v.resize (n);

  for (int i = 0; i < n; i++)
    cin >> v[i];

  cin >> k;

  for (int i = 0; i < k; i++)
    s.insert (make_pair (v[i], i));

  k--;

  while (k < n - 1)
    {
      max = s.rbegin ();
      cout << max->first << " ";

      s.erase (make_pair (v[l], l));
      l++;
      k++;
      s.insert (make_pair (v[k], k));
    }

  cout << max->first << "\n";

  return 0;	
}
