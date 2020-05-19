#include <bits/stdc++.h>
using namespace std;

vector <int> getArray (int);
void printArray (vector <int> &);

int
main (void)
{
  int n = 0;
  int t = 0;

  cin >> t;

  while (t--)
    {
      cin >> n;

      if ((n / 2) % 2 == 0)
        {
	  cout << "YES\n";

	  vector <int> balance;
	  balance = getArray (n);
	  printArray (balance);

	  cout << "\n";
	}
      else
        cout << "NO\n";
    }

  return 0;
}

vector <int>
getArray (int n)
{
  int evenSum = 0;
  int oddSum = 0;

  vector <int> balance (n);

  for (int i = 0; i < n / 2; i++)
    {
      balance[i] = (i + 1) * 2;
      evenSum = evenSum + balance[i];
    }

  for (int i = 0; i < n / 2; i++)
    {
      balance[n / 2 + i] = (2 * i) + 1;
      oddSum = oddSum + balance[n / 2 + i];
    }

  balance[n - 1] = balance[n - 1] + (evenSum - oddSum);

  return balance;
}

void
printArray (vector <int> &balance)
{
  for (int i = 0; i < balance.size (); i++)
    cout << balance[i] << " ";
}
