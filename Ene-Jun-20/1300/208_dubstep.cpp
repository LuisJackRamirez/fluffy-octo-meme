#include <bits/stdc++.h>
using namespace std;

string ogSong (string &);

int
main (void)
{
  string song;
  string og;

  cin >> song;

  og = ogSong (song);

  cout << og << "\n";

  return 0;
}

string
ogSong (string & song)
{
  bool wub[3] = { false, false, false };
  string res;

  vector < int >wubIdx;

  for (int i = 0; i < song.length (); i++)
    {
      if (song[i] == 'W')
	wub[0] = true;
      else if (song[i] == 'U' && wub[0])
	wub[1] = true;
      else if (song[i] == 'B' && wub[0] && wub[1])
	wub[2] = true;
      else
	{
	  wub[0] = false;
	  wub[1] = false;
	  wub[2] = false;
	}

      if (wub[0] && wub[1] && wub[2])
	{
	  wubIdx.push_back (i - 2);

	  wub[0] = false;
	  wub[1] = false;
	  wub[2] = false;
	}
    }

  if (wubIdx.empty ())
    return song;
  else if (wubIdx[0] != 0)
    res.append (song.substr (0, wubIdx[0]) + " ");

  for (int i = 1; i < wubIdx.size (); i++)
    {
      if (wubIdx[i] - wubIdx[i - 1] > 3)
	res.append (song.substr (wubIdx[i - 1] + 3,
				 wubIdx[i] - wubIdx[i - 1] - 3) + " ");
    }

  if (song[wubIdx[wubIdx.size () - 1] + 3] != '\000')
    res.append (song.substr (wubIdx[wubIdx.size () - 1] + 3));

  return res;
}
