#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

template < typename T > struct FenwickTree
{
  vector < T > bit;
  FenwickTree (int N):bit (N + 1, 0)
  {
  }

  /* Update value: add val to bit[i]
   *
   * Al actualizar, se le añade uno a todos sus
   * ancestros indicando que hay un elemento más
   * grande que todos esos.
   */
  void add (int i, T val)
  {
    while (i < bit.size ())
      {
	bit[i] = bit[i] + val;
	i = i + (i & -i);
      }
  }

  /*
   * Query: sum the values from 1 to i
   *
   * Regresa el número de elementos presentes
   * desde el inicio del arreglo de estructura
   * personalizada hasta i.
   */
  T sum (int i)
  {
    T res = 0;
    while (i > 0)
      {
	res = res + bit[i];
	i = i - (i & -i);
      }

    return res;
  }
};

int
main (void)
{
  int n = 0;
  int q = 0;

  vector < int >lastPosition (1e6 + 5, -1);
  vector < int >ans (300005);

  cin >> n;
  vector < int >a (n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  //Las solicitudes se realizarán
  //de manera offline.
  cin >> q;
  vector < pair < int, pair < int, int >>>queries (q);
  for (int i = 0; i < q; i++)
    {
      //vector <pair <int a, pair <int b, int c>>>
      //a = Elemento j de la DQUERY. Permitirá ordenar con respecto a j
      //b = Elemento i de la DQUERY.
      //c = Número de query.
      cin >> queries[i].s.f >> queries[i].f;
      queries[i].s.s = i;
    }

  sort (queries.begin (), queries.end ());
  FenwickTree < int >t (n);

  int x = 0;
  for (int i = 1; i <= n; i++)
    {
      if (lastPosition[a[i]] != -1)
	//Actualizar la ultima posicion
	t.add (lastPosition[a[i]], -1);

      //Actualizar la posición actual del elemento i
      lastPosition[a[i]] = i;
      t.add (i, 1);

      while (x < q && queries[x].f == i)
	{
	  ans[queries[x].s.s] =
	    t.sum (queries[x].f) - t.sum (queries[x].s.f - 1);
	  x++;
	}
    }

  for (int i = 0; i < q; i++)
    cout << ans[i] << "\n";

  return 0;
}
