#include <bits/stdc++.h>
using namespace std;

int
maximumCostDeletion (string s, int a, int b)
{
  int n = s.length ();
  int m = 0;
  int l = 0;

  if (b >= 0)
    return n * (a + b);

  for (int i = 0; i < s.length (); i++)
    {
      if (s[l] != s[i])
        {
	  m++;
	  l = i;
	}
    }

  m++;
  return (n * a) + ((m / 2 + 1) * b);
}

int
main (void)
{
  int t = 0;
  int n = 0;
  int a = 0;
  int b = 0;
  string s;

  cin >> t;
  while (t--)
    {
      cin >> n >> a >> b;
      cin >> s;

      cout << maximumCostDeletion (s, a, b) << "\n";
    }

  return 0;
}
