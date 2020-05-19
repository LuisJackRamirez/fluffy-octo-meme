#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int
main ()
{

  lli c = 0, n = 0, m = 0, aux = 0;
  cin >> c >> n >> m;

  multiset < lli > mu;
  map < lli, lli > ma;

  for (lli i = 0; i < n; i++)
    {
      cin >> aux;

      if (aux > c)
	{

	  lli llevar = aux / 2;
	  lli dejar = aux - llevar;
	  mu.insert (dejar);
	  mu.insert (llevar);
	}

      else
	mu.insert (aux);

    }

  ma.insert (
	      {
	      0, mu.size ()}
  );

  for (lli i = 1; i <= m; i++)
    {
      multiset < lli > ref;
      for (auto it = mu.begin (); it != mu.end (); it++)
	{
	  lli temp = *it;
	  temp *= 2;
	  if (temp > c)
	    {

	      lli llevar = temp / 2;
	      lli dejar = temp - llevar;


	      ref.insert (dejar);
	      ref.insert (llevar);
	    }
	  else
	    ref.insert (temp);

	}

      ma.insert (
		  {
		  i, ref.size ()}
      );
      mu.clear ();
      mu = ref;
      ref.clear ();
    }


  lli q = 0;
  for (lli i = 0; i < m; i++)
    {
      cin >> q;
      auto it = ma.find (q);

      cout << it->second << endl;

    }





  return 0;
}
