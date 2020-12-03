#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
vector < int >adj[maxn];
int tamano[maxn], vis[maxn];
vector < int >cuales;

void
dfs (int u)
{
  //entro a un nodo
  vis[u] = 1;			// marco como visitado
  // lo meto en mi vector de a quienes puedo llegar
  cuales.push_back (u);
for (int v:adj[u])
    {
      if (vis[v])
	continue;
      dfs (v);
    }
}

int
main ()
{
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
    {
      int c;
      cin >> c;
      vector < int >grupo;
      //leemos los nodos de la lista
      for (int j = 0; j < c; j++)
	{
	  int x;
	  cin >> x;
	  grupo.push_back (x);
	}

      //conectamos a un nodo con todos los demas de la lista
      for (int j = 1; j < c; j++)
	{
	  int k = j - 1;
	  adj[grupo[j]].push_back (grupo[k]);
	  adj[grupo[k]].push_back (grupo[j]);
	  //iniciamos desde j+1 para no repetir aristas
	  /*
	  for (int k = j + 1; k < c; k++)
	    {
	      //arista bidireccional
	      adj[grupo[j]].push_back (grupo[k]);
	      adj[grupo[k]].push_back (grupo[j]);
	    }
	    */
	}
    }

  for (int i = 1; i <= n; i++)
    {
      if (vis[i])
	continue;
      //si no lo he visitado
      //limpio la lista
      cuales.clear ();
      //inicio dfs desde ahi
      dfs (i);
      //cada uno puede llegar a cualquier otro de la lista
    for (int u:cuales)
	{
	  tamano[u] = (int) cuales.size ();
	}
    }

  //imprimo resultado
  for (int i = 1; i <= n; i++)
    {
      cout << tamano[i] << " ";
    }
  cout << endl;
  return 0;
}
