#include <bits/stdc++.h>
using namespace std;

long long int countTrees (vector <string> &, int, int);

int
main (void)
{
  string str;
  long long int trees = 0;
  long long int res = 0;
  vector <string> area;

  while (getline (cin, str))
    area.push_back (str);

  for (int i = 1; i <= 7; i = i + 2)
    {
      trees = countTrees (area, i, 1);

      if (i == 1)
        res = trees;
      else
        res = res * trees;
    }

  res = res * countTrees (area, 1, 2);
  cout << res << "\n";

  return 0;
}

long long int
countTrees (vector <string> &area, int dx, int dy)
{
  int positionX = 0;
  long long int res = 0;

  for (int i = 0; i < area.size (); i = i + dy)
    {
      if (area[i][positionX] == '#')
        res++;

      positionX = (positionX + dx) % area[0].size ();
    }

  return res;
}
