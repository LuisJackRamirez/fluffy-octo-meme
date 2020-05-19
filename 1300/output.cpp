#include <iostream>
using namespace std;

int
main (void)
{
  for (int i = 0; i < 200000; i++)
    cout << 1000000000 << " ";

  cout << "\n";

  return 0;  
}
