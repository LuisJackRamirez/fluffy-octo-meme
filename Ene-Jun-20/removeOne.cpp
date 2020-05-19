#include <bits/stdc++.h>
using namespace std;

int maxRightLength (vector <int> &, int *, int);
int maxLeftLength (vector <int> &, int *, int);

int
main (void)
{
  int a = 0;
  int n = 0;
  int res = 0;

  vector <int> array;

  cin >> n; 
  array.resize (n);

  int l[n];
  memset (l, -1, sizeof (l));
  int r[n];
  memset (r, -1, sizeof (r));

  for (int i = 0; i < n; i++)
    cin >> array[i];

  for (int i = 0; i < n; i++)
    r[i] = maxRightLength (array, r, i);

  for (int i = n - 1; i >= 0; i--)
    {
      l[i] = maxLeftLength (array, l, i);
      
      if (l[i] > res)
        res = l[i];
    }

  

  for (int i = 1; i < n - 1; i++)
    {
      if (array[i - 1] < array[i + 1])
        {
	  a = l[i - 1] + r[i + 1];

	  if (a > res)
	    res = a;
	}
    }

  cout << res << "\n";

  return 0;
}

int
maxRightLength (vector <int> &array, int *r, int index)
{
  if (index == array.size () - 1)
    return r[index] = 1;

  if (r[index] == -1)
    {
      if (array[index] < array[index + 1])
        {
	  r[index] = maxRightLength (array, r, index + 1) + 1;
	  return r[index];
	}
      else
        return r[index] = 1;
    }
  else
    return r[index];
}

int
maxLeftLength (vector <int> &array, int *l, int index)
{
  if (index == 0)
    return l[index] = 1;

  if (l[index] == -1)
    {
      if (array[index] > array[index - 1])
        {
	  l[index] = maxLeftLength (array, l, index - 1) + 1;
	  return l[index];
	}
      else
        return l[index] = 1;
    }
  else
    return l[index];
}
