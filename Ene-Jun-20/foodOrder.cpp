#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

int
main (void)
{
  int n = 0;
  int m = 0;
  int foodType = 0;
  int dishNums = 0;

  vector < int >quantities;
  vector < int >costs;
  vector < int >expenses;
  set < pair < int, int >>s;	//costs, index

  cin >> n >> m;
  quantities.resize (n + 1);
  costs.resize (n + 1);
  expenses.resize (m + 1);

  for (int i = 1; i <= n; i++)
    cin >> quantities[i];

  for (int i = 1; i <= n; i++)
    {
      cin >> costs[i];
      s.insert (make_pair (costs[i], i));
    }

  for (int i = 1; i <= m; i++)
    {
      if (s.empty ())
	expenses[i] = 0;
      else
	{

	  cin >> foodType >> dishNums;
	  //foodType--;

	  if (dishNums <= quantities[foodType])
	    {
	      expenses[i] = dishNums * costs[foodType];
	      quantities[foodType] = quantities[foodType] - dishNums;

	      if (quantities[foodType] == 0)
		s.erase (make_pair (costs[foodType], foodType));
	    }
	  else
	    {
	      while (dishNums != 0 && !s.empty ())
		{
		  expenses[i] =
		    expenses[i] + (quantities[foodType] * costs[foodType]);
		  dishNums = dishNums - quantities[foodType];
		  quantities[foodType] = 0;
		  s.erase (make_pair (costs[foodType], foodType));

		  foodType = (*s.begin ()).second;

		  if (dishNums <= quantities[foodType])
		    {
		      expenses[i] =
			expenses[i] + (dishNums * costs[foodType]);
		      quantities[foodType] = quantities[foodType] - dishNums;
		      dishNums = 0;

		      if (quantities[foodType] == 0)
			s.erase (make_pair (costs[foodType], foodType));

		      break;
		    }
		}

	      if (s.empty () && dishNums != 0)
		expenses[i] = 0;
	    }
	}
    }

  for (int i = 1; i <= m; i++)
    cout << expenses[i] << "\n";

  return 0;
}
