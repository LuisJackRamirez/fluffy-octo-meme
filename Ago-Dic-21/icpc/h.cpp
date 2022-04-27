#include <bits/stdc++.h>
using namespace std;

bool
handlingBlocks (vector <int> &blocks, vector <int> &colours, int n, int k)
{
  if (k == 1)
    return true;

  for (int i = 1; i <= n; i++)
    {
      if (blocks[i] != i)
        {
	  if (colours[blocks[i]] != colours[i])
	    return false;

	  swap (blocks[i], blocks[blocks[i]]);
	}
    }

  return true;
}

int
main (void)
{
  int n = 0;
  int k = 0;

  cin >> n >> k;

  vector <int> blocks (n + 1);
  vector <int> colours (n + 1);

  for (int i = 1; i <= n; i++)
    cin >> blocks[i] >> colours[i];

  if (handlingBlocks (blocks, colours, n, k) == true)
    cout << "Y\n";
  else
    cout << "N\n";  

  return 0;
}
