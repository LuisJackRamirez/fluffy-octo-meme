#include <bits/stdc++.h>
using namespace std;

bool isReachable (string, map <string, vector <string>> &, map <string, bool>);

int
main (void)
{
  int res = 0;
  int i = 0;
  int indexFound = 0;
  
  map <string, vector <string>> bags;
  map <string, bool> visited;

  string key;
  string bagContained;
  string str;

  while (getline (cin, str))
    {
      vector <string> contains;

      i = 0;
      indexFound = str.find ("bags");
      key = str.substr (0, indexFound - 1);
      i = indexFound + 13;
      
      visited.insert (make_pair (key, false));

      if (str[i] == 'n')
        {
          bags.insert (make_pair (key, vector <string> (0)));
	  continue;
	}

      while (str[i] != '.')
        {
 	  while (isalpha (str[i]) == 0)
 	    i++;

	  indexFound = str.find ("bag", i);
	  bagContained = str.substr (i, indexFound - 1 - i);
	  contains.push_back (bagContained);
	  i = indexFound + 3;

	  if (str[i] == 's')
	    i++;
	}

      bags.insert (make_pair (key, contains));
    }

  for (auto it = visited.begin (); it != visited.end (); it++)
    {
      if (it->first != "shiny gold")
        {
	  if (isReachable (it->first, bags, visited))
	    res++;
	}
    }

  cout << res << "\n";

  return 0;
}

bool
isReachable (string start, map <string, vector <string>> &bags, map <string, bool> visited)
{
  queue<string> q;

  visited.find (start)->second = true;
  q.push (start);

  while (!q.empty ())
    {
      vector <string> it;

      string s = q.front ();
      q.pop ();

      it = bags.find (s)->second;
      for (int ite = 0; ite < it.size (); ite++)
        {
	  if (it[ite] == "shiny gold")
	    return true;

	  if (visited.find (it[ite])->second == false)
	    {
	      visited.find (it[ite])->second = true;
 	      q.push (it[ite]);
	    }
	}
    }

  return false;
}
