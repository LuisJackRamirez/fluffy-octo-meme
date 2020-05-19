#include <bits/stdc++.h>
using namespace std;

const int size = 26;

int
main (void)
{
  int hostGuest[size];
  int jokeBucket[size];
  string host;
  string guest;
  string joke;

  memset (hostGuest, 0, sizeof (hostGuest));
  memset (jokeBucket, 0, sizeof (jokeBucket));

  cin >> host >> guest >> joke;

  for (int i = 0; i < host.length (); i++)
    hostGuest[host[i] - 'A']++;
  
  for (int i = 0; i < guest.length (); i++)
    hostGuest[guest[i] - 'A']++;

  for (int i = 0; i < joke.length (); i++)
    jokeBucket[joke[i] - 'A']++;

  for (int i = 0; i < size; i++)
    if (hostGuest[i] != jokeBucket[i])
      {
        cout << "NO\n";
	return 0;
      }

  cout << "YES\n";
  return 0;
}
