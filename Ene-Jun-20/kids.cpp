#include <bits/stdc++.h>
using namespace std;

int kidsEntertainment (string &);
int getOnes (string &);
string getNum (int);

int
main (void)
{
  int t = 0;
  string str;

  cin >> t;

  while (t--)
    {
      cin >> str;

      cout << kidsEntertainment (str) << "\n";
    }

  return 0;
}

int
kidsEntertainment (string &str)
{
  int res = 0;
  string X;
  string Y;

  X = getNum (str[0] - '0');
  Y = getNum (str[1] - '0');

  res = getOnes (X) + getOnes (Y);
  
  if (str[0] != '1')
    {
      if (X[1] == Y[5] && X[2] == Y[4])
        res = res - (X[1] - '0') - (X[2] - '0');
    }

  return res;
}

string
getNum (int x)
{
  switch (x)
    {
      case 0:
        return "1111110";
	break;

      case 1:
        return "0110000";
	break;

      case 2:
        return "1101101";
	break;

      case 3:
        return "1111001";
	break;

      case 4:
        return "0110011";
	break;

      case 5:
        return "1011011";
	break;

      case 6:
        return "1011111";
	break;

      case 7:
        return "1110000";
	break;

      case 8:
        return "1111111";
	break;

      case 9:
        return "1111011";
	break;
    }
}

int
getOnes (string &str)
{
  int res = 0;

  for (int i = 0; i < str.length (); i++)
    {
      if (str[i] == '1')
        res++;
    }

  return res;
}
