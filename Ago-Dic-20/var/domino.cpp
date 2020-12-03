#include <bits/stdc++.h>
using namespace std;

int solve (vector <int> &, vector <int> &);

int
main (void)
{
  int n = 0;

  vector <int> A;
  vector <int> B;

  cin >> n;
  A.resize (n);
  B.resize (n);

  for (int i = 0; i < n; i++)
    cin >> A[i];
  
  for (int i = 0; i < n; i++)
    cin >> B[i];

  cout << solve (A, B) << "\n";

  return 0;
}

int
solve (vector <int> &A, vector <int> &B)
{
  int resA = 0;
  int resB = 0;
  int actual = 0;

  actual = A[0];
  for (int i = 1; i < A.size (); i++)
    {
      if (actual ^ A[i] == 0)
        actual = A[i];
      else if (actual ^ B[i] == 0)
        actual = B[i];
      else
        {
	  resA = -1;
	  break;
        }
    }

  actual = B[0];
  for (int i = 1; i < B.size (); i++)
    {
      if (actual ^ B[i] == 0)
        actual = B[i];
      else if (actual ^ A[i] == 0)
        actual = A[i];
      else
        {
	  resB = -1;
	  break;
        }
    }

  if (resA == -1 && resB == -1)
    return -1;
  else
    {
      if (resA == -1)
        return resB;
      else if (resB == -1)
        return resA;
      else
        return min (resA, resB);
    }
}
