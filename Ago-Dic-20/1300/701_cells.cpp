#include <bits/stdc++.h>
#define lli long long int
#define f first
#define s second
using namespace std;

int
main (void)
{
  int n = 0;
  int m = 0;
  lli horizontal = 0;
  lli vertical = 0;

  pair <int, int> num;
  vector <lli> x;
  vector <lli> y;

  cin >> n >> m;

  x.resize (n);
  y.resize (n);
  horizontal = n;
  vertical = n;

  for (int i = 0; i < m; i++)
    {
      cin >> num.f >> num.s;

      if (x[num.f - 1] == 0)
        {
	  x[num.f - 1] = 1;
	  horizontal--;
	}
      
      if (y[num.s - 1] == 0)
        {
	  y[num.s - 1] = 1;
	  vertical--;
	}

      cout << horizontal * vertical << "\n";
    }

  return 0;
}
