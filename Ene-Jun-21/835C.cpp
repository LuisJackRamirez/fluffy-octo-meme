#include <bits/stdc++.h>
using namespace std;
int
main (void)
{
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  int c = 0;
  int n = 0;
  int q = 0;
  int res = 0;

  cin >> n >> q >> c;
  int cnt[c + 1][101][101];

  memset (cnt, 0, sizeof (cnt));
  for (int i = 0; i < n; i++)
    {
      int a = 0;
      int b = 0;
      int s = 0;
      cin >> a >> b >> s;
      cnt[s][a][b]++;
    }

  //3D vector stars[c][x][y], number of stars
  //with brightness c in rectangle (1,1):(x,y).
  for (int i = 0; i <= c; i++)
    {
      for (int j = 1; j <= 100; j++)
        {
	  for (int k = 1; k <= 100; k++)
	    {
	      cnt[i][j][k] += cnt[i][j - 1][k] + cnt[i][j][k - 1] -
		      cnt[i][j - 1][k - 1];
	    }
	}
    }

  for (int i = 0; i < q; i++)
    {
      int t = 0;
      int x1 = 0;
      int y1 = 0;
      int x2 = 0;
      int y2 = 0;

      res = 0;

      cin >> t >> x1 >> y1 >> x2 >> y2;

      for (int j = 0; j <= c; j++)
        {
	  int amm = cnt[j][x2][y2] - cnt[j][x1 - 1][y2] - cnt[j][x2][y1 - 1]
		  + cnt[j][x1 - 1][y1 - 1];

	  res = res + (((j + t) % (c + 1)) * amm);
	}
      
      cout << res << "\n";
    }

  return 0;
}
