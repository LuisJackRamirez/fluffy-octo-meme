#include <bits/stdc++.h>
using namespace std;

bool executeCode (vector <string> &, int &);

int
main (void)
{
  int accumulator = 0;
  int numIns = 0;
  int strValue = 0;

  string strIns;
  string temp;

  vector <string> instructions;
  vector <int> nopJmps;

  while (getline (cin, strIns))
    {
      instructions.push_back (strIns);

      if (strIns[0] == 'n' || strIns[0] == 'j')
        nopJmps.push_back (numIns);

      numIns++;
    }

  for (int i:nopJmps)
    {
      accumulator = 0;

      temp = instructions[i];
      if (instructions[i][0] == 'j')
	instructions[i][0] = 'n';
      else
	instructions[i][0] = 'j';

      if (executeCode (instructions, accumulator))
        {
	  cout << accumulator << "\n";
	  break;
	}

      instructions[i] = temp;
    }

  return 0;
}

bool
executeCode (vector <string> &instructions, int &accumulator)
{
  int instruction = 0;
  int strValue = 0;

  vector <bool> hasBeenExecutedOnce;

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

      if (instruction == instructions.size ())
        return true;
    }

  return false;
}
