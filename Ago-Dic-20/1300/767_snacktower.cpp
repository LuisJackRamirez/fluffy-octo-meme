#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int input = 0;
  int num = 0;

  set <int> a;

  cin >> n;
  num = n;

  for (int i = 0; i < n; i++)
    {
      cin >> input;

      if (input == num)
        {
	  cout << input << " ";
	  num--;

	  while (a.find (num) != a.end ())
	    {
	      cout << num << " ";
	      num--;
	    }
	}
      else
	a.insert (input);

      cout << "\n";
    }

  return 0;
}
