#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  bool flag = false;
  float a = 0;
  float b = 0;
  float x = 0;
  float y = 0;
  double distance = 0;
  double res = 0;
  double time = 0;
  double v = 0;
  int n = 0;

  cin >> a >> b;
  cin >> n;

  for (int i = 0; i < n; i++)
    {
      cin >> x >> y >> v;

      distance = sqrt (pow ((x - a), 2) + pow((y - b), 2));
      time = distance / v;

      if (time < res || flag == false)
        {
	  res = time;
	  flag = true;
	}
    }

  cout << setprecision (14) << res << "\n";

  return 0;
}
