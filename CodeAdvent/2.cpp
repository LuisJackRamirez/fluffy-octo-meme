#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  char x = '0';
  int i = 0;
  int minimumNumber = 0;
  int maximumNumber = 0;
  int givenLetterCount = 0;
  int res = 0;
  string buffer;		//To parse strings to integers
  string password;
  string str;

  while (getline (cin, str))
    {
      i = 0;
      givenLetterCount = 0;

      while (str[i] != ' ')
        {
	  if (str[i] == '-')
	    {
	      minimumNumber = stoi (buffer);
	      buffer.clear ();
	    }
	  else
	    buffer.push_back (str[i]);

	  i++;
	}

      maximumNumber = stoi (buffer);
      buffer.clear ();

      x = str[++i];
      i = i + 3;

      password = str.substr (i);

      if (password[minimumNumber - 1] == x)
        givenLetterCount++;
      
      if (password[maximumNumber - 1] == x)
        givenLetterCount++;

      if (givenLetterCount == 1)
        res++;
    }

  cout << res << "\n";

  return 0;
}
