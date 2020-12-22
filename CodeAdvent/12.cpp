#include <bits/stdc++.h>
using namespace std;
        
void sumDir (char, int &, int &, int);
int changeDir (int, int);

int
main (void)
{
  char direccion[4] = {'N', 'E', 'S', 'W'};
  int dir = 0;
  int x = 0;
  int y = 0;
  string str;

  dir = 1;

  while (getline (cin, str))
    {
      int value = stoi (str.substr (1));

      if (str[0] == 'F')
        sumDir (direccion[dir], x, y, value);
      else if (str[0] == 'L')
        dir = changeDir (dir, -value);
      else if (str[0] == 'R')
        dir = changeDir (dir, value);
      else
        sumDir (str[0], x, y, value);
    }

  cout << abs (x) + abs (y) << "\n";

  return 0;
}

void 
sumDir (char letra, int &x, int &y, int value)
{
  if (letra == 'N')
    y = y + value;
  else if (letra == 'S')
    y = y - value;
  else if (letra == 'E')
    x = x + value;
  else if (letra == 'W')
    x = x - value;
}

int 
changeDir (int dir, int valor)
{
  int x = 0;

  x = (dir + (valor / 90)) % 4;

  if (x < 0)
    x = x + 4;

  return x;
}
