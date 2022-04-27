#include <bits/stdc++.h>
using namespace std;

void
findFactors (long long int n)
{
  for (long long int p = 2; p*p <= n; p++)
    {
      //Divisor p no trivial de n,
      //es primo
      if (n % p == 0)
        {
	  int exponent = 0;
	  while (n % p == 0)
	    {
	      //Mientras n sea divisible entre p,
	      //se cuentan el número de divisiones
	      cout << "    " << p << "\n";
	      n /= p;
	      exponent++;
	    }
	}
    }

  //Si n > 1, significa que n' restante es primo,
  //entonces se imprime
  if (n > 1)
    cout << "    " << n << "\n";

  return;
}

int
main (void)
{
  long long int num;

  ios_base::sync_with_stdio (false);
  cin.tie (NULL);

  while (true)
    {
      cin >> num;
      if (num == -1)
        break;

      findFactors (num);
      cout << "\n";
    }

  return 0;
}
