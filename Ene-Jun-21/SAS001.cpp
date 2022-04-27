#include <bits/stdc++.h>
#define lli long long int
using namespace std;

struct FenwickTree
{
  vector <lli> bit;

  FenwickTree (int N) : bit (N + 1) {}

  void add (int i, lli x)
    {
      for (; i < bit.size (); i += (i & -i))
        bit[i] += x;
    }

  lli sum (lli i)
    {
      int res = 0;

      for (; i > 0; i -= (i & -i))
        res += bit[i];

      return res;
    }

  lli sum (lli l, lli r)
    {
      return sum (r) - sum (l - 1);
    }
};

void
mapNumbers (vector <int> &a)
{
  int act = 1;
  map <int, int> m;
  vector <int> aux;

  aux = a;
  sort (aux.begin (), aux.end ());

  for (int &x : aux)
    {
      if (m.find (x) == m.end ())
        m[x] = act++;
    }

  for (int i = 0; i < a.size (); i++)
    a[i] = m[a[i]];
}

int
main (void)
{
  int n = 0;
  lli res = 0;
  int t = 0;
  
  cin >> t;
  while (t--)
    {
      res = 0;

      cin >> n;
      vector <int> a(n);

      for (int i = 0; i < n; i++)
        cin >> a[i];

      mapNumbers (a);
      FenwickTree ft (n + 3);

      for (int i = n - 1; i >= 0; i--)
        {
	  res = res + ft.sum (1, a[i] - 1);	//Suma de todos los menores
	  ft.add (a[i], 1);
	}

      cout << res << "\n";
    }

  return 0;
}
