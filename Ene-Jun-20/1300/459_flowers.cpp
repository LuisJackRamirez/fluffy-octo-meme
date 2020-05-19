#include <bits/stdc++.h>
using namespace std;

void numberWays (vector <int> &, long long int &, long long int &);

int
main (void)
{
  int n = 0;
  int res = 0;
  long long int ways = 0;
  long long int beauty = 0;

  vector <int> beauties;

  cin >> n;
  beauties.resize (n);

  for (int i = 0; i < n; i++)
    cin >> beauties[i];

  numberWays (beauties, ways, beauty);

  cout << beauty << " " << ways << "\n";

  return 0;
}

void
numberWays (vector <int> &beauties, long long int &ways, long long int &beauty)
{
  bool allEqual = true;

  int a = 0;
  int b = 0;
  long long int countA = 0;
  long long int countB = 0;
  int diff = 0;
  int i = 0;
  int lastNum = 0;
  int res = 0;

  sort (beauties.begin (), beauties.end ());

  i = beauties.size () - 1;
  a = beauties[0];
  b = beauties[i];

  diff = abs (a - b);

  while (beauties[i] == b && i >= 0)
    {
      countB++;
      i--;
    }

  i = 0;

  while (beauties[i] == a && i < beauties.size ())
    {
      countA++;
      i++;
    }

  if (beauties[0] == beauties[beauties.size () - 1])
    ways = beauties.size () * (beauties.size () - 1) / 2;
  else
    ways = countA * countB;

  beauty = diff;

  return;
}
