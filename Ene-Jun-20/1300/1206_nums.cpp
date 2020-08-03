#include <bits/stdc++.h>
using namespace std;

vector<int> twoNums (vector <int>, vector <int>);

int
main (void)
{
  int n = 0;
  int m = 0;
  vector <int> res(2);

  vector <int> A;
  vector <int> B;

  cin >> n;
  A.resize (n);
  for (int i = 0; i < n; i++)
    cin >> A[i];
  
  cin >> m;
  B.resize (m);
  for (int i = 0; i < m; i++)
    cin >> B[i];

  res = twoNums (A, B);

  cout << res[0] << " " << res[1] << "\n";

  return 0;
}

vector<int>
twoNums (vector <int> A, vector <int> B)
{
  vector<int> res (2);

  sort (A.begin (), A.end ());
  sort (B.begin (), B.end ());

  res[0] = A[A.size () - 1];
  res[1] = B[B.size () - 1];

  return res;
}
