#include <bits/stdc++.h>
using namespace std;

bool
lovePolygonExists (vector <int> &planes, int n, int i, int grade)
{
  if (grade == 0)
    {
      if (n == i)
        return true;
      else
        return false;
    }
    
  return lovePolygonExists (planes, n, planes[i] - 1, grade - 1);
}

int
main (void)
{
  int n = 0;

  cin >> n;
  vector <int> planes (n);
  vector <bool> visited (n);

  for (int i = 0; i < n; i++)
    cin >> planes[i];

  for (int i = 0; i < n; i++)
    {
      if (lovePolygonExists (planes, i, planes[i] - 1, 2))
        {
          cout << "Yes\n";
	  return 0;
	}
    }
  
  cout << "No\n";
  return 0;
}
