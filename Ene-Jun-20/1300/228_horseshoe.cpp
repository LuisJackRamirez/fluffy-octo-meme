#include <bits/stdc++.h>
using namespace std;

const int size = 4;

int
main (void)
{
  int horseshoes[size];
  int newHs = 0;

  for (int i = 0; i < size; i++)
    cin >> horseshoes[i];

  sort (horseshoes, &horseshoes[3] + 1);

  for (int i = 1; i < size; i++)
    {
      if (horseshoes[i] == horseshoes[i - 1])
        newHs++;
    }  

  cout << newHs << "\n";

  return 0;
}
