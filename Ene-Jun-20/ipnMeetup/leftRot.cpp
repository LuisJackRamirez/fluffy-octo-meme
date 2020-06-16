#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int d = 0;

  vector <int> array;

  cin >> n >> d;
  array.resize (n);

  for (int i = 0; i < array.size (); i++)
    cin >> array[i];

  for (int i = d % n; i < array.size (); i++)
    cout << array[i] << " ";
  
  for (int i = 0; i < d % n; i++)
    cout << array[i] << " ";

  cout << "\n";

  return 0;
}
