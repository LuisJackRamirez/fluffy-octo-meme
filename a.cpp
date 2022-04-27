#include <bits/stdc++.h>
using namespace std;

int res = 0;

void
paint (vector <string> &picture, int i, int j, char x)
{
  picture[i][j] = 'x';

  if (i - 1 >= 0 && picture[i - 1][j] == x)
    paint (picture, i - 1, j, x);
  if (i + 1 < picture.size () && picture[i + 1][j] == x)
    paint (picture, i + 1, j, x);
  if (j - 1 >= 0 && picture[i][j - 1] == x)
    paint (picture, i, j - 1, x);
  if (j + 1 < picture[i].size () && picture[i][j + 1] == x)
    paint (picture, i, j + 1, x);
}

int
bucketFill (vector <string> picture)
{
  for (int i = 0; i < picture.size (); i++)
    {
      for (int j = 0; j < picture[i].size (); j++)
        {
	  if ((picture[i][j]) != 'x')
	    {
	      paint (picture, i, j, picture[i][j]);
	      res++;
	    }
	}
    }

  return res;
}

int
main (void)
{
  int h = 0;
  string str;
  vector <string> picture;

  cin >> h;
  for (int i = 0; i < h; i++)
    {
      cin >> str;
      picture.push_back (str);
    }

  cout << bucketFill (picture) << "\n";

  return 0;
}
