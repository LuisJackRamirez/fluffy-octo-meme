#include <iostream>
using namespace std;

int
main (void)
{
  int a = 0;
  int b = 0;
  int n = 0;

  cin >> n >> a >> b;

  if ((b - a - 1) & 1)
    cout << "Alice";
  else
    cout << "Borys";

  return 0;
}
