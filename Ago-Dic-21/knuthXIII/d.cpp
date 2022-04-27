#include <bits/stdc++.h>
using namespace std;

string
figurativeSpeak (string str)
{
  for (int i = 0; i < str.length (); i++)
    {
      if (str[i] == 'O' || str[i] == 'o')
        str[i] = '0';
      else if (str[i] == 'I' || str[i] == 'i')
        str[i] = '1';
      else if (str[i] == 'Z' || str[i] == 'z')
        str[i] = '2';
      else if (str[i] == 'E' || str[i] == 'e')
        str[i] = '3';
      else if (str[i] == 'A' || str[i] == 'a')
        str[i] = '4';
      else if (str[i] == 'S' || str[i] == 's')
        str[i] = '5';
      else if (str[i] == 'G' || str[i] == 'g')
        str[i] = '6';
      else if (str[i] == 'T' || str[i] == 't')
        str[i] = '7';
      else if (str[i] == 'B' || str[i] == 'b')
        str[i] = '8';
    }

  return str;
}

int
main (void)
{
  string str;

  cin >> str;
  cout << figurativeSpeak (str) << "\n";

  return 0;
}
