#include <bits/stdc++.h>
using namespace std;

int makeInt (string &);

int
main (void)
{
  char x = '0';
  int a = 0;
  int b = 0;
  int c = 0;
  int n = 0;

  string str;
  stack < int >s;

  cin >> str;

  while (!str.empty ())
    {
      x = *str.begin ();
      str.erase (str.begin ());

      switch (x)		//Nivel 1
	{
	case 'S':
	  if (str.empty ())
	    break;

	  x = *str.begin ();
	  str.erase (str.begin ());

	  switch (x)		//Nivel 2
	    {
	    case 'S':
	      n = makeInt (str);
	      s.push (n);
	      break;

	    case 'N':
	      if (str.empty ())
	        break;

	      x = *str.begin ();
	      str.erase (str.begin ());

	      switch (x)	//Nivel 3
		{
		case 'S':
		  if (s.empty ())
		    cout << "Invalid copy operation\n";
		  else
		    s.push (s.top ());
		  break;

		case 'T':
		  if (s.size () < 2)
		    cout << "Invalid swap operation\n";
		  else
		    {
		      a = s.top ();
		      s.pop ();
		      b = s.top ();
		      s.pop ();
		      s.push (a);
		      s.push (b);
		    }
		  break;

		case 'N':
		  if (s.empty ())
		    cout << "Invalid remove operation\n";
		  else
		    s.pop ();
		  break;
		}
	      break;
	    }
	  break;

	case 'T':
 	  if (str.empty ())
	    break;

	  x = *str.begin ();
	  str.erase (str.begin ());

	  switch (x)		//Nivel 2
	    {
	    case 'S':
 	      if (str.empty ())
	        break;

	      x = *str.begin ();
	      str.erase (str.begin ());

	      switch (x)	//Nivel 3
		{
		case 'S':
		  if (str.empty ())
	            break;

		  x = *str.begin ();
		  str.erase (str.begin ());
 	          
		  switch (x)	//Nivel 4
		    {
		    case 'S':
		      if (s.size () < 2)
			cout << "Invalid addition operation\n";
		      else
			{
			  a = s.top ();
			  s.pop ();
			  c = a;
			  b = s.top ();
			  s.pop ();
			  c = c + b;
			  s.push (c);
			}
		      break;

		    case 'T':
		      if (s.size () < 2)
			cout << "Invalid addition operation\n";
		      else
			{
			  a = s.top ();
			  s.pop ();
			  c = 0 - a;
			  b = s.top ();
			  s.pop ();
			  c = c + b;
			  s.push (c);
			}
		      break;

		    case 'N':
		      if (s.size () < 2)
			cout << "Invalid multiplication operation\n";
		      else
			{
			  a = s.top ();
			  s.pop ();
			  c = a;
			  b = s.top ();
			  s.pop ();
			  c = c * b;
			  s.push (c);
			}
		      break;
		    }
		  break;

		case 'T':
		  if (str.empty ())
	            break;

		  x = *str.begin ();
		  str.erase (str.begin ());

		  if (s.size () < 2)
		    cout << "Invalid division operation\n";
		  else if (s.top () == 0)
		    cout << "Division by zero\n";
		  else
		    {
		      a = s.top ();
		      s.pop ();
		      b = s.top ();
		      s.pop ();
		      c = a / b;
		      s.push (c);
		    }

		  break;
		}
	      break;

	    case 'N':
	      if (str.size () < 2)
	        break;

	      str.erase (str.begin ());
	      str.erase (str.begin ());

	      if (s.empty ())
		cout << "Invalid print operation\n";
	      else
		{
		  cout << s.top () << "\n";
		  s.pop ();
		}
	      break;
	    }
	  break;
	}
    }

  return 0;
}

int
makeInt (string & str)
{
  bool isNegative = false;
  char x = '0';
  int num = 0;
 
  if (str.empty ())
    return 0;

  x = *str.begin ();
  str.erase (str.begin ());

  if (x == 'T')
    isNegative = true;

  while (*str.begin () != 'N')
    {
      if (str.empty ())
        break;

      num = num << 1;

      if (*str.begin () == 'T')
	num = num | 1;

      str.erase (str.begin ());
    }

  if (!str.empty ())
    str.erase (str.begin ());

  if (isNegative)
    return -num;
  else
    return num;
}
