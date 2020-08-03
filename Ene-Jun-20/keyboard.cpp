#include <bits/stdc++.h>
using namespace std;

bool similar (vector <char>, char, char);
int keyboard (string s1, string s2);
void getKeyboard (vector <char> &);

int
main (void)
{
  int n = 0;
  string s1;
  string s2;

  cin >> n;
  while (n--)
    {
      cin >> s1 >> s2;

      cout << keyboard (s1, s2) << "\n";
    }

  return 0;
}

int
keyboard (string s1, string s2)
{
  vector <char> keyboard;

  if (s1.length () != s2.length ())
    return 3;
  else if (s1 == s2)
    return 1;
  else
    {
      getKeyboard (keyboard);

      for (int i = 0; i < s1.length (); i++)
        {
	  if (similar (keyboard, s1[i], s2[i]) == false)
	    return 3;
	}

      return 2;
    }
}

void
getKeyboard (vector <char> &keyboard)
{
  for (int i = 0; i < 26; i++)
    keyboard.push_back (i + 'a');
}

bool
similar (vector <char> keyboard, char a, char b)
{
  int key = 0;

  if (a == b)
    return true;

  key = (a - 'a') - 10;
  if (key >= 0 && key <= 25)
    {
      if (keyboard[key] == b)
        return true;
    }

  key = (a - 'a') + 10;
  if (key >= 0 && key <= 25)
    {
      if (keyboard[key] == b)
        return true;
    }

  key = (a - 'a') - 9;
  if (key >= 0 && key <= 25)
    {
      if (keyboard[key] == b)
        return true;
    }

  key = (a - 'a') + 9;
  if (key >= 0 && key <= 25)
    {
      if (keyboard[key] == b)
        return true;
    }
  
  key = (a - 'a') - 8;
  if (key >= 0 && key <= 25)
    {
      if (keyboard[key] == b)
        return true;
    }

  key = (a - 'a') + 8;
  if (key >= 0 && key <= 25)
    {
      if (keyboard[key] == b)
        return true;
    }

  key = (a - 'a') - 1;
  if (key >= 0 && key <= 25)
    {
      if (keyboard[key] == b)
        return true;
    }

  key = (a - 'a') + 1;
  if (key >= 0 && key <= 25)
    {
      if (keyboard[key] == b)
        return true;
    }

  return false;
}
