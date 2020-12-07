#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int res = 0;
  int peopleInGroup = 0;
  int questions[26];
  string str;

  memset (questions, 0, sizeof (questions));
  while (getline (cin, str))
    {
      if (str != "")
	{
	  for (int i = 0; i < str.size (); i++)
	    questions[str[i] - 'a']++;

	  peopleInGroup++;
	}
      else
	{
	  for (int i = 0; i < 26; i++)
	    {
	      if (questions[i] == peopleInGroup)
		res++;
	    }

	  peopleInGroup = 0;
	  memset (questions, 0, sizeof (questions));
	}
    }

  for (int i = 0; i < 26; i++)
    {
      if (questions[i] == peopleInGroup)
	res++;
    }

  cout << res << "\n";

  return 0;
}
