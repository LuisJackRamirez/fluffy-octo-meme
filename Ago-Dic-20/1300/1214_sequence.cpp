#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int flag = 0;
  int mini = 0;
  int n = 0;
  string str;

  cin >> n;
  cin >> str;

  if (n % 2 == 1)
    {
      cout << "No\n";
      return 0;
    }

  for (int i = 0; i < n; i++)
    {
      if (str[i] == '(')
        flag++;
      else
        flag--;

      mini = min (flag, mini);
    }

  if (flag == 0 && mini >= -1)
    cout << "Yes\n";
  else
    cout << "No\n";

  return 0;
}
