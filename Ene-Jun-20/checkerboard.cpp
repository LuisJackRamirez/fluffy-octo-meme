#include <bits/stdc++.h>
using namespace std;

vector < vector < char >>checkerboard (int R, int C, vector < int >A,
				       vector < int >B);

int
main (void)
{
  int R = 0;
  int C = 0;
  int aNum = 0;
  int bNum = 0;

  vector < int >A;
  vector < int >B;

  cin >> R >> C >> aNum >> bNum;

  vector < vector < char >>flag (R, vector < char >(C));
  A.resize (aNum);
  B.resize (bNum);

  for (int i = 0; i < aNum; i++)
    cin >> A[i];

  for (int i = 0; i < bNum; i++)
    cin >> B[i];

  flag = checkerboard (R, C, A, B);

  for (int i = 0; i < R; i++)
    {
      for (int j = 0; j < C; j++)
	cout << flag[i][j];

      cout << "\n";
    }

  return 0;
}

vector < vector < char >>
checkerboard (int R, int C, vector < int >A, vector < int >B)
{
  int colorCol = 0;
  int colorRow = 0;
  int i = 0;
  int j = 0;
  int a = 0;
  int b = 0;
  int m = 0;
  int n = 0;

  vector < vector < char >>flag (R, vector < char >(C));

  colorRow = 1;

  for (m = 0; m < A.size (); m++)
    {
      while (a < A[m])
	{
	  colorCol = colorRow;
	  j = 0;

	  for (n = 0; n < B.size (); n++)
	    {
	      while (b < B[n])
		{
		  if (colorCol == 1)
		    flag[i][j] = 'B';
		  else
		    flag[i][j] = 'W';

		  j++;
		  b++;
		}

	      colorCol *= -1;
	      b = 0;
	    }

	  i++;
	  a++;
	}

      colorRow *= -1;
      a = 0;
    }

  return flag;
}
