#include<bits/stdc++.h>
using namespace std;

int
main (void)
{
  int friends[3] = {0, 0, 0};

  for (int i = 0; i < 3; i++)
    cin >> friends[i];

  sort (friends, &friends[3]);

  cout << friends[2] - friends[0] << "\n";

  return 0;
}
