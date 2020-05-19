#include <bits/stdc++.h>
using namespace std;

int maxIntRatio (vector <int> &pedal, vector <int> &wheel);

int
main (void)
{
  int n = 0;
  int m = 0;
  int res = 0;

  vector <int> pedal;
  vector <int> wheel;

  cin >> n;
  pedal.resize (n);

  for (int i = 0; i < n; i++)
    cin >> pedal[i];

  cin >> m;
  wheel.resize (m);

  for (int i = 0; i < m; i++)
    cin >> wheel[i];

  res = maxIntRatio (pedal, wheel);

  cout << res << "\n";
	
  return 0;
}

int
maxIntRatio (vector <int> &pedal, vector <int> &wheel)
{
  bool foundIntRatio = false;
  int i = 0;
  int j = 0;
  int maxRatio = 0;
  int res = 0;

  for (i = wheel.size () - 1; i >= 0; i--)
    {
      j = 0;

      while (j < pedal.size () && wheel[i] >= pedal[j])
        {
	  if (wheel[i] % pedal[j] == 0)
	    {
 	      foundIntRatio = true;
	      break;
	    }

	  j++;
	}

      if (foundIntRatio)
        break;
    }

  maxRatio = wheel[i] / pedal[j];
  res++;

  i--;

  while (i >= 0)
    {
      j = 0;

      while (j < pedal.size () && wheel[i] >= pedal[j])
        {
	  if (wheel[i] % pedal[j] == 0 && wheel[i] / pedal[j] == maxRatio)
 	    res++;

	  j++;
	}

      i--;
    }

  return res;
}
