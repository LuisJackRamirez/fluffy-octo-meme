#include <bits/stdc++.h>
using namespace std;

long long int xorSum (long long int);

int
main (void)
{
  int n = 0;
  long long int x = 0;
  long long int m = 0;
  long long int res = 0;

  cin >> n;

  for (int i = 0; i < n; i++)
    {
      cin >> x >> m;

      res = res ^ xorSum (x) ^ xorSum (x + m);
    }
  
  if (res != 0)
    cout << "tolik\n";
  else
    cout << "bolik\n";

  return 0;
}

long long int
xorSum (long long int x)
{
  switch (x % 4)
    {
      case 0:
	return 0;

      case 1:
	return x - 1;

      case 2:
	return 1;

      case 3:
	return x;
    }
}
