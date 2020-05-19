#include <bits/stdc++.h>
using namespace std;

string kString (string &, int);

int
main (void)
{
  int k = 0;

  string str;
  string res;

  cin >> k;
  cin >> str;

  res = kString (str, k);

  cout << res << "\n";

  return 0;
}

string
kString (string &str, int k)
{
  int aux = 0;
  int max = 0;
  string auxStr;
  string res;

  map <char, int> bucket;
  map <char, int>::iterator it;

  for (int i = 0; i < str.size (); i++)
    {
      it = bucket.find (str[i]);

      if (it == bucket.end ())
        bucket.insert (make_pair (str[i], 1));
      else
        it->second++;
    }

  for (auto i = bucket.begin (); i != bucket.end (); i++)
    {
      if (i->second % k != 0)
        return "-1";
      else
        {
	  for (int j = 0; j < i->second / k; j++)
            auxStr += i->first;
	}
    }

  aux = str.length () / auxStr.length ();

  for (int i = 0; i < aux; i++)
    res.append (auxStr);

  return res;
}
