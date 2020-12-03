#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> ady;

int dfs (int, bool[]);

int
main (void)
{
  int a = 0;
  int b = 0;
  int n = 0;
  int m = 0;
  int k = 0;


  cin >> n >> m;
  ady.resize (n + 1);

  bool visited[n + 1];
  memset (visited, false, sizeof (visited));

  for (int i = 0; i < m; i++)
    {
      cin >> k;
      for (int j = 0; j < k; j++)
        {
	  cin >> a;

	  if (j != 0)
	    {
	      ady[a].push_back (b);
	      ady[b].push_back (a);
	    }

	  b = a;
	}
    }

  for (int i = 1; i <= n; i++)
    {
      memset (visited, false, sizeof (visited));
      cout << dfs (i, visited) << " ";
    }

  return 0;
}

int
dfs (int i, bool visited[])
{
  int res = 0;

  if (visited[i])
    return 0;

  visited[i] = true;

  for (auto u : ady[i])
    res = res + dfs (u, visited);

  return res + 1;
}
