#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int m = 0;
  int n = 0;
  int q = 0;

  cin >> m >> n;

  vector <vector <int>> matrix (m, vector <int> (n));
  for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
        cin >> matrix[i][j];
    }

  vector <vector <int>> sumMatrix = matrix;
  for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
        {
	  int a = 0;
	  int b = 0;
	  int c = 0;

	  if (i - 1 >= 0)
	    a = sumMatrix[i - 1][j];
	  
	  if (j - 1 >= 0)
	    b = sumMatrix[i][j - 1];

	  if (i - 1 >= 0 && j - 1 >= 0)
	    c = sumMatrix[i - 1][j - 1];

	  sumMatrix[i][j] = sumMatrix[i][j] + a + b - c;
	}
    }

  q = 3;
  for (int i = 0; i < q; i++)
    {
      int x1 = 0;
      int y1 = 0;
      int x2 = 0;
      int y2 = 0;
      int res1 = 0;
      int res2 = 0;
      int res3 = 0;
      int res4 = 0;

      cin >> x1 >> y1 >> x2 >> y2;

      res1 = sumMatrix[x2][y2];

      if (x1 - 1 >= 0)
        res2 = sumMatrix[x1 - 1][y2];

      if (y2 - 1 >= 0)
        res3 = sumMatrix[x2][y1 - 1];

      if (x1 - 1 >= 0 && y1 - 1 >= 0)
      res4 = sumMatrix[x1 - 1][y1 - 1];

      cout << res1 - res2 - res3 + res4 << "\n";
    }

  return 0;
}
