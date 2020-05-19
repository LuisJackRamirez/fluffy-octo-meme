#include <bits/stdc++.h>
using namespace std;

int petyaStr (string, string);
void lowerCase (string &);

int
main (void)
{
  int res = 0;

  string str1;
  string str2;

  cin >> str1 >> str2;

  lowerCase (str1);
  lowerCase (str2);

  res = petyaStr (str1, str2);

  cout << res << "\n";

  return 0;
}

void
lowerCase (string &str)
{
  for (int i = 0; i < str.length (); i++)
    {
      if (str[i] >= 65 && str[i] <= 90)
        str[i] = str[i] + 32;
    }
}

int
petyaStr (string s1, string s2)
{
  for (int i = 0; i < s1.length (); i++)
    {
      if (s1[i] < s2[i])
        return -1;
      else if (s1[i] > s2[i])
        return 1;
    }

  return 0;
}
