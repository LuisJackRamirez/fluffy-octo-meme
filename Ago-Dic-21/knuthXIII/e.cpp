#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);

  int n = 0;
  string str;

  cin >> n;
  str.resize (n);

  for (int i = 0; i < n; i++)
    cin >> str[i];

  sort (str.begin (), str.end ());

  cout << str << "\n";

  return 0;
}
