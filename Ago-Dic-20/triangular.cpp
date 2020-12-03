#include <bits/stdc++.h>
#define f first
#define s second
#define lli long long int
using namespace std;

int finde (vector <lli> &, int);
void spiral (vector <lli> &);
pair <int, int> simulate (int, int);

vector <lli> lowerB;

int
main (void)
{
  lli n = 0;
  int points = 0;
  int t = 0;
  int range = 0;

  pair <int, int> res;

  spiral (lowerB);

  cin >> t;
  while (t--)
    {
      cin >> n;

      range = finde (lowerB, n);
      points = n - lowerB[range];

      res = simulate (points, range);
      cout << res.f << " " << res.s << "\n";
    }

  return 0;
}

void
spiral (vector <lli> &lowerB)
{
  lli i = 0;
  lowerB.push_back (1);
  i++;

  while (lowerB[i - 1] < 1e12)
    {
      lowerB.push_back (lowerB[i - 1] + (2 * ((4 * (i - 1)) + 3)));
      i++;
    }
}

int
finde (vector <lli> &lowerB, int n)
{
  int l = 0;
  int r = lowerB.size () - 1;
  int m = 0;

  while (l < r)
    {
      m = l + (r - l) / 2;
      
      if (lowerB[m] <= n)
        {
	  if (lowerB[m + 1] > n)
	    return m;
	  else if (lowerB[m + 1] <= n)
	    l = m;
	}
      else if (lowerB[m] > n)
        r = m;
    }
}

pair <int, int>
simulate (int numPuntos, int nivel)
{
  int i = 0;
  int n = 0;
  pair <int, int> inicial (0, -nivel);

  n = (2 * nivel) + 1;
  
  while (i = 0 < n && numPuntos > 0)
    {
      inicial.f--;
      numPuntos--;
    }
  
  while (i = 0 < n && numPuntos > 0)
    {
      inicial.f++;
      inicial.s++;
      numPuntos--;
    }

  n++;
  while (i = 0 < n && numPuntos > 0)
    {
      inicial.f++;
      inicial.s--;
      numPuntos--;
    }

  while (i = 0 < n && numPuntos > 0)
    {
      inicial.f--;
      numPuntos--;
    }

  return inicial;
}
