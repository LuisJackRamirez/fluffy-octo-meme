#include <bits/stdc++.h>
using namespace std;

int arr[10000006];

int
main (void)
{
  int maxNum = 0;
  int n = 0;
  int num = 0;
  int res = 0;

  cin >> n;

  memset (arr, 0, sizeof (arr));

  for (int i = 0; i < n; i++)
    {
      cin >> num;
      arr[num]++;

      if (num > maxNum)
        maxNum = num;
    }

  cout << arr[maxNum] << "\n";

  return 0;
}
