#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int
main (void)
{
  int x = 0;
  int y = 0;
 
  scanf ("%d.%d", &x, &y);

  /* Eliminamos el decimal multiplicando por diez.
   * También tenemos que ajustar el 360, entonces
   * 360 * 100 = 36000.
   *
   * GCD (36000, (100 * x) + y) obtiene el ángulo
   * en el que se encuentra la primera rebanada p.
   * Cada rebanada se encuentra a lo largo de los
   * 36000 ángulos en las posiciones p*i, siempre
   * que p*i <= 36000.
   */
  cout << 36000 / __gcd (36000, (100 * x) + y) << "\n";

  return 0;
}
