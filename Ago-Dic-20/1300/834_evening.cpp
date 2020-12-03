#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;	//guests
  int k = 0;	//guards

  string str;	//order of guests;
  vector <int> opened (26, -1);	//Doors
  vector <int> closed (26, -1);

  cin >> n >> k;
  cin >> str;

  for (int i = 0; i < n; i++)
    {
      if (opened[str[i] - 'A'] == -1)
        opened[str[i] - 'A'] = i;

      closed[str[i] - 'A'] = i;
    }

  for (int i = 0; i < n; i++)
    {
      if (opened[str[i] - 'A'] == i)
        k--;
      
      if (k < 0)
        {
	  cout << "YES\n";
	  return 0;
	}
      
      if (closed[str[i] - 'A'] == i)
        k++;
    }

  cout << "NO\n";

  return 0;
}
