#include <bits/stdc++.h>
using namespace std;

int max (int, int);
int commonChild (string, string, int, int);

int
main (void)
{
  int res = 0;

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  res = commonChild (s1, s2, s1.length (), s2.length ());

  cout << res << "\n";

  return 0;
}

int
commonChild (string s1, string s2, int l1, int l2)
{
  vector <int> v(l1);
  vector <vector <int>> dp(l2, v);

  int i = 0;
  int j = 0;

  for (i = 0; i <= l1; i++)
    {
      for (j = 0; j <= l2; j++)
        {
	  if (i == 0 || j == 0)
	    dp[i][j] = 0;
	  else if (s1[i - 1] == s2[j - 1])
	    dp[i][j] = dp[i - 1][j - 1] + 1;
	  else
	    dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
	}
    }

  return dp[l1][l2];
}

int
max (int a, int b)
{
  return (a > b) ? a : b;
}
