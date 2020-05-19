#include <bits/stdc++.h>
using namespace std;

string strXor (string, string);

int
main (void)
{
  string str1;
  string str2;
  string strRes;

  cin >> str1 >> str2;

  strRes = strXor (str1, str2);

  cout << strRes << "\n";

  return 0;
}

string
strXor (string s1, string s2)
{
  string str;

  for (int i = 0; i < s1.length (); i++)
    {
      if (s1[i] == s2[i])
        str.push_back ('0');
      else
        str.push_back ('1');
    }

  return str;
}
