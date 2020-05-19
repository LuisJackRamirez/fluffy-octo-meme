#include <bits/stdc++.h>
using namespace std;

vector <string> getResultingField (vector <string>, int, int);
void printField (vector <string> &);

int
main (void)
{
  int x = 0;
  int y = 0;
  
  string row;
  string aux;

  vector <string> field;
  vector <string> res;

  for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 3; j++)
        {
          cin >> aux;
	  row.append (aux);
	  aux.clear ();
	}

      field.push_back (row);
      row.clear ();
      aux.clear ();
    }

  cin >> y >> x;

  res = getResultingField (field, x, y);

  printField (res);

  return 0;
}

vector <string>
getResultingField (vector <string> field, int x, int y)
{
  bool noValidMove = true;
  int xBigField = 0;
  int yBigField = 0;
  int xNextField = 0;
  int yNextField = 0;

  xBigField = (x - 1) / 3;
  yBigField = (y - 1) / 3;

  x = (x - 1) % 3;
  xNextField = x;
  y = (y - 1) % 3;
  yNextField = y;

  for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
        {
	  if (field[i + (3 * yNextField)][j + (3 * xNextField)] == '.')
	    {
	      noValidMove = false;
	      field[i + (3 * yNextField)][j + (3 * xNextField)] = '!';
	    }
	}
    }

  if (noValidMove)
    {
      for (int i = 0; i < 9; i++)
        {
          for (int j = 0; j < 9; j++)
            {
   	      if (field[i][j] == '.')
	        field[i][j] = '!';
	    } 
        }
    }

  return field;
}

void
printField (vector <string> &field)
{
  for (int i = 0; i < 9; i++)
    {
      if (i % 3 == 0 && i != 0)
        cout << "\n";

      for (int j = 0; j < 9; j++)
        {
          if (j % 3 == 0 && j != 0)
	    cout << " ";
	  
	  cout << field[i][j];
	}

      cout << "\n";
    }
}
