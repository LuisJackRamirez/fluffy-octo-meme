#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int element = 0;
  int finale = 0;
  int n = 0;
  int res = 0;
  int type1 = 0;
  int type2 = 0;

  vector <int> food;

  cin >> n;
  food.resize (n);

  for (int i = 0; i < n; i++)
    cin >> food[i];

  int j = 0;
  element = food[j];

      while (element == food[j] && j < n)
        {
          type1++;
	  j++;
	}

  while (j < n)
    {
      element = food[j - 1];
      while (element != food[j] && j < n)
        {
          type2++;
	  j++;
	}

      res = min (type1, type2) * 2;
      if (res > finale)
        finale = res;

      type1 = type2;
      type2 = 0;
    }

  cout << finale << "\n";

  return 0;
}
