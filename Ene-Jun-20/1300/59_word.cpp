#include <bits/stdc++.h>
using namespace std;

string toUpper (string);
string toLower (string);

int
main (void)
{
  int i = 0;
  int uppercase = 0;

  string str;
  string sortedStr;

  cin >> str;
  
  sortedStr = str;
  sort (sortedStr.begin (), sortedStr.end ());  

  while (sortedStr[i] >= 65 && sortedStr[i] <= 90)
    {
      uppercase++;
      i++;
    }

  if (uppercase > (str.length () - uppercase))
    cout << toUpper (str) << "\n";
  else 
    cout << toLower (str) << "\n";

  return 0;
}

string
toUpper (string s)
{
  for (int i = 0; i < s.length (); i++)
    if (s[i] >= 97 && s[i] <= 122)
      s[i] = s[i] - 32;

  return s;
}

string
toLower (string s)
{
  for (int i = 0; i < s.length (); i++)
    if (s[i] >= 65 && s[i] <= 90)
      s[i] = s[i] + 32;

  return s;
}
