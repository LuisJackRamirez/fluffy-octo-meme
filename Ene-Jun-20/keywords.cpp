#include <bits/stdc++.h>
using namespace std;

void cleanStr (string &);

int
main (void)
{
  int n = 0;
  string str;
  set <string> keywords;

  cin >> n;

  getline (cin, str);
  for (int i = 0; i < n; i++)
    {
      //cin >> str;
      getline (cin, str);
      cleanStr (str);
      keywords.insert (str);
    }

  cout << keywords.size () << "\n";

  return 0;
}

void
cleanStr (string &str)
{
  for (int i = 0; i < str.length (); i++)
    {
      if (str[i] == '-')
        str[i] = ' ';
      else if (str[i] >= 65 && str[i] <= 90)
        str[i] = str[i] + 32;
    }
}
