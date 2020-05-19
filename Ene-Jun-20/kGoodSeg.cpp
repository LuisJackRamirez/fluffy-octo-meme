#include <bits/stdc++.h>
using namespace std;

int bucket[1000001];

int
main (void)
{
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);

  int distinct = 0;
  int l = 0;
  int r = 0;
  int n = 0;
  int k = 0;
  int res = 0;
  int lRes = 0;
  int rRes = 0;

  vector < int >a;

  cin >> n >> k;
  a.resize (n);

  memset (bucket, 0, sizeof (bucket));

  for (int i = 0; i < n; i++)
    cin >> a[i];

  l = 0;
  r = 0;

  while (r < n)
    {
      if (distinct < k)
	{
	  bucket[a[r]]++;
	  
	  if (bucket[a[r]] == 1)
	    distinct++;

	  r++;
	}
      else if (distinct == k)
	{
	  if (bucket[a[r]] == 0)
	    {
	      if (r - l > res)
		{
		  res = r - l;
		  lRes = l + 1;
		  rRes = r + 1;
		}

	      bucket[a[l]]--;

	      if (bucket[a[l]] == 0)
		distinct--;

	      l++;
	    }
	  else
	    {
	      bucket[a[r]]++;
	      r++;
	    }
	}

      if (r - l > res)
	{
	  res = r - l;
	  lRes = l + 1;
	  rRes = r;
	}
    }

  cout << lRes << " ";
  cout << rRes << "\n";

  return 0;
}
