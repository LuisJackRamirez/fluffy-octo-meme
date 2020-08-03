#include <bits/stdc++.h>
using namespace std;

void kuroniGifts (vector <int>, vector <int>);

int
main (void)
{
  int t = 0;
  int n = 0;
  vector <int> a;
  vector <int> b;

  cin >> t;
  while (t--)
    {
      cin >> n;
      a.resize (n);
      b.resize (n);

      for (int i = 0; i < n; i++)
        cin >> a[i];
      
      for (int i = 0; i < n; i++)
        cin >> b[i];

      kuroniGifts (a, b);
    }

  return 0;
}

void
kuroniGifts (vector <int> a, vector <int> b)
{
  int n = 0;

  n = a.size ();
  sort (a.begin (), a.end ());
  sort (b.begin (), b.end ());

  for (int i = 0; i < n; i++)
    cout << a[i] << " ";

  cout << "\n";
      
  for (int i = 0; i < n; i++)
    cout << b[i] << " ";
  
  cout << "\n";
}
