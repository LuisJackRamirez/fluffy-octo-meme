#include <iostream>
#include <vector>
using namespace std;

int
main (void)
{
  int n = 0;
  int nimSum = 0;
  int res = 0;

  vector <int> stones;

  while (true)
    {	    
      cin >> n;
      if (n == 0)
        return 0;

      stones.resize (n);

      for (int i = 0; i < n; i++)
        {
          cin >> stones[i];
	  nimSum = nimSum ^ stones[i];
	}

      for (int i = 0; i < n; i++)
        {
	  if ((nimSum ^ stones[i]) < stones[i])
	    res++;
	}

      cout << res << "\n";

      stones.clear ();
      nimSum = 0;
      res = 0;
    }

  return 0;
}
