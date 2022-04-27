#include <bits/stdc++.h>
using namespace std;

bool
canBobCommute (int n, int s, int i, vector < vector < int >>&metro,
	       vector < bool > &visited)
{
  if (i == s)
    return true;

  if (visited[i] == true)
    return false;

  visited[i] = true;

for (int x:metro[i])
    {
      if (canBobCommute (n, s, x, metro, visited))
	return true;
    }

  return false;
}

vector <vector<int>>
constructGraph (vector <int> &firstLine, vector <int> &secondLine)
{
  int i = 0;
  int n = firstLine.size ();

  vector <vector <int>> metro (n);
  
  while (i < n)
    {
      if (firstLine[i] != 0)
        {
	  bool found = false;

	  for (int j = i + 1; j < n; j++)
	    {
	      if (firstLine[j] == 1)
	        {
		  metro[i].push_back (j);
		  found = true;
		  i = j;
		  break;
		}
	    }

	  if (found == false)
	    break;
        }
      else
        i++;
    }

  i = n - 1;
  while (i > 0)
    {
      if (secondLine[i] != 0)
        {
	  bool found = false;

	  for (int j = i - 1; j >= 0; j--)
	    {
	      if (secondLine[j] == 1)
	        {
		  metro[i].push_back (j);
		  found = true;
		  i = j;
		  break;
		}
	    }

	  if (found == false)
	    break;
        }
      else
        i--;
    }

  return metro;
}

int
main (void)
{
  int n = 0;
  int s = 0;
  vector < int >firstLine;
  vector < int >secondLine;
  vector < vector < int >>metro;
  vector < bool > visited;

  cin >> n >> s;
  firstLine.resize (n);
  secondLine.resize (n);
  metro.resize (n);
  visited.resize (n);

  for (int i = 0; i < n; i++)
    cin >> firstLine[i];

  for (int i = 0; i < n; i++)
    cin >> secondLine[i];

  metro = constructGraph (firstLine, secondLine);

  if (canBobCommute (n, s - 1, 0, metro, visited))
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}
