#include <bits/stdc++.h>
using namespace std;

void initializeVector (vector <string> &, int);

int
main (void)
{
  bool foundSol = false;

  char answer;
  char result;

  int q = 0;
  int m = 0;
  int t = 0;
  int zeroes = 0;

  vector <string> questions;
  vector <bool> indetermined;

  cin >> t;

  while (t--)
    {
      cin >> q >> m;
      initializeVector (questions, q);
      indetermined.resize (q);

      for (int i = 0; i < m; i++)
        {
	  for (int j = 0; j < q; j++)
	    {
	      cin >> answer >> result;
	  
 	      if (result == 'F')
	        {
		  if (questions[j][answer - 'A'] == '1')
		    indetermined[j] = true;
		  else
	            questions[j][answer - 'A'] = '0';
		}
	      else if (result == 'T')
	        {
		  for (int k = 0; k < 4; k++)
		    {
		      if (questions[j][k] == '1' && k != answer - 'A')
		        indetermined[j] = true;
		    }	    

		  if (indetermined[j] != true)
		    {
		      for (int k = 0; k < 4; k++)
		        questions[j][k] = '0';

		      questions[j][answer - 'A'] = '1';
		    }
		}
	    }
	}

      for (int i = 0; i < q; i++)
        {
	  foundSol = false;
	  zeroes = 0;

	  if (indetermined[i] == true)
	    cout << "?";
	  else
	    {
	      for (int k = 0; k < 4; k++)
	        {
		  if (questions[i][k] == '1')
		    {
		      foundSol = true;

		      cout << (char) (k + 'A');
		      break;
		    }
		  else if (questions[i][k] == '0')
		    zeroes++;
		}

	      if (zeroes == 3)
	        {
	          for (int k = 0; k < 4; k++)
	            {
	   	      if (questions[i][k] == '3')
		        {
  	  	          cout << (char) (k + 'A');
		          break;
			}
		    }
		}
	      else if (foundSol == false)
	        cout << "?";
	    }
	  
	  if (i < q - 1)
	    cout << " ";
	}

      cout << "\n";
      foundSol = false;
      indetermined.clear ();
      questions.clear ();
    }

  return 0;
}

void
initializeVector (vector <string> &questions, int q)
{
  for (int i = 0; i < q; i++)
    questions.push_back ("3333");
}
