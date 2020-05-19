#include <iostream>
#include <vector>
using namespace std;

int
main (void)
{
  int g = 0;
  int n = 0;
  int nimSum = 0;

  vector <int> stones;

  cin >> g;

  while (g--)
    {
      cin >> n;
      stones.resize (n);

      for (int i = 0; i < n; i++)
        {
          cin >> stones[i];

	  nimSum = nimSum ^ stones[i];
	}

      if (nimSum != 0)
        cout << "First\n";
      else
        cout << "Second\n";

      stones.clear ();
      nimSum = 0;
    }

  return 0;
}
