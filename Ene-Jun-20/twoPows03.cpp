#include <bits/stdc++.h>
using namespace std;


int
main (void)
{
  int a = 0;
  int n = 0;
  int num = 0;
  int powsTwo[31];
  long long int res = 0;
  int var1 = 0;

  map < int, int >nums;
  vector < int >v;

  for (int i = 0; i < 31; i++)
    powsTwo[i] = pow (2, i);

  cin >> n;

  for (int i = 0; i < n; i++)
    {
      cin >> num;
      v.push_back (num);

      if (nums.find (num) == nums.end ())
	nums.insert (make_pair (num, 1));
      else
	nums.find (num)->second++;
    }

  for (int i = 0; i < n; i++)
    {
      a = v[i];

      for (int j = 0; j < 31; j++)
	{
	  var1 = powsTwo[j] - a;

	  if (nums.find (var1) != nums.end ())
	    {	    
	      res = res + nums.find (var1)->second;

	      if ((var1) == a)
	        res--;
	    }
	}
    }

  res = res / 2;

  cout << res << "\n";

  return 0;
}
