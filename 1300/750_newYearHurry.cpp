#include <bits/stdc++.h>
using namespace std;

int dpTable[11];

int dp (int);
int binary (int, int);
bool checkSolution (int, int);

int
main (void)
{
  int n = 0;
  int k = 0;
  int time = 0;
  int res = 0;

  cin >> n >> k;

  memset (dpTable, -1, sizeof (dpTable));

  time = 240 - k;

  if (time < 5)
    {
      cout << "0\n";
      return 0;
    }

  res = binary (n, time);

  cout << res << "\n";

  return 0;
}

int
dp (int index)
{
  if (dpTable[index] != -1)
    return dpTable[index];
  else
    {
      if (index == 0)
        return 0;
      else 
        {
	  dpTable[index] = dp (index - 1) + (index * 5);
	  return dpTable[index];
	}
    }
}

int
binary (int n, int time)
{
  int l = 0;
  int r = 0;
  int res = 0;
  int m = 0;
  int i = 0;

  r = n + 1;

  while (l < r && i < 30)
    {
      m = l + ((r - l) / 2);

      if (checkSolution (m, time))
        {
	  res = m;
	  l = m;
	}
      else
        r = m;

      i++;
    }

  return res;
}

bool
checkSolution (int m, int time)
{
  if (dp(m) <= time)
    return true;
  else
    return false;  
}













