#include<bits/stdc++.h>
using namespace std;

int
main (void)
{
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);

  int k = 0;
  int m = 0;
  int n = 0;
  char s = 0;
  int x = 0;
  int y = 0;

  map <int, int> mapC;
  map <int, int> mapF;
  vector <vector <int>> p;

  cin >> n >> m >> k;

  p.resize (n);

  for (int i = 0; i < n; i++)
    {
      p[i].resize (m);

      for (int j = 0; j < m; j++)
        cin >> p[i][j];
    }

  for (int i = 0; i < n; i++)
    mapF.insert (make_pair (i, i));

  for (int i = 0; i < m; i++)
    mapC.insert (make_pair (i, i));

  for (int i = 0; i < k; i++)
    {
      cin >> s >> x >> y;
      x--;
      y--;

      switch (s)
        {
	  case 'c':
	    swap (mapC[x], mapC[y]);
	    //mapC[x] = y;
	    //mapC[y] = x;
	    break;

	  case 'r':
	    swap (mapF[x], mapF[y]);
	    //mapF[x] = y;
	    //mapF[y] = x;
	    break;

	  case 'g':
	    cout << p[mapF[x]][mapC[y]] << "\n";
	    break;
	}
    }

  return 0;
}
