#include <bits/stdc++.h>
#define pii pair <int, int>
#define f first
#define s second
using namespace std;

vector <int> threeNums (int);
int minDiv (int);

int
main (void)
{
  int a = 0;
  int b = 0;
  int c = 0;
  int n = 0;
  int t = 0;
  vector <int> res;
  
  cin >> t;

  while (t--)
    {
      cin >> n;

      res = threeNums (n);

      if (res[1] == -1 || res[2] == -1)
        cout << "NO\n";
      else
        {
	  for (int i = 0; i < 3; i++)
	    cout << res[i] << " ";

	  cout << "\n";
	}
     }

  return 0;
}

vector <int>
threeNums (int n)
{
  vector <int> res (3);

  res[0] = minDiv (n);

  res[1] = minDiv (n / res[0]);

  res[2] = minDiv (n / (res[0] * res[1]));
  if (res[2] == res[0] || res[2] == res[1])
    res[2] == -1;

  return res;
}

int
minDiv (int n)
{
  if (n % 2 == 0)
    return 2;
  else
    {
      for (int i = 3; i < n; i = i + 2)
        {
	  if (n % i == 0)
	    return i;
	}
    }
}
