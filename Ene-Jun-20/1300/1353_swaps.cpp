#include <bits/stdc++.h>
using namespace std;

int twoArrays (vector <int>, vector <int>, int);
int vectorSum (vector <int>);

int 
main (void)
{
  int t = 0;
  int n = 0;
  int k = 0;

  vector <int> A;
  vector <int> B;

  cin >> t;
  while (t--)
    {
      cin >> n >> k;
      A.resize (n);
      B.resize (n);

      for (int i = 0; i < n; i++)
        cin >> A[i];
      
      for (int i = 0; i < n; i++)
        cin >> B[i];

      cout << twoArrays (A, B, k) << "\n";
    }

  return 0;
}

int
twoArrays (vector <int> A, vector <int> B, int k)
{
  int i = 0;
  int j = 0;

  j = A.size () - 1;

  sort (A.begin (), A.end ());
  sort (B.begin (), B.end ());

  while (k > 0 && i < A.size () && j >= 0 && A[i] < B[j])
    {
      A[i] = B[j];
      k--;
      i++;
      j--;
    }

  return vectorSum (A);
}

int
vectorSum (vector <int> A)
{
  int res = 0;
  
  for (int i = 0; i < A.size (); i++)
    res = res + A[i];

  return res;
}
