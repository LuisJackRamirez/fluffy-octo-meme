#include <bits/stdc++.h>
using namespace std;

vector <int> getResult (int n);
void printResult (vector <int> &);

int
main (void)
{
  int t = 0;
  int n = 0;

  vector <int> res;

  cin >> t;

  while (t--)
    {
      cin >> n;

      res = getResult (n);
      printResult (res);
    }

  return 0;
}

vector <int>
getResult (int n)
{
  int num = 0;

  string str;
  vector <int> res;

  str = to_string (n);

  for (int i = 0; i < str.size (); i++)
    {
      if (str[i] != '0')
        {
	  num = (str[i] - '0') * pow (10, str.size () - i - 1);
	  res.push_back (num);
	}
    }
  
  return res;
}

void
printResult (vector <int> &res)
{
  cout << res.size () << "\n";

  for (int i = 0; i < res.size (); i++)
    cout << res[i] << " ";

  cout << "\n";
}
