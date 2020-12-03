#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int n = 0;
  int num = 0;
  int k = 0;

  deque <int> chat;
  set <int> messages;

  cin >> n >> k;

  for (int i = 0; i < n; i++)
    {
      cin >> num;
      
      if (messages.find (num) == messages.end ())
        {
	  if (chat.size () >= k)
	    {
	      messages.erase (chat.back ());
	      chat.pop_back ();
	    }

	  chat.push_front (num);
	  messages.insert (num);
	}
    }

  cout << chat.size () << "\n";
  for (auto i = chat.begin (); i != chat.end (); i++)
    cout << *i << " ";

  cout << "\n";

  return 0;
}
