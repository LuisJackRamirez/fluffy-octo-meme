#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair <char, int>
using namespace std;

int
main (void)
{
  char d = 0;
  int j = 0;
  int n = 0;
  int p = 0;
  int q = 0;
  int s = 0;

  map < pii, int >bookS;
  map < pii, int >bookB;
  map < pii, int >::iterator it;

  cin >> n >> s;

  for (int i = 0; i < n; i++)
    {
      cin >> d >> p >> q;

      if (d == 'B')
	{
	  it = bookB.find (pii ('B', p));

	  if (it == bookB.end ())
	    bookB.insert (make_pair (make_pair ('B', p), q));
	  else
	    it->second = it->second + q;
	}
      else
	{
	  it = bookS.find (pii ('S', p));

	  if (it == bookS.end ())
	    bookS.insert (make_pair (make_pair ('S', p), q));
	  else
	    it->second = it->second + q;
	}
    }

  map < pii, int >::iterator i;
  if (bookS.size () != 0)
    {
      i = bookS.begin ();
      do
	{
	  i++;
	  cout << i->f.f << " " << i->f.s << " " << i->s << "\n";
	  j++;

	  if (j >= s)
	    break;
	}
      while (i != bookS.end ());
    }

  j = 0;
  if (bookB.size () != 0)
    {
      i = bookB.end ();
      do
	{
	  --i;
	  cout << i->f.f << " " << i->f.s << " " << i->s << "\n";
	  j++;

	  if (j >= s)
	    break;
	}
      while (i != bookB.begin ());
    }

  return 0;
}
