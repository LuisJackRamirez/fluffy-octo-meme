#include <bits/stdc++.h>
using namespace std;

const int Fibonacci[45] = {
    0, 1, 1, 2, 3, 5, 
    8, 13, 21, 34, 55, 89,
    144, 233, 377, 610,
    987, 1597, 2584, 4181,
    6765, 10946, 17711, 28657,
    46368, 75025, 121393, 196418,
    317811, 514229, 832040,
    1346269, 2178309, 3524578,
    5702887, 9227465, 14930352,
    24157817, 39088169, 63245986,
    102334155, 165580141, 267914296,
    433494437, 701408733
};

char getChar (int, int);

int
main (void)
{
  int t = 0;
  int n = 0;
  int k = 0;

  cin >> t;

  while (t--)
    {
      cin >> n >> k;
      cout << getChar (n + 1, k) << "\n";
    }

  return 0;
}

char
getChar (int row, int index)
{
  if (row == 1)
    return 'a';
  if (row == 2 && index == 1)
    return 'b';
  if (row == 2 && index == 2)
    return 'c';

  if (index < Fibonacci [row - 1])
    return getChar (row - 2, index);

  return getChar (row - 1, index - Fibonacci [row - 1]);
}
