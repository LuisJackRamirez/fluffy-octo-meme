#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  bool happy = false;
  int n = 0;
  vector <pair <int, int>> laptops;

  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> laptops[i].first >> laptops[i].second;

  sort (laptops.begin (), laptops.end ());

  for (int i = 0; i < n; i++)
    {
      if (laptops[i].first < laptops[j].first)
        {
          if (laptops[i].second > laptops[j].second)
	    {
	      happy = true;
	      break;
	    }
        }
    }

  if (happy)
    cout << "Happy Alex\n";
  else
    cout << "Poor Alex\n";

  return 0;	
}
