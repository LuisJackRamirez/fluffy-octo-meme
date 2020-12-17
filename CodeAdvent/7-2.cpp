#include <bits/stdc++.h>
using namespace std;

int
getNumBags (string, map <string, vector <pair <string, int>>> &, map <string, int> &);

int
main (void)
{
  int res = 0;
  int i = 0;
  int numBags = 0;
  int indexFound = 0;
  
  map <string, vector <pair <string, int>>> bags;
  map <string, int> numBagsContained;

  string key;
  string bagContained;
  string str;

  while (getline (cin, str))
    {
      vector <pair<string, int>> contains;

      i = 0;
      indexFound = str.find ("bags");
      key = str.substr (0, indexFound - 1);
      numBagsContained.insert (make_pair (key, -1));

      //Número de bolsas de ese color
      i = indexFound + 13;
      if (str[i] == 'n')
        {
          bags.insert (make_pair (key, vector <pair <string, int>> (0)));
	  continue;
	}

      while (str[i] != '.')
        {
	  string num;

	  while (isdigit (str[i]) == 0)
	    i++;

	  while (isdigit (str[i]) == 1)
	    {
	      num.push_back (str[i]);
	      i++;
	    }

	  numBags = stoi (num);

 	  while (isalpha (str[i]) == 0)
 	    i++;

	  indexFound = str.find ("bag", i);
	  bagContained = str.substr (i, indexFound - 1 - i);
	  contains.push_back (make_pair (bagContained, numBags));
	  i = indexFound + 3;

	  if (str[i] == 's')
	    i++;
	}

      bags.insert (make_pair (key, contains));
    }

  //it es un iterador en el vector de pares bolsa-número
  for (auto it:bags.find ("shiny gold")->second)
    {
      map <string, int>::iterator findResult;

      findResult = numBagsContained.find (it.first);
      if (findResult->second == -1)
	findResult->second = getNumBags (it.first, bags, numBagsContained);

      res = res + (it.second * (1 + findResult->second));
    }

  cout << res << "\n";

  return 0;
}

int
getNumBags (string bagColour, map <string, vector <pair <string, int>>> &bags, map <string, int> &numBagsContained)
{
  int res = 0;

  if (bags.find (bagColour)->second.size () == 0)
    {
      numBagsContained.find (bagColour)->second = 0;
      return 0;
    }

  for (auto it:bags.find (bagColour)->second)
    {
      map <string, int>::iterator findResult;

      findResult = numBagsContained.find (it.first);
      if (findResult->second == -1)
        findResult->second = getNumBags (it.first, bags, numBagsContained);
	
      res = res + (it.second * (1 + findResult->second));
    }

  return res;
}
