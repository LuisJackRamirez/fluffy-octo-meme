#include <bits/stdc++.h>
using namespace std;

bool checkCode (string);

int
main (void)
{
  bool answer = false;
  string str;

  cin >> str;

  answer = checkCode (str);

  if (answer)
    cout << "YES\n";
  else
    cout << "NO\n";  

  return 0;
}

bool
checkCode (string sourceCode)
{
  for (int i = 0; i < sourceCode.length (); i++)
    {
      if (sourceCode[i] == 'H' || sourceCode[i] == 'Q' || sourceCode[i] == '9')
        return true;
    }

  return false;
}
