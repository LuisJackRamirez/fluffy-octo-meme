#include <bits/stdc++.h>
using namespace std;

int teamsForm (vector <int>);

int
main (void)
{
  int n = 0;
  vector <int> students;

  cin >> n;
  students.resize (n);
  
  for (int i = 0; i < n; i++)
    cin >> students[i];

  cout << teamsForm (students) << "\n";

  return 0;
}

int
teamsForm (vector <int> students)
{
  int res = 0;

  sort (students.begin (), students.end ());

  for (int i = 1; i < students.size (); i = i + 2)
    res = res + students[i] - students[i - 1];

  return res;
}
