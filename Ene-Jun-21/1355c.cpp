#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int
main (void)
{
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  vector <lli> sumXY ((int) 1e6 + 77);
  lli res = 0;

  cin >> a >> b >> c >> d;
  for (int i = a; i <= b; i++)
    {
      /*
       * Iterando sobre todos los pares (x,y) podemos
       * obtener el número de pares x,y que resultan en
       * x+y. . 
       */
      sumXY[i + b]++;
      sumXY[i + c + 1]--;
    }

  for (int i = 1; i < 1e6 + 77; i++)
    sumXY[i] = sumXY[i] + sumXY[i - 1];
  
  for (int i = 1; i < 1e6 + 77; i++)
    sumXY[i] = sumXY[i] + sumXY[i - 1];

  for (int i = c; i <= d; i++)
    res = res + sumXY[(int) 1e6 + 77 - 1] - sumXY[i];

  cout << res << "\n";

  return 0;
}
