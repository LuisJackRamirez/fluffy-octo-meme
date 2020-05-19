#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int
main ()
{
  double n = 0.0, r = 0.0, avg = 0.0, prom = 0.0;
  cin >> n >> r >> avg;

  multiset < pair < double, double >>mp;
  double a = 0.0, b = 0.0;

  for (int i = 0; i < n; i++)
    {
      cin >> a >> b;
      mp.insert (
		  {
		  b, a});
      prom += a;
    }

  prom /= n;

  if (prom >= avg)
    cout << 0 << endl;

  else
    {
      int p = ((avg - prom) / (1.0 / n));

      lli ans = 0;

      for (auto it = mp.begin (); it != mp.end (); it++)
	{
	  if (it->second < r)
	    {
	      lli aux = abs (r - it->second);
	      lli min1 = (aux <= p) ? aux : p;
	      if (min1 != 0)
		{
		  p -= min1;
		  ans += ((it->first) * min1);
		}
	    }

	  if (p == 0)
	    break;
	}

      cout << ans << endl;
    }

  return 0;
}
