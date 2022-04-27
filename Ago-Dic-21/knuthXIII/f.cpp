#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  string num;
  vector <string> nums;

  ios_base::sync_with_stdio (false);
  cin.tie (NULL);

  cin >> n;
  while (n--)
    {
      cin >> num;

      sort (num.rbegin (), num.rend ());
      nums.push_back (num);
    }

  sort (nums.rbegin (), nums.rend ());

  for (int i = 0; i < nums.size (); i++)
    cout << nums[i];

  cout << "\n";

  return 0;
}
