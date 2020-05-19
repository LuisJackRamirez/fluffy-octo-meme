#include <bits/stdc++.h>
#define lli long long int
using namespace std;

lli timeToComplete (int, vector <int> &);

int
main (void)
{
  int m = 0;
  int n = 0;
  lli res = 0;

  vector <int> tasks;

  cin >> n >> m;
  tasks.resize (m);

  for (int i = 0; i < m; i++)
    cin >> tasks[i];

  res = timeToComplete (n, tasks);

  cout << res << "\n";

  return 0;
}

lli
timeToComplete (int n, vector <int> &tasks)
{
  int house = 0;
  lli res = 0;

  house = 1;

  for (int i = 0; i < tasks.size (); i++)
    {
      if (tasks[i] > house)
	res = res + tasks[i] - house;
      else if (tasks[i] < house)
	res = res + n - (house - tasks[i]);
      
      house = tasks[i];
    }

  return res;
}
