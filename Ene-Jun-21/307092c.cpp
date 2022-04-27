#include <bits/stdc++.h>
using namespace std;

long long int
numberOfEqual (vector <int> a, vector <int> b, int n, int m)
{
  int i = 0;	
  int l = 0;
  int r = 0;
  long long int res = 0;

  while (i < m && l < n)
    {
      while (r < n && a[l] == a[r])
        r++;

      if (a[l] == b[i])
        {
          while (a[l] == b[i])
            {
              res = res + r - l;
   	      i++;
 	    }
        }
      else
        {
	  if (b[i] > a[l])
	    l = r;
	  else
	    {
	      i++;
	      while (i < m && b[i - 1] == b[i])
	        i++;
	    }
	}
    }

  return res;  
}

int
main (void)
{
  int n = 0;
  int m = 0;

  cin >> n >> m;
  vector <int> a (n);
  vector <int> b (m);

  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < m; i++)
    cin >> b[i];

  cout << numberOfEqual (a, b, n, m) << "\n";
  return 0;
}
