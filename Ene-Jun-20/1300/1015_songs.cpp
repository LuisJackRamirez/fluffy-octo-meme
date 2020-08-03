#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int
main (void)
{
  int a = 0;
  int b = 0;
  int n = 0;
  int m = 0;
  vector <pair <int, int>> diff;
  lli res = 0;
  lli sum = 0;
  lli sumComp = 0;

  cin >> n >> m;

  for (int i = 0; i < n; i++)
    {
      cin >> a >> b;

      sum = sum + a;
      sumComp = sumComp + b;

      diff.push_back (make_pair (a - b, i));
    }

  if (sum <= m)
    cout << "0\n";
  else if (sumComp > m)
    cout << "-1\n";
  else
    {
      int i = 0;

      sort (diff.rbegin (), diff.rend ());

      while (sum > m)
        {
	  sum = sum - diff[i].first;

	  res++;
	  i++;
	}

      cout << res << "\n";
    }

  return 0;	
}
