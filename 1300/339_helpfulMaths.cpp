#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  char a = '0';
  int i = 0;
  int plus = 0;
  vector <char> summands;
  string s;

  cin >> s;

  for (int i = 0; i < s.length (); i++)
    {
      if (s[i] == '+')
        plus++;
      else if (s[i] >= '0' && s[i] <= '9')
        summands.push_back (s[i]);
    }

  sort (summands.begin (), summands.end ());

  while (plus > 0)
    {
      cout << summands[i] << "+";
      plus--;
      i++;
    }

  cout << *(summands.end () - 1) << "\n";

  return 0;  
}
