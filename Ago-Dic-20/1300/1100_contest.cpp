#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int num = 0;
  int m = 0;

  vector <int> freq;
  set <int> problems;
  string res;

  cin >> n >> m;
  res.resize (m);
  freq.resize (n + 1);

  for (int i = 0; i < m; i++)
    {
      cin >> num;

      freq[num]++;
      problems.insert (num);
      if (problems.size () == n)
        {
	  res[i] = '1';

	  for (int i = n; i > 0; i--)
	    {
	      freq[i]--;

	      if (freq[i] == 0)
	        problems.erase (i);
	    }
	}
      else
        res[i] = '0';
    }

  cout << res << "\n";

  return 0;
}
