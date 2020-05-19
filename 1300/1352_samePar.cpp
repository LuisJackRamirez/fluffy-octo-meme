#include <bits/stdc++.h>
#define Y "YES\n"
#define N "NO\n"
using namespace std;

vector <int> getNums (int, int);
void printRes (vector <int> &);

int
main (void)
{
  int t = 0;
  int n = 0;
  int k = 0;

  vector <int> res;

  cin >> t;

  while (t--)
    {
      cin >> n >> k;

      res = getNums (n, k);

      if (res.size () == 0)
        cout << N;
      else
        {
	  cout << Y;
	  printRes (res);
	}
    }

  return 0;
}

vector <int> 
getNums (int n, int k)
{
  vector <int> res;

  if (n % 2 == 0)
    {
      if (k > n / 2 && k != n)
        return res;
      else if (k == n)
        {
	  for (int i = 0; i < k; i++)
	    res.push_back (1);
	}
      else
        {
	  for (int i = 1; i < k; i++)
	    res.push_back (2);

	  res.push_back (n - (2 * (k - 1)));
	}
    }
  else
    {
      if (k % 2 == 0 || k > n)
        return res;
      else
        {
	  for (int i = 1; i < k; i++)
	    res.push_back (1);

	  res.push_back (n - (k - 1));
	}
    }

  return res;
}

void
printRes (vector <int> &res)
{
  for (int i = 0; i < res.size (); i++)
    cout << res[i] << " ";

  cout << "\n";
}
