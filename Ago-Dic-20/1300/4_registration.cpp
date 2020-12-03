#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  map <string, int> users;
  map <string, int>::iterator it;
  string str;

  cin >> n;

  for (int i = 0; i < n; i++)
    {
      cin >> str;

      it = users.find (str);
      if (it == users.end ())
        {
	  cout << "OK\n";
	  users.insert (make_pair (str, 1));
	}
      else
        {
	  cout << str + to_string (it->second) << "\n";
	  users.insert (make_pair (str + to_string (it->second), 1));
	  it->second++;
	}
    }

  return 0;
}
