#include <bits/stdc++.h>
using namespace std;

int
main ()
{

  int n = 0, aux = 0;
  cin >> n;
  multiset < int >po, ne;
  vector < int >ans;
  bool ba = false;

  for (int i = 0; i < n; i++)
    {
      cin >> aux;
      if (aux > 0)
	po.insert (aux);
      else
	ne.insert (aux);
    }

  if (po.size () == 0)
    cout << "Error" << endl;
  else if (ne.size () == 0)
    {
      int sum1 = 0;
      for (auto it = po.begin (); it != po.end (); it++)
	{
	  sum1 += *it;
	  if (sum1 > 99999999)
	    ba = true;
	  ans.push_back (*it);
	}
    }

  else
    {
      int suma = 0, x = 0;
      auto it = po.rbegin ();
      auto it2 = ne.begin ();

      while (it != po.rend ())
	{
	  ans.push_back (*it);
	  x = *it;
	  suma += x;

	  if (suma > 99999999)
	    ba = true;

	  while ((x - *it2 >= 0) && it2 != ne.end ())
	    {
	      x += *it2;
	      suma += *it2;

	      if (suma < -99999999)
		ba = true;

	      ans.push_back (*it2);
	      it2++;
	    }
	  it++;
	}
    }

  if (ba)
    cout << "Error " << endl;
  else
    for (int i = 0; i < ans.size (); i++)
      cout << ans[i] << endl;


  return 0;
}
