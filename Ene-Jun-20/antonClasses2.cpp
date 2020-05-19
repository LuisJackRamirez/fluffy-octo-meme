#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int m = 0;
  int maxLeftChess = 0;
  int maxLeftProg = 0;
  int minRightChess = 0;
  int minRightProg = 0;
  int n = 0;
  int res = 0;

  vector <pair <int, int>> chess;
  vector <pair <int, int>> programming;

  maxLeftChess = -1;
  maxLeftProg = -1;
  minRightChess = 1000000005;
  minRightProg = 1000000005;

  cin >> n;
  chess.resize (n);

  for (int i = 0; i < n; i++)
    cin >> chess[i].first >> chess[i].second;

  cin >> m;
  programming.resize (m);

  for (int i = 0; i < m; i++)
    cin >> programming[i].first >> programming[i].second;

  for (int i = 0; i < n; i++)
    {
      maxLeftChess = max (maxLeftChess, chess[i].first);
      minRightChess = min (minRightChess, chess[i].second);
    }

  for (int i = 0; i < m; i++)
    {
      maxLeftProg = max (maxLeftProg, programming[i].first);
      minRightProg = min (minRightProg, programming[i].second);
    }

  res = max (maxLeftProg - minRightChess, maxLeftChess - minRightProg);

  cout << max (res, 0) << "\n";

  return 0;
}
