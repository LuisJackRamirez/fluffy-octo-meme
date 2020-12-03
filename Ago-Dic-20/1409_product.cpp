#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int
main (void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 0;
  int a = 0;
  int auxA = 0;
  int auxB = 0;
  int b = 0;
  int x = 0;
  int y = 0;
  int n = 0;
  lli res = 0;

  cin >> t;

  while (t--)
    {
      res = 1e18;
      cin >> a >> b >> x >> y >> n;

      for (int i = 0; i < 2; i++)
        {
           //Para observar si podemos decrementar a y b
           auxA = min (n, a - x);
           //Por si a ocupó todo
           auxB = min (n - auxA, b - y);

           res = min (res, ((lli) a - (lli) auxA) * ((lli) b - (lli) auxB) * 1ll);

	   //Para probar primero b y luego d
	   swap (a, b);
	   swap (x, y);
	}

      cout << res << "\n";
    }

  return 0;
}
