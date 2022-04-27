#include <bits/stdc++.h>
using namespace std;

bool
canSurroundWolf (vector < string > &field, int rows, int columns, int x,
		 int y)
{
  if (y - 1 >= 0) 
    {
      if (field[x][y - 1] == 'S')
        return false;
      else if (field[x][y - 1] == '.')
        field[x][y - 1] = 'D';
    }
    
  if (y + 1 < columns)
    {
      if (field[x][y + 1] == 'S')
        return false;
      else if (field[x][y + 1] == '.')
        field[x][y + 1] = 'D';
    }
  
  if (x - 1 >= 0)
    {
      if (field[x - 1][y] == 'S')
        return false;
      else if (field[x - 1][y] == '.')
        field[x - 1][y] = 'D';
    }
  
  if (x + 1 < rows)
    {
      if (field[x + 1][y] == 'S')
        return false;
      else if (field[x + 1][y] == '.')
        field[x + 1][y] = 'D';
    }

  return true;
}

bool
canPlaceDogs (vector < string > &field, int rows, int columns)
{
  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < columns; j++)
	{
	  if (field[i][j] == 'W')
	    {
	      if (canSurroundWolf (field, rows, columns, i, j) == false)
		return false;
	    }
	}
    }

  return true;
}

int
main (void)
{
  int r = 0;
  int c = 0;

  cin >> r >> c;
  vector < string > field (r);

  for (int i = 0; i < r; i++)
    cin >> field[i];

  if (canPlaceDogs (field, r, c))
    {
      cout << "Yes\n";
      
      for (string x:field)
	cout << x << "\n";
    }
  else
    cout << "No\n";

  return 0;
}
