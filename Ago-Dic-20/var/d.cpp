#include <bits/stdc++.h>
#define lli long long int
#define mod 1000000007
using namespace std;

int
main (void)
{
  int n = 0;
  lli sum = 0;
  lli ans = 0;

  vector <int> A;

  cin >> n;
  A.resize (n);

  for (int i = 0; i < n; i++)
    {
      //A[i]*A[i+1] + A[i]*A[i+2] + ... + A[i]*A[n]
      //Eso se puede simplificar a:
      //A[i] * (A[i+1] + A[i+2] + ... + A[n])
      cin >> A[i];
      sum = sum + A[i];

      //A menos que sea división, el módulo es asociativo
      sum = sum % mod;
    }

  for (int i = 0; i < n; i++)
    {
      //Sustrayendo el elemento A[i], podemos obtener
      //A[i+1] + A[i+2] + ... + A[n] en O(1)
      sum = sum - A[i];

      //Si la suma es menor a cero, significa que hubo un
      //desborde inverso del modulo, y nos regresamos a la
      //cima
      if (sum < 0)
        sum = sum + mod;

      //A[i] * (A[i+1] + A[i+2] + ... + A[n])
      ans = ans + (A[i] * sum);

      //A menos que sea división, el módulo es asociativo
      ans = ans % mod;
    }

  cout << ans << "\n";

  return 0;
}
