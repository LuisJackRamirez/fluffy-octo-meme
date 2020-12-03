#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

bool comp (pair <string, int>, pair <string, int>);
void add (map <string, int> &, string, int);
void sorted (map <string, int> &);

int
main (void)
{
  int n = 0;
  string name;
  map <string, int> messages;

  cin >> n;

  for (int i = 0; i < n; i++)
    {
      cin >> name;
      add (messages, name, i);  
    }

  sorted (messages);

  return 0;
}

bool
comp (pair <string, int> A, pair <string, int> B)
{
  return A.s > B.s;
}

void 
add (map <string, int> &messages, string name, int i)
{
  map <string, int>::iterator it;

  it = messages.find (name);
  if (it == messages.end ())
    messages.insert (pair <string, int> (name, i));
  else
    it->s = i;
}

void
sorted (map <string, int> &messages)
{
  vector <pair <string, int>> v;

  for (auto it = messages.begin (); it != messages.end (); it++)
    v.push_back (pair <string, int> (it->f, it->s));

  sort (v.begin (), v.end (), comp);

  for (int i = 0; i < v.size (); i++)
    cout << v[i].f << "\n";
}
