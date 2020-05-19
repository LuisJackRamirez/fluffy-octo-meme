#include <bits/stdc++.h>
using namespace std;

int maxSum (vector <int> &);

int
main (void)
{
  int t = 0;
  int n = 0;
  int res = 0;

  vector <int> array;

  cin >> t;

  while (t--)
    {
      cin >> n;
      array.resize (n);

      for (int i = 0; i < n; i++)
        cin >> array[i];

      res = maxSum (array);
    }

  return 0;
}

int
maxSum (vector <int> &array)
{
  bool sign = false;

  int i = 0;
  int max = 0;
  int res = 0;

  if (array[0] < 0)
    sign = false;
  else
    sign = true;

  max = array[0];

  for (i = 0; i < array.size (); i++)
    {
      if (sign == false)
        {
	  while (array[i] < 0 && i < array.size ())
	    {
	      if (array[i] > max)
	        max = array[i];

	      i++;
	    }

	  res = res + max;

	  if (i < array.size ())
	    max = array[i];
	}
      else
        {
	  while (array[i] > 0 && i < array.size ())
	    {
	      if (array[i] > max)
	        max = array[i];

	      i++;
	    }

	  res = res + max;

	  if (i < array.size ())
	    max = array[i];
	}
    }

  return res;
}
