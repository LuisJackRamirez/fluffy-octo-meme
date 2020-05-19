#include <bits/stdc++.h>
using namespace std;

int lightningStrike (int);
int voidAbsorption (int, int);

int
main (void)
{
  int m = 0;
  int n = 0;
  int t = 0;
  int x = 0;
  int total = 0;

  cin >> t;

  while (t--)
    {
      cin >> x >> n >> m;

      total = voidAbsorption (x, n);
      total = total - lightningStrike (m);

      if (total <= 0)
        cout << "YES\n";
      else
        cout << "NO\n";
    }

  return 0;
}

int
lightningStrike (int m)
{
  return m * 10;
}

int
voidAbsorption (int x, int n)
{
  int damage = 0;
  int aux = 0;

  damage = x;

  while (n--)
    {
      aux = (damage / 2) + 10;

      if (aux >= damage)
        break;
      else
        damage = (damage / 2) + 10;
    }

  return damage;
}
