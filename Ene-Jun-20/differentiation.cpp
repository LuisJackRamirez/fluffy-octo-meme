#include <bits/stdc++.h>
#include <cstring>
using namespace std;

void differentiate (string, bool);
int getCoef (string);
int getGrade (string);

int
main (void)
{
  bool firstNeg = false;
  string polynome;

  cin >> polynome;

  if (polynome[0] == '-')
    firstNeg = true;

  differentiate (polynome, firstNeg);
  cout << "\n";

  return 0;
}

void
differentiate (string polynome, bool firstNeg)
{
  bool neg = false;
  int a = 0;
  int j = 0;
  int grade = 0;
  int power = 0;

  vector <string> terms;

  for (int i = 0; i < polynome.length (); i++)
    {
      if (polynome[i] == '+' || (polynome[i] == '-' && i != 0))
        {
	  terms.push_back (polynome.substr (j, i - j));
	  
	  j = i;
	  if (polynome[j] == '+')
	    j++;
	}
    }
  terms.push_back (polynome.substr (j));

  grade = getGrade (terms[0]);
  if (grade == 0)
    {
      cout << "0";
      return;
    }
  int coef[grade];
  memset (coef, 0, sizeof (coef));

  coef[0] = getCoef (terms[0]) * grade;
  for (int i = 1; i < terms.size (); i++)
    {
      power = getGrade (terms[i]);
      a = getCoef (terms[i]);

      if (power != 0)
        coef[grade - power] = a * power;
    }

  j = 0;
  while (true)
    {
      if (coef[j] != 0)
        break;
      else if (j == grade - 1)        
        {
	  cout << "0\n";
	  return;
	}
    }

  for (int i = 0; i < grade; i++)
    {
      if (coef[i] > 0 && i != 0)
        cout << "+";

      if (coef[i] != 0)
        {
          cout << coef[i];
          if (grade - i - 1 >= 1)
            cout << "x";
          if (grade - i - 1 > 1)
            cout << grade - i - 1;
	}
    }

  return;
}

int
getGrade (string str)
{
  for (int i = 0; i < str.length (); i++)
    {
      if (str[i] == 'x')
        {
	  if (str[i + 1] != '\0')
            return stoi (str.substr (i + 1));
	  else 
	    return 1;
	}
    }

  return 0;
}

int
getCoef (string str)
{
  int coef = 0;
  int i = 0;

  if (str[0] == 'x')
    coef = 1;
  else if (str[0] == '-' && str[1] == 'x')
    coef = -1;
  else
    {
      while (str[i] != 'x' && str[i] != '\0' && str[i] != '\n')
        i++;

      coef = stoi (str.substr(0, i));
    }

  return coef;
}
