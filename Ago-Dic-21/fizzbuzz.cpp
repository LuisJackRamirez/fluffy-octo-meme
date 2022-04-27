#include <bits/stdc++.h>
using namespace std;

void
fizzbuzz (int n)
{
  for (int i = 1; i <= n; i++)
    {
      if (i % 3 == 0)
        cout << "Fizz";
     
      if (i % 5 == 0)
        cout << "Buzz";

      if (i % 3 != 0 && i % 5 != 0)
        cout << i;

      cout << "\n";
    }

  return;
}

int
main (int argc, char **argv)
{
  int n = 0;

  if (argc != 2)
    return 0;

  n = atoi (argv[1]);
  fizzbuzz (n);

  return 0;
}
