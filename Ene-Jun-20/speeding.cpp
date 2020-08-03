#include <bits/stdc++.h>
using namespace std;

int
main (void)
{
  int N = 0;
  float vel = 0;
  int time[2] = {0, 0};
  int distance[2] = {0, 0};
  float max = 0;

  cin >> N;

  cin >> time[0] >> distance[0];

  for (int i = 0; i < N - 1; i++)
    {
      cin >> time[1] >> distance[1];
      
      vel = (distance[1] - distance[0])/(time[1] - time[0]);

      if (vel > max)
        max = vel;

      distance[0] = distance[1];
      time[0] = time[1];
    }

  cout << (int) vel << "\n";

  return 0;
}
