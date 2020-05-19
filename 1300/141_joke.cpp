#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  string host;
  string guest;
  string hostGuest;
  string joke;

  cin >> host >> guest >> joke;
  
  hostGuest = host.append (guest);

  sort (hostGuest.begin (), hostGuest.end ());
  sort (joke.begin (), joke.end ());

  if (hostGuest.compare (joke) == 0)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}
