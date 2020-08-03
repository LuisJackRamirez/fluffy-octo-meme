#include <bits/stdc++.h>
using namespace std;

void unLeet (string &);

int
main (void)
{
  int N = 0;
  int M = 0;
  bool badWord = false;

  vector <string> badWords;
  vector <string> plates;

  cin >> N >> M;
  badWords.resize (N);
  plates.resize (M);

  for (int i = 0; i < N; i++)
    cin >> badWords[i];

  for (int i = 0; i < M; i++)
    {
      cin >> plates[i];
      unLeet (plates[i]);
    }

  for (int i = 0; i < M; i++)
    {
      badWord = false;

      for (int j = 0; j < N; j++)
        {
          if (plates[i].find (badWords[j]) != string::npos)
	    {
	      badWord = true;
	      break;
	    }
	}

      if (badWord)
        cout << "INVALID\n";
      else
        cout << "VALID\n";
    }

  return 0;
}

void
unLeet (string &str)
{
  for (int i = 0; i < str.length (); i++)
    {
      if (str[i] == '0')
        str[i] = 'O';
      else if (str[i] == '1')
        str[i] = 'L';
      else if (str[i] == '2')
        str[i] = 'Z';
      else if (str[i] == '3')
        str[i] = 'E';
      else if (str[i] == '5')
        str[i] = 'S';
      else if (str[i] == '6')
        str[i] = 'B';
      else if (str[i] == '7')
        str[i] = 'T';
      else if (str[i] == '8')
        str[i] = 'B';
    }
}
