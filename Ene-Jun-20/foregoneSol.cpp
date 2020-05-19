#include <bits/stdc++.h>
using namespace std;

void cleanStr (string &);

int
main (void)
{
  int strSize = 0;
  int t = 0;

  string A;
  string B;
  string N;

  cin >> t;

  for (int i = 1; i <= t; i++)
    {
      cin >> N;

      strSize = N.size ();

      A.resize (strSize);
      B.resize (strSize);

      for (int j = 0; j < N.size (); j++)
        {
	  if (N[j] == '4')
	    {
	      A[j] = '3';
	      B[j] = '1';
	    }
	  else
	    {
	      A[j] = N[j];
	      B[j] = '0';
	    }
	}

      cleanStr (A);
      cleanStr (B);

      cout << "Case #" << i << ": " << A << " " << B << "\n";
      N.clear ();
      A.clear ();
      B.clear ();
    }

  return 0;
}

void
cleanStr (string &str)
{
  int i = 0;

  while (str[0] == '0')
    str.erase (0, 1);
}
