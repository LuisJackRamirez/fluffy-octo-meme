#include <bits/stdc++.h>
using namespace std;

void solve (int, int, vector <int> &);

int
main (void)
{
  int aux = 0;	
  int pos = 0;
  int n = 0;	
  int num = 0;
  int perms = 0;
  float res = 0;
  int t = 0;

  vector <int> nums;

  string ogStr;
  string str;

  cin >> t;

  cin >> num;
  str = to_string (num);

  sort (str.begin (), str.end ());

  nums.push_back (stoi (str));
  perms++;

  while (next_permutation (str.begin (), str.end ()))
    {
      nums.push_back (stoi (str));
      perms++;
    }

  solve (num, perms, nums);

  for (int i = 1; i < t; i++)
    {
      cin >> num;

      solve (num, perms, nums);
    }

  str.clear ();
  nums.clear ();

  return 0;	
}

void
solve (int num, int perms, vector <int> &nums)
{
  int pos = 0;
  float res = 0;

      for (int i = nums.size () - 1; i >= 0; i--)
        {
	  if (nums[i] > num)
	    pos++;
	  else if (nums[i] <= num)
	    break;
	}	

      if (pos == 0)
        res = 0;
      else
        res = pow ((perms + 1), pos - 1) / pow (perms, pos);

      printf ("%.8f\n", res);
      //cout << setprecision (7) << res << "\n";
}
