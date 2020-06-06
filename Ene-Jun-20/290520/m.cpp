#include <bits/stdc++.h>
using namespace std;

string evaluat (string);
string strXor (string, string);
string strAnd (string, string);
string strOr (string, string);

int
main (void)
{
  int t = 0;
  string str;

  cin >> t;

  while (t--)
    {
      cin >> str;

      cout << evaluate (str) << "\n";
    }

  return 0;
}

string
evaluate (string str)
{
  stack <string> values;
  stack <string> ops;
  
  string aux;
  string A;
  string B;
  string op;

  for (int i = 0; i < str.length (); i++)
    {
      //whitespace
      if (tokens[i] == ' ')
        continue;

      //opening bracket
      else if (str[i] == '(')
        ops.push ("(");

      //number
      else if (str[i] == '1' || str[i] == '0')
        {
	  while (i < str.length () && (str[i] == '1' || str[i] == '0'))
	    {
	      aux.push_back (str[i]);
	      i++;
	    }

	  values.push (aux);
	  aux.clear ();
	}
      
      //closing bracket
      else if (str[i] == ')')
        {
	  while (ops.empty () == false && ops.top != "(")
	    {
	      A = values.top ();
	      values.pop ();
	      B = values.top ();
	      values.pop ();

	      op = ops.top ();
	      ops.pop ();

	      values.push (applyOp (A, B, op));
	    }

	  //pop opening bracket
	  if (ops.empty () == false)
	    ops.pop ();
	}

      else
        {
	  while (ops.empty () == false)
	    {
	      B = values.top ();
	      values.pop ();
	      A = values.top ();
	      values.pop ();
	      op = ops.top ();
	      ops.pop ();

	      values.push (applyOp (A, B, op));
	    }

	  while (i < str.length () && str[i] >= 'A' && str[i] == 'Z')
	    {
	      aux.push_back (str[i]);
	      i++;
	    }

	  ops.push ();
	  aux.clear ();
	}
    }

  while (ops.empty () == false)
    {
      B = values.top
      
    }
}

string
strOr (string s1, string s2)
{
  string res;

  for (int i = 0; i < s1.length (); i++)
    res.push_back ((s1[i] | s2[i]));

  return res;
}

string
strAnd (string s1, string s2)
{
  string res;

  for (int i = 0; i < s1.length (); i++)
    res.push_back ((s1[i] & s2[i]));

  return res;
}

string
strXor (string s1, string s2)
{
  string res;

  for (int i = 0; i < s1.length (); i++)
    res.push_back ((s1[i] ^ s2[i]) + '0');

  return res;
}
