#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  string num;
  vector <string> nums;
  vector <string> res;

  ios_base::sync_with_stdio (false);
  cin.tie (NULL);

  cin >> n;
  while (n--)
    {
      cin >> num;

      sort (num.rbegin (), num.rend ());
      nums.push_back (num);
    }

  while (next_permutation (nums.begin (), nums.end ()))
    res = nums;

  for (int i = 0; i < nums.size (); i++)
    cout << res[i];

  cout << "\n";

  return 0;
}
