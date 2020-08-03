#include <bits/stdc++.h>
using namespace std;

vector <vector <char>> travelRestrictions (int, string, string);

int
main (void)
{
  int t = 0;
  int n = 0;

  string i;
  string o;
  vector <vector <char>> res;

  cin >> t;
  for (int j = 0; j < t; j++)
    {
      cin >> n;
      cin >> i;
      cin >> o;

      res = travelRestrictions (n, i, o);

      cout << "Case #" << j + 1 << ":\n";

      for (int i = 0; i < n; i++)
        {
	  for (int j = 0; j < n; j++)
	    cout << res[i][j];

	  cout << "\n";
	}
    }

  return 0;
}

vector <vector <char>>
travelRestrictions (int n, string in, string out)
{
  vector <vector <char>> res (n, vector <char> (n));

  for (int i = 0; i < n; i++)
    {
      for (int j = i; j > 0; j--)
        {
	  if (out[j] == 'Y' && in[j - 1] == 'Y')
	    res[i][j - 1] = 'Y';
	  else
	    {
	      for (int k = j - 1; k >= 0; k--)
	        res[i][k] = 'N';

	      break;
	    }
	}

      res[i][i] = 'Y';

      for (int j = i; j < n - 1; j++)
        {
	  if (out[j] == 'Y' && in[j + 1] == 'Y')
	    res[i][j + 1] = 'Y';
	  else
	    {
	      for (int k = j + 1; k < n; k++)
	        res[i][k] = 'N';

	      break;
	    }
	}
    }

  return res;
}
