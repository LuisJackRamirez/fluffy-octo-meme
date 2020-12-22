#include <bits/stdc++.h>
#define lli long long int
#define preSize 25
using namespace std;

lli findNonValidNumber (vector <lli> &);

int
main (void)
{
  int begin = 0;
  int end = 0;
  lli nonValidNumber = 0;
  lli sum = 0;

  set <lli> window;
  vector <lli> data;

  nonValidNumber = findNonValidNumber (data);

  while (end != data.size ())
    {
      while (sum < nonValidNumber && end != data.size ())
        {
	  sum = sum + data[end];
	  window.insert (data[end]);
	  end++;
	}
      
      if (sum == nonValidNumber)
        {
	  vector <int> a (data.begin () + begin, data.begin () + end);

	  sort (a.begin (), a.end ());
	  cout << a[0] + a[a.size () - 1] << "\n";
	  break;
	}
      else
        {
	  while (sum > nonValidNumber && begin < end)
	    {
	      sum = sum - data[begin];
	      window.erase (data[begin]);
	      begin++;
	    }
	}
    }

  return 0;
}

lli
findNonValidNumber (vector <lli> &data)
{
  bool found = false;
  lli num = 0;
  lli begin = 0;
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
	break;

      window.erase (data[begin]);
      data.push_back (num);
      window.insert (num);
      begin++;
    }

  return num;
}
