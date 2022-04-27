#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct FenwickTree
{
  vector <T> bit;
  FenwickTree (int N) : bit (N + 1, 0) {}

  //Update value: add val to bit[i]
  void add (int i, T val)
    {
      while (i < bit.size ())
        {
	  bit[i] = bit[i] + val;
	  i = i + (i & -i);
	}
    }

  //Query: sum the values from 1 to i
  T sum (int i)
    {
      T res = 0;
      while (i > 0)
        {
	  res = res + bit[i];
	  i = i - (i & -i);
	}

      return res;
    }

  //Query: sum the values from l to r
  T sum (int l, int r)
    {
      return sum (r) - sum (l - 1);
    }
};

int
main (void)
{
  int n = 0;
  int q = 0;

  cin >> n;
  vector <int> numbers (n);
  for (int i = 0; i < n; i++)
    cin >> numbers[i];

  FenwickTree <int> a (n);
  for (int i = 1; i <= n; i++)
    a.add (i, numbers[i - 1]);

  cin >> q;
  while (q--)
    {
      int l = 0;
      int r = 0;

      cin >> l >> r;
      cout << a.sum (l + 1, r + 1) << "\n";
    }

  return 0;
}
