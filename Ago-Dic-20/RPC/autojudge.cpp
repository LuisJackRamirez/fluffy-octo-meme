#include <bits/stdc++.h>
using namespace std;

int check (string, string, int, int, int, vector <string> &, vector <string> &);

int
main (void)
{
  string filename;
  string submitted;
  string str;
  int r = 0;
  int d = 0;
  int e = 0;
  int c = 0;
  int t = 0;
  int res = 0;
  vector <string> correctOuts;
  vector <string> submittedOuts;

  cin >> filename;
  cin >> submitted;
  cin >> r >> d >> e;
  
  cin >> c;
  cin.ignore ();
  for (int i = 0; i < c; i++)
    {
      getline (cin, str);
      correctOuts.push_back (str);
    }

  cin >> t;
  cin.ignore ();
  for (int i = 0; i < t; i++)
    {
      getline (cin, str);
      submittedOuts.push_back (str);
    }

  res = check (filename, submitted, r, d, e, correctOuts, submittedOuts);

  switch (res)
    {
      case 0: 
        cout << "Correct";
	break;

      case 1:
	cout << "Compile Error";
	break;

      case 2:
	cout << "Run-Time Error";
	break;

      case 3:
	cout << "Time Limit Exceeded";
	break;

      case 4:
	cout << "Wrong Answer";
	break;
    }

  cout << "\n";

  return 0;
}

int
check (string filename, string submitted, int r, int d, int e, 
		vector <string> &correctOuts, vector <string> &submittedOuts)
{
  bool extension = false;
  int i = 0;
  int j = 0;

  set <string> fileTypes;

  fileTypes.insert ("c");
  fileTypes.insert ("cpp");
  fileTypes.insert ("java");
  fileTypes.insert ("py");

  for (i = submitted.length () - 1; i >= 0; i--)
    {
      if (submitted[i] == '.')
        {
	  if (fileTypes.find (submitted.substr (i + 1)) == fileTypes.end ())
	    return 1;

	  extension = true;
	  break;
	}
    }

  if (extension == false)
    return 1;

  for (j = i - 1; j >= 0; j--)
    {
      if (islower (submitted[j]) == 0)
	break;
    }
  
  if (submitted.substr (j + 1, i - j - 1) != filename)
    return 1;

  if (r != 0)
    return 2;

  if (e > d)
    return 3;

  if (correctOuts.size () != submittedOuts.size ())	  
    return 4;

  for (int k = 0; k < correctOuts.size (); k++)
    {
      if (correctOuts[k] != submittedOuts[k])
        return 4;
    }

  return 0;
}
