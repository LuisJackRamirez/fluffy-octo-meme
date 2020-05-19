#include <bits/stdc++.h>
using namespace std;

const int M = 3;
const int N = 3;

void toggle (int [N][M], int, int);

int
main (void)
{
  int lights[N][M];
  //int switches[3][3];
  int buttons = 0;

  for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
        lights[i][j] = 1;
    }

  for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
        {
	  cin >> buttons;

	  if (buttons % 2 != 0)
	    {
	      toggle (lights, i, j);

	      if (i + 1 < M)
 	        toggle (lights, i + 1, j);
	      if (i - 1 >= 0)
	        toggle (lights, i - 1, j);
	      if (j - 1 >= 0)
	        toggle (lights, i, j - 1);
	      if (j + 1 < N)
	        toggle (lights, i, j + 1);
	    }
	}
    }

  for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
	cout << lights[i][j];

      cout << "\n";
    }

  return 0;
}

void
toggle (int lights[N][M], int y, int x)
{
  if (lights[y][x] == 0)
    lights[y][x] = 1;
  else if (lights[y][x] == 1)
    lights[y][x] = 0;
}
