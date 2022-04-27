#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

void
factorize (int n, vector <int> &pr, vector <int> &e)
{
  for (int p = 2; p*p <= n; p++)
    {
      if (n % p == 0)
        {
	  int exp = 0;
	  while (n % p == 0)
	    {
	      n /= p;
	      exp++;
	    }

	  pr.push_back (p);
	  e.push_back (exp);
	}
    }

  if (n > 1)
    {
      pr.push_back (n);
      e.push_back (1);
    }

  return;
}

int
processStr (string str)
{
  int e = 0;
  int numNums = 0;
  int p = 0;
  int res = 0;
  string num;

  for (int i = 0; i <= str.length (); i++)
    {
      if (isdigit (str[i]))
	num.push_back (str[i]);
      else
	{
	  if (numNums % 2 == 0)
	    p = stoi (num);
	  else
	    {
	      e = stoi (num);

	      if (numNums == 1)
                res = pow (p, e);
	      else
	        res = res * pow (p, e);
	    }

	  numNums++;
	  num.clear ();
	}
    }

  return res;
}

int
main (void)
{
  string str;

  while (getline (cin, str))
    {
      if (str.length () == 1 && stoi (str) == 0)
	break;

      int num = processStr (str) - 1;

      vector <int> p;
      vector <int> e;
      factorize (num, p, e);

      for (int i = p.size () - 1; i >= 0; i--) 
        {
          cout << p[i] << " " << e[i];
	  if (i == 0)
	    cout << "\n";
	  else
	    cout << " ";
	}
    }

  return 0;
}
