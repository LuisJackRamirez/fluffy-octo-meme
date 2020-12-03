#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int left = 0;
  int number = 0;
  int right = 0;
  vector<int> a;

  while (cin >> number)
    a.push_back (number);

  //Sort so the two pointers search works correctly
  sort (a.begin (), a.end ());

  for (int i = 0; i < a.size (); i++)
    {
      left = i + 1;
      right = a.size () - 1;

      while (left < right)
        {
	  int sum = a[i] + a[left] + a[right];
	  if (sum == 2020)
	    {
	      cout << a[i] * a[left] * a[right] << "\n";
	      return 0;
	    }
	  else if (sum < 2020)
	    left++;
	  else
	    right--;
	}
    }

  return 0;
}
