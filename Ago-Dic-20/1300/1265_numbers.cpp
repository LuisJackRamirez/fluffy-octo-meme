#include <bits/stdc++.h>
using namespace std;

string beautifulNumbers (vector <int> &nums, vector <int> &pos);

int
main (void)
{
  int t = 0;
  int n = 0;

  string res;
  vector <int> pos;
  vector <int> num;

  cin >> t;

  while (t--)
    {
      cin >> n;
      num.resize (n);
      pos.resize (n + 1);

      for (int i = 0; i < n; i++)
        {
	  cin >> num[i];
	  pos[num[i]] = i;
	}

      res = beautifulNumbers (num, pos);
      cout << res << "\n";
    }

  return 0;
}

string
beautifulNumbers (vector <int> &nums, vector <int> &pos)
{
  int l = 0;
  int m = 0;
  int r = 0;

  set <int> s;
  string res;

  m = 1;
  l = pos[m];
  r = pos[m];
  s.insert (m);

  while (m <= nums.size ())
  //while (l != 0 || r != nums.size () - 1)
    {
      if (pos[m] > r)
        {
	  r++;
	  while (r < pos[m])
	    {
	      s.insert (nums[r]);
	      r++;
	    }

	  s.insert (nums[r]);
	}
      else if (pos[m] < l)
        {
	  l--;
	  while (l > pos[m])
	    {
	      s.insert (nums[l]);
	      l--;
	    }

	  s.insert (nums[l]);
	}

      if (s.size () == m && r - l == m - 1)
        res.push_back ('1');
      else
        res.push_back ('0');

      m++;
    }

  return res;
}
