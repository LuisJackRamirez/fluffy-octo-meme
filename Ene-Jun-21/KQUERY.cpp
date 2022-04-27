#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

/*
 * Estructura personalizada para almacenar 
 * valores importantes del problema
 *
 * pos: El orden de la i-ésima query. Cero si es un elemento de un arreglo
 * L: Índice izquierdo de la query. Cero si es un elemento de un arreglo
 * R: Índice derecho de la query. Si es un elemento de un arreglo,
 *    guarda su posición
 * val: El valor 'k' de la query o el valor numérico del elemento del arreglo.
 */
struct node
{
  int pos;
  int l;
  int r;
  int val;
};

bool
comp (node a, node b)
{
  /*
   * l representa si val es una query o un elemento del arreglo.
   * Si son iguales los valores, va a poner primero la query
   * y luego el elemento.
   *
   * De otra manera, los acomoda en orden descendente.
   */

  if (a.val == b.val)
    return a.l > b.l;

  return a.val > b.val;
}

template<typename T>
struct FenwickTree
{
  vector <T> bit;
  FenwickTree (int N) : bit (N + 1, 0) {}

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

  cin >> n;
  vector <int> numbers (n);
  for (int i = 0; i < n; i++)
    cin >> numbers[i];

  cin >> q;
  vector <int> queryK (q);
  vector <int> queryL (q);
  vector <int> queryR (q);
  for (int i = 0; i < q; i++)
    cin >> queryL[i] >> queryR[i] >> queryK[i];

  //Creación de la estructura personalizada de 
  //tamaño suficiente para los elementos y las preguntas
  node a[n + q + 1];

  //Ingresar los elementos del array
  for (int i = 1; i <= n; i++)
    {
      a[i].val = numbers[i - 1];
      a[i].pos = 0;
      a[i].l = 0;
      a[i].r = i;
    }

  //Ingresar las querys;
  for (int i = n + 1; i <= n + q; i++)
    {
      a[i].pos = i - n;
      a[i].val = queryK[i - n - 1];
      a[i].l = queryL[i - n - 1];
      a[i].r = queryR[i - n - 1];
    }

  //Ordenar el arreglo con una función comp auxiliar
  sort (a + 1, a + n + q + 1, comp);

  //Inicialización del BIT
  FenwickTree<int> tree (n);

  //Inicialización del arreglo de respuestas
  //para resolver las queries offline.
  vector <int> ans (q + 1);

  //Procesamiento de las querys y los elementos
  for (int i = 1; i <= n + q; i++)
    {
      //Es una query
      if (a[i].pos != 0)
        {
	  int cnt = tree.sum (a[i].r) - tree.sum (a[i].l - 1);
	  ans[a[i].pos] = cnt;
	}
      //Es un elemento del array. Se actualiza con uno
      else
        tree.add (a[i].r, 1);
    }

  for (int i = 1; i <= q; i++)
    cout << ans[i] << "\n";

  return 0;
}
