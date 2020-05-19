#include <bits/stdc++.h>
using namespace std;


int
main (void)
{
  int a = 0;
  int n = 0;
  int num = 0;
  int powsTwo[31];
  int res = 0;

  map <int, int> nums;
  vector <int> v;

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

  sort (v.begin (), v.end ());

  for (int i = 0; i < v.size (); i++)
    {
      a = v[i];
      a = a;

      for (int j = 0; j < 31; j++)
        {
	if (powsTwo[j] - a >= 0)
	  if (powsTwo[j] - a == a)
	    {
	      res = res + (nums.find (a)->second * (nums.find (a)->second - 1));
//	      break;
	    }
	  else
	    res = res + (nums[powsTwo[j] - a] * nums.find (a)->second);
	}
    }

  res = res / 2;

  cout << res << "\n";

  return 0;
}
