#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int instruction = 0;
  int accumulator = 0;
  int strValue = 0;

  string strIns;

  vector <string> instructions;
  vector <bool> hasBeenExecutedOnce;

  while (getline (cin, strIns))
    instructions.push_back (strIns);

  hasBeenExecutedOnce.resize (instructions.size ());

  while (hasBeenExecutedOnce[instruction] != true)
    {
      string str;
      char x = '0';
      
      x = instructions[instruction][0];
      hasBeenExecutedOnce[instruction] = true;

      if (x == 'n')
        instruction++;
      else if (x == 'a')
        {
	  for (int i = 4; i < instructions[instruction].size (); i++)
	    {
	      if (instructions[instruction][i] != '+')
	        str.push_back (instructions[instruction][i]);
	    }

	  strValue = stoi (str);
	  accumulator = accumulator + strValue;
 	  instruction++;
	}
      else
        {
	  for (int i = 4; i < instructions[instruction].size (); i++)
	    {
	      if (instructions[instruction][i] != '+')
	        str.push_back (instructions[instruction][i]);
	    }
	 
	  strValue = stoi (str);
	  instruction = instruction + strValue;
	}
    }

  cout << accumulator << "\n";

  return 0;
}
