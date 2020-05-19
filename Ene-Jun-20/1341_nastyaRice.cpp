#include <bits/stdc++.h>
using namespace std;

bool consistentInfo (int, int, int, int, int);

int
main (void)
{
  int t = 0;
  int n = 0;
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  
  cin >> t;

  while (t--)
    {
      cin >> n >> a >> b >> c >> d;

      if (consistentInfo (n, a, b, c, d))
        cout << "Yes\n";
      else
        cout << "No\n";
    }

  return 0;
}

bool
consistentInfo (int n, int a, int b, int c, int d)
{
  int i = 0;
  int minWeight = 0;
  int maxWeight = 0;

  minWeight = n * (a - b);
  maxWeight = n * (a + b);

  i = minWeight;

  while (minWeight <= maxWeight)
    {
      if (minWeight >= (c - d) && minWeight <= (c + d))
        return true;
      else
        minWeight++;
    }
    
  return false;
}
