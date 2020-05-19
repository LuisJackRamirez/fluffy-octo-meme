#include <bits/stdc++.h>
using namespace std;

void printCincos (int n);
void printZeroes (int n);

int
main (void)
{
  int a = 0;
  int n = 0;
  int zeroes = 0;
  int cincos = 0;

  cin >> n;

  for (int i = 0; i < n; i++)
    {
      cin >> a;

      if (a == 0)
        zeroes++;
      else if (a == 5)
        cincos++;
    }

  if (zeroes == 0)
    cout << "-1\n";
  else if (cincos < 9)
    cout << "0\n";
  else
    {
      printCincos (cincos / 9);
      printZeroes (zeroes);
      cout << "\n";
    }

  return 0;
}

void
printCincos (int n)
{
  for (int i = 0; i < n; i++)
    cout << "555555555";
}

void
printZeroes (int n)
{
  for (int i = 0; i < n; i++)
    cout << "0";
}
