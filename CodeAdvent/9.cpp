#include <bits/stdc++.h>
#define lli long long int
#define preSize 25
using namespace std;

int
main (void)
{
  bool found = false;
  lli num = 0;
  lli begin = 0;
  vector <lli> data;
  set <lli> window;

  for (int i = 0; i < preSize; i++)
    {
      cin >> num;
      data.push_back (num);
      window.insert (num);
    }

  while (cin >> num)
    {
      found = false;

      for (int i = 0 + begin; i < begin + preSize; i++)
        {
	  if (num - data[i] != num / 2)
	    {
	      if (window.find (num - data[i]) != window.end ())
	        found = true;
	    }

	  if (found == true)
	    break;
	}

      if (found == false)
        {
	  cout << num << "\n";
	  break;
	}

      window.erase (data[begin]);
      data.push_back (num);
      window.insert (num);
      begin++;
    }

  return 0;
}
