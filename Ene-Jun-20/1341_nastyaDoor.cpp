#include <bits/stdc++.h>
using namespace std;

void getThrowingDistance (vector <int> &, int , int &, int &);

int
main (void)
{
  int t = 0;
  int n = 0;
  int k = 0;
  int a = 0;
  int l = 0;
  int p = 0;

  vector <int> heights;

  cin >> t;

  while (t--)
    {
      cin >> n >> k;
      heights.resize (n);

      for (int i = 0; i < n; i++)
        cin >> heights[i];
     
      getThrowingDistance (heights, k, l, p);

      cout << p << " " << l << "\n";
    }

  return 0;	
}

void
getThrowingDistance (vector <int> &heights, int k, int &l, int &p)
{
  int j = 0;
  int r = 0;
  int minL = 0;
  int maxP = 0;

  l = 0;
  p = 0;

  vector <bool> peaks (heights.size ());

  for (int i = 1; i < heights.size () - 1; i++)
    {
      if (heights[i] > heights[i - 1] && heights[i] > heights[i + 1])
	peaks[i] = true;
    }

  r = l + k - 1;

  for (j = 1; j < r; j++)
    {
      if (peaks[j] && peaks[j - 1] == false && peaks[j + 1] == false)
        p++;
    }

  maxP = p;

  r++;
  l++;

  while (r < heights.size ())
    {
      if (peaks[l])
        p--;
      
      if (peaks[r] == false && peaks[r - 1])
        p++;

      if (p > maxP)
        {
	  minL = l;
	  maxP = p;
	}

      l++;
      r++;
    }

  p = maxP + 1;
  l = minL + 1;

  return;
}
