#include <bits/stdc++.h>
using namespace std;

vector <string> readSeats (int &);
bool getChanges (vector <string> &, vector <vector <bool>> &);
void makeChanges (vector <string> &, vector <vector <bool>> &, int &);
int occupiedAdjSeats (vector <string> &, int, int);
void printVect (vector <string> &);

int
main (void)
{
  bool thereWasChange = false;
  int availableSeats = 0;
  int totalSeats = 0;

  vector <string> seats;

  seats = readSeats (availableSeats);
  totalSeats = availableSeats;
  vector <vector <bool>> changes (seats.size (),
				     vector < bool > (seats[0].length ()));

  thereWasChange = true;
  while (thereWasChange == true)
    {
      thereWasChange = getChanges (seats, changes);
      if (thereWasChange == true)
        makeChanges (seats, changes, availableSeats);
    }

  cout << totalSeats - availableSeats << "\n";

  return 0;
}

bool
getChanges (vector <string> &seats, vector <vector <bool>> &changes)
{
  bool thereWasChange = false;

  for (int i = 0; i < seats.size (); i++)
    {
      for (int j = 0; j < seats[i].size (); j++)
        {
	  if (seats[i][j] == 'L')
	    {
	      if (occupiedAdjSeats (seats, i, j) == 0)
	        {
		  changes[i][j] = true;
		  thereWasChange = true;
		}
	    }
	  else if (seats[i][j] == '#')
	    {
	      if (occupiedAdjSeats (seats, i, j) >= 4)
	        {
		  changes[i][j] = true;
		  thereWasChange = true;
		}
	    }
	}
    }

  return thereWasChange;
}

void
makeChanges (vector <string> &seats, vector <vector <bool>> &changes, int &availableSeats)
{
  for (int i = 0; i < seats.size (); i++)
    {
      for (int j = 0; j < seats[i].size (); j++)
        {
	  if (changes[i][j] == true)
	    {
	      if (seats[i][j] == 'L')
	        {
		  seats[i][j] = '#';
		  availableSeats--;
		}
	      else if (seats[i][j] == '#')
	        {
		  seats[i][j] = 'L';
		  availableSeats++;
		}

	      changes[i][j] = false;
	    }
	}
    }
}

int
occupiedAdjSeats (vector <string> &seats, int row, int col)
{
  int occupiedSeats = 0;

  for (int i = row - 1; i <= row + 1; i++)
    {
      if (i >= 0 && i < seats.size ())
        {
	  for (int j = col - 1; j <= col + 1; j++)
	    {
	      if (j >= 0 && j < seats[i].size ())
	        {
		  if (!(i == row && j == col))
		    {
		      if (seats[i][j] == '#')
		        occupiedSeats++;
		    }
		}
	    }
	}
    }

  return occupiedSeats;
}

void
printVect (vector <string> &vect)
{
  for (int i = 0; i < vect.size (); i++)
    cout << vect[i] << "\n";

  cout << "\n";
}

vector <string> readSeats (int &availableSeats)
{
  string str;
  vector <string> seats;

  while (getline (cin, str))
    {
      for (int i = 0; i < str.length (); i++)
	{
	  if (str[i] == 'L')
	    availableSeats++;
	}

      seats.push_back (str);
    }

  return seats;
}
