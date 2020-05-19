#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

int
main (void)
{
  long long int n = 0;
  long long int m = 0;
  long long int foodType = 0;
  long long int expenses = 0;
  long long int dishNums = 0;

  vector < long long int >quantities;
  vector < long long int >costs;
  set < pair < long long int, long long int >>s;	//costs, index

  cin >> n >> m;
  quantities.resize (n + 1);
  costs.resize (n + 1);

  for (int i = 1; i <= n; i++)
    cin >> quantities[i];

  for (int i = 1; i <= n; i++)
    {
      cin >> costs[i];
      s.insert (make_pair (costs[i], i));
    }

  for (int i = 1; i <= m; i++)
    {
      cin >> foodType >> dishNums;

      if (dishNums <= quantities[foodType])
	{
	  quantities[foodType] = quantities[foodType] - dishNums;
	  cout << dishNums * costs[foodType] << "\n";
	}
      else
	{
	  expenses = quantities[foodType] * costs[foodType];
	  dishNums = dishNums - quantities[foodType];
	  quantities[foodType] = 0;

	  while (s.empty () == false)
	    {
	      while (s.empty () == false
		     && quantities[(*s.begin ()).second] == 0)
		s.erase (s.begin ());

	      if (s.empty ())
	        break;

	      foodType = (*s.begin ()).second;

	      if (dishNums <= quantities[foodType])
		{
		  quantities[foodType] = quantities[foodType] - dishNums;
		  expenses = expenses + (dishNums * costs[foodType]);

		  cout << expenses << "\n";

		  break;
		}
	      else
	        {
		  expenses = expenses + (quantities[foodType] * costs[foodType]);
		  dishNums = dishNums - quantities[foodType];
		  quantities[foodType] = 0;
		  s.erase (s.begin ());
		}
	    }

	  if (s.empty () && dishNums != 0)
	    cout << "0\n";
	}
    }

  return 0;
}
