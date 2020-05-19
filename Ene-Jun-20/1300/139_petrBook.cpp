#include<bits/stdc++.h>
using namespace std;

int
main (void)
{
  int j = 0;
  int n = 0;
  int pages[7];
  int res = 0;
  int sum = 0;

  cin >> n;

  for (int i = 0; i < 7; i++)
    cin >> pages[i];

  while (n > 0)
    {
      if (n > pages[j])
        n = n - pages[j];
      else
        break;

      j = (j + 1) % 7;
    }

  cout << j + 1 << "\n";

  return 0;
}
