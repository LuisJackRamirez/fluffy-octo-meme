#include <bits/stdc++.h>
using namespace std;

void increment (string &, int &, int);

int
main (void)
{
  int k = 0;
  int ocurrences = 0;
  int res = 0;
  string a;
  string b;

  cin >> a >> b >> k;

  for (int i = 0; i < a.length (); i++)
    {
      if (a[i] - '0' == k)
        ocurrences++;
    }

  res = ocurrences;

  while (a != b)
    {
      increment (a, ocurrences, k);
      res = res + ocurrences;
    }

  cout << res << "\n";

  return 0;
}

void
increment (string &a, int &ocurrences, int k)
{
  bool residue = false;
  int i = 0;

  i = a.length () - 1;

  if (a[i] == '9')
    {
      residue = true;

      if (a[i] - '0' == k)
        ocurrences--;

      a[i] = '0';
      if (a[i] - '0' == k)
        ocurrences++;
	      
      i--;

      while (residue && i >= 0)
        {
	  if (a[i] == '9')
	    {
	      if (a[i] - '0' == k)
	        ocurrences--;

	      a[i] = '0';
	      if (a[i] - '0' == k)
	        ocurrences++;

	      i--;
	    }
	  else
	    {
	      residue = false;

	      if (a[i] - '0' == k)
	        ocurrences--;

	      a[i]++;
	      if (a[i] - '0' == k)
	        ocurrences++;
	    }
	}
    }
  else
    {
      if (a[i] - '0' == k)
        ocurrences--;

      a[i]++;
      if (a[i] - '0' == k)
        ocurrences++;
    }
}
