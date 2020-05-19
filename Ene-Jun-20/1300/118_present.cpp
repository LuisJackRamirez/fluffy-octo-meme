#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> obtainHandkerchief (int);
void printHandkerchief (vector <vector <int>> &);
void printSpaces (int);

int
main (void)
{
  int n = 0;

  vector <vector <int>> handkerchief;
  
  cin >> n;

  handkerchief = obtainHandkerchief (n);
  printHandkerchief (handkerchief);

  return 0;
}

vector <vector <int>>
obtainHandkerchief (int n)
{
  vector <int> aux;
  vector <vector <int>> handkerchief;

  while (n >= 0)
    {
      for (int i = 0; i <= n; i++)
        aux.push_back (i);

      for (int i = n - 1; i >= 0; i--)
        aux.push_back (i);

      handkerchief.push_back (aux);

      n--;
      aux.clear ();
    }

  return handkerchief;
}

void
printHandkerchief (vector <vector <int>> &handkerchief)
{
  int a = 0;

  a = handkerchief.size () - 1;

  while (a >= 0)
    {
      printSpaces (a);

      for (int i = 0; i < handkerchief[a].size () - 1; i++)
        cout << handkerchief[a][i] << " ";

      cout << handkerchief[a][handkerchief[a].size () - 1];

      cout << "\n";
      a--;
    }

  a = 1;
  while (a < handkerchief.size ())
    {
      printSpaces (a);

      for (int i = 0; i < handkerchief[a].size () - 1; i++)
        cout << handkerchief[a][i] << " ";

      cout << handkerchief[a][handkerchief[a].size () - 1];

      cout << "\n";
      a++;
    }
}

void
printSpaces (int a)
{
  for (int i = 0; i < 2 * a; i++)
    cout << " ";
}
