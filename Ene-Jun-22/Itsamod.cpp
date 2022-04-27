#include <bits/stdc++.h>
using namespace std;

int 
findSum(int N, int K)
{
    int ans = 0;
    
    int y = N / K;
    int x = N % K;
 
    ans = (K * (K - 1) / 2) * y + (x * (x + 1)) / 2;
 
    return ans;
}

int
main (void)
{
  int n = 0;
  int p = 0;
  int q = 0;
  int w = 0;

  cin >> w;

  while (w--)
    {
      cin >> p >> q >> n;

      int partSum = findSum (n, q);
      cout << p * partSum << "\n";
    }

  return 0;
}
