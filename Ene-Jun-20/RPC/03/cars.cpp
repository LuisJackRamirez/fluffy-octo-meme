#include <bits/stdc++.h>
using namespace std;

//Structs
struct Point
{
  double x;
  double y;

  Point (double x, double y): x (x), y (y) {}
};

struct Rectangle
{
  Point P1;
  Point P2;
  
  char direction;
  int speed;

  Rectangle (): P1(0, 0), P2 (0, 0) {}
  Rectangle (Point one, Point two): P1 (one), P2 (two) {}
};

//Functions
void rectAdvances (Rectangle &);
bool rectsIntersect (Rectangle, Rectangle);
Rectangle initializeRectangle (int, int, int, int, char, int);

int
main (void)
{
  bool carsCrashed = false;
  char d = '0';
  int s = 0;
  int l = 0;
  int t = 0;
  int x = 0;
  int y = 0;
  int w = 0;

  cin >> t;

  cin >> d >> x >> y >> s >> w >> l;
  Rectangle one = initializeRectangle (x, y, w, l, d, s);
  
  cin >> d >> x >> y >> s >> w >> l;
  Rectangle two = initializeRectangle (x, y, w, l, d, s);

  while (--t)
    {
      rectAdvances (one);
      rectAdvances (two);

      if (rectsIntersect (one, two))
        {
	  carsCrashed = true;
	  break;
	}
    }

  if (carsCrashed)
    cout << "crash\n";
  else
    cout << "safe\n";

  return 0;
}

void
rectAdvances (Rectangle &rect)
{
  if (rect.direction == 'N')
    {
      rect.P1.y = rect.P1.y + rect.speed;
      rect.P2.y = rect.P2.y + rect.speed;
    }
  else if (rect.direction == 'S')
    {
      rect.P1.y = rect.P1.y - rect.speed;
      rect.P2.y = rect.P2.y - rect.speed;
    }
  else if (rect.direction == 'E')
    {
      rect.P1.x = rect.P1.x + rect.speed;
      rect.P2.x = rect.P2.x + rect.speed;
    }
  else if (rect.direction == 'W')
    {
      rect.P1.x = rect.P1.x - rect.speed;
      rect.P2.x = rect.P2.x - rect.speed;
    }
}

bool
rectsIntersect (Rectangle r1, Rectangle r2)
{
  //One rectangle is completely above the other
  if (r1.P1.y > r2.P2.y || r1.P2.y < r2.P1.y)
    return false;

  //One rectangle is entirely to the side of the other
  if (r1.P1.x > r2.P2.x || r1.P2.x < r2.P1.x)
    return false;

  return true;
}

Rectangle
initializeRectangle (int x, int y, int width, int length, char d, int s)
{
  Rectangle r;

  if (d == 'N' || d == 'S')
    {
      r.P1.x = (double) x - ((double) width / 2);
      r.P1.y = (double) y - ((double) length / 2);
      r.P2.x = (double) x + ((double) width / 2);
      r.P2.y = (double) y + ((double) length / 2);
    }
  else
    {
      r.P1.x = (double) x - ((double) length / 2);
      r.P1.y = (double) y - ((double) width / 2);
      r.P2.x = (double) x + ((double) length / 2);
      r.P2.y = (double) y + ((double) width / 2);
    }

  r.direction = d;
  r.speed = s;

  return r;
}
