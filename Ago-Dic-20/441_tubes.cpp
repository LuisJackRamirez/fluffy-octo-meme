#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int, int>
using namespace std;

int n = 0;
int m = 0;

pii tubo (int &, int &, vector <vector <int>> &);

int
main (void)
{
  int i = 0;
  int j = 0;
  int k = 0;
  int ogK = 0;

  pii last (-1, -1);
  vector <vector <pii>> pipes;

  cin >> n >> m >> k;
  vector <vector <int>> visited (n, vector <int> (m));
  pipes.resize (k);

  ogK = k;
  pipes[ogK - k].push_back (make_pair (0, 0));
  visited[j][i] = 1;
  last = tubo (i, j, visited);
  pipes[ogK - k].push_back (last);
  k--;

  while (k > 1 && j < n)
    {
	    /*
      if (last == make_pair (-1, -1))
        {
          pipes[ogK - k].push_back (make_pair (0, 0));
	  visited[j][i] = 1;
	  last = tubo (i, j, visited);
	}
      else
        {*/
	  if (j % 2 == 0)
	    {
	      if (i + 1 < m)
	        i++;
	      else
	        j++;
	    }
	  else
	    {
	      if (i - 1 >= 0)
	        i--;
	      else
	        j++;
	    }
          
	  visited[j][i] = 1;
	  pipes[ogK - k].push_back (make_pair (i, j));
	  last = tubo (i, j, visited);
	//}


      pipes[ogK - k].push_back (last);
      k--;
    }

  while (true)
    {
      last = tubo (i, j, visited);

      if (last != make_pair (-1, -1))
        pipes[ogK - 1].push_back (last);
      else
        break;
    }

  for (int a = 0; a < pipes.size (); a++)
    {
      cout << pipes[a].size () << " ";
      for (int b = 0; b < pipes[a].size (); b++)
        cout << pipes[a][b].s + 1 << " " << pipes[a][b].f + 1 << " ";
        //cout << pipes[a][b].f + 1 << " " << pipes[a][b].s + 1 << " ";
      cout << "\n";
    }

  return 0;
}

pii
tubo (int &i, int &j, vector <vector <int>> &visited)
{
  if (j % 2 == 0)
    {
      if (i + 1 < m)
        i++;
      else
        j++;
    }
  else
    {
      if (i - 1 >= 0)
        i--;
      else
        j++;
    }

  if (j == n)
    return make_pair (-1, -1);
  
  visited[j][i] = 1;

  return make_pair (i, j);
}
