#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int, int>
using namespace std;

void
karenCoffee (vector <pii> &recipes, int n, vector <pii> &queries, int q, int k)
{
  vector <int> temps (200001);

  for (int i = 0; i < n; i++)
    {
      temps[recipes[i].f]++;
      temps[recipes[i].s + 1]--;
    }

  for (int i = 1; i < temps.size (); i++)
    temps[i] = temps[i] + temps[i - 1];
  
  for (int i = 1; i < temps.size (); i++)
    {
      if (temps[i] >= k)
        temps[i] = temps[i - 1] + 1;
      else
        temps[i] = temps[i - 1];
    }

  for (int i = 0; i < q; i++)
    cout << temps[queries[i].s] - temps[queries[i].f - 1] << "\n";

  return;
}

int
main (void)
{
  int n = 0;
  int k = 0;
  int q = 0;

  cin >> n >> k >> q;
  vector <pii> recipes (n);
  vector <pii> questions (q);

  for (int i = 0; i < n; i++)
    cin >> recipes[i].f >> recipes[i].s;

  for (int i = 0; i < q; i++)
    cin >> questions[i].f >> questions[i].s;

  karenCoffee (recipes, n, questions, q, k);

  return 0;
}
