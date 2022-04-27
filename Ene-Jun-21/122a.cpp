#include <bits/stdc++.h>
using namespace std;

bool
isLucky (int n)
{
  string num = to_string (n);

  for (char x : num)
    {
      if (x != '4' && x != '7')
        return false;
    }

  return true;
}

bool
luckyDivision (int n)
{
  if (isLucky (n))
    return true;

  for (int i = 1; i <= n; i++)
    {
      if (n % i == 0)
        {
	  if (isLucky (i))
	    return true;
	}
    }

  return false;
}

int
main (void)
{
  int n = 0;

  cin >> n;

  if (luckyDivision (n))
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}
