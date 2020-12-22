#include <bits/stdc++.h>
using namespace std;

vector <string> readSeats (int &);
bool getChanges (vector <string> &, vector <vector <bool>> &);
void makeChanges (vector <string> &, vector <vector <bool>> &, int &);
int needsChange (vector <string> &, int, int, int);
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
        {
          makeChanges (seats, changes, availableSeats);
	  printVect (seats);
	}
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
	      //if (occupiedAdjSeats (seats, i, j) == 0)
	      if (needsChange (seats, i, j, 1) == 0)
	        {
		  changes[i][j] = true;
		  thereWasChange = true;
		}
	    }
	  else if (seats[i][j] == '#')
	    {
	      //if (occupiedAdjSeats (seats, i, j) >= 5)
	      if (needsChange (seats, i, j, 5) >= 5)
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
needsChange (vector <string> &seats, int row, int col, int req)
{
  bool searchN = true;
  bool searchNW = true;
  bool searchW = true;
  bool searchSW = true;
  bool searchS = true;
  bool searchSE = true;
  bool searchE = true;
  bool searchNE = true;
  int delta = 0;
  int numSearchDirections = 0;
  int seatsOcc = 0;

  numSearchDirections = 8;
  while (seatsOcc < req && numSearchDirections > 0)
    {
      delta++;

      if (searchN)
        {
	  if (row - delta < 0)
	    {
	      searchN = false;
	      numSearchDirections--;
	    }
	  else if (seats[row - delta][col] == 'L')
	    {
	      searchN = false;
	      numSearchDirections--;
	    }
	  else if (seats[row - delta][col] == '#')
	    {
	      searchN = false;
	      numSearchDirections--;
	      seatsOcc++;
	    }
	}
      
      if (searchNW)
        {
	  if (row - delta < 0 || col - delta < 0)
	    {
	      searchNW = false;
	      numSearchDirections--;
	    }
	  else if (seats[row - delta][col - delta] == 'L')
	    {
	      searchNW = false;
	      numSearchDirections--;
	    }
	  else if (seats[row - delta][col - delta] == '#')
	    {
	      searchNW = false;
	      numSearchDirections--;
	      seatsOcc++;
	    }
	}
      
      if (searchW)
        {
	  if (col - delta < 0)
	    {
	      searchW = false;
	      numSearchDirections--;
	    }
	  else if (seats[row][col - delta] == 'L')
	    {
	      searchW = false;
	      numSearchDirections--;
	    }
	  else if (seats[row][col - delta] == '#')
	    {
	      searchW = false;
	      numSearchDirections--;
	      seatsOcc++;
	    }
	}
      
      if (searchSW)
        {
	  if (row + delta >= seats.size () || col - delta < 0)
	    {
	      searchSW = false;
	      numSearchDirections--;
	    }
	  else if (seats[row + delta][col - delta] == 'L')
	    {
	      searchSW = false;
	      numSearchDirections--;
	    }
	  else if (seats[row + delta][col - delta] == '#')
	    {
	      searchSW = false;
	      numSearchDirections--;
	      seatsOcc++;
	    }
	}
      
      if (searchS)
        {
	  if (row + delta >= seats.size ())
	    {
	      searchS = false;
	      numSearchDirections--;
	    }
	  else if (seats[row + delta][col] == 'L')
	    {
	      searchS = false;
	      numSearchDirections--;
	    }
	  else if (seats[row + delta][col] == '#')
	    {
	      searchS = false;
	      numSearchDirections--;
	      seatsOcc++;
	    }
	}
      
      if (searchSE)
        {
	  if (row + delta >= seats.size () || col + delta >= seats[0].length ())
	    {
	      searchSE = false;
	      numSearchDirections--;
	    }
	  else if (seats[row + delta][col + delta] == 'L')
	    {
	      searchSE = false;
	      numSearchDirections--;
	    }
	  else if (seats[row + delta][col + delta] == '#')
	    {
	      searchSE = false;
	      numSearchDirections--;
	      seatsOcc++;
	    }
	}
      
      if (searchE)
        {
	  if (col + delta >= seats[0].length ())
	    {
	      searchE = false;
	      numSearchDirections--;
	    }
	  else if (seats[row][col + delta] == '#')
	    {
	      searchE = false;
	      numSearchDirections--;
	    }
	  else if (seats[row][col + delta] == '#')
	    {
	      searchE = false;
	      numSearchDirections--;
	      seatsOcc++;
	    }
	}
      
      if (searchNE)
        {
	  if (row - delta < 0 || col + delta >= seats[0].length ())
	    {
	      searchNE = false;
	      numSearchDirections--;
	    }
	  else if (seats[row - delta][col + delta] == '#')
	    {
	      searchNE = false;
	      numSearchDirections--;
	    }
	  else if (seats[row - delta][col + delta] == '#')
	    {
	      searchNE = false;
	      numSearchDirections--;
	      seatsOcc++;
	    }
	}
    }

  /*
  if (seatsOcc < req)
    return true;
  else
    return false;
  */

  return seatsOcc;
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
