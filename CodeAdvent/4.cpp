#include <bits/stdc++.h>
using namespace std;

bool isValid (string &);
bool checkByr (string &, int);
bool checkIyr (string &, int);
bool checkEyr (string &, int);
bool checkHgt (string &, int);
bool checkHcl (string &, int);
bool checkEcl (string &, int);
bool checkPid (string &, int);

int
main (void)
{
  int validPassports = 0;
  string str;
  string passportData;

  while (getline (cin, str))
    {
      while (str != "")
	{
	  passportData.append (str + " ");
	  getline (cin, str);
	}

      if (isValid (passportData))
	validPassports++;

      passportData.clear ();
    }

  cout << validPassports << "\n";

  return 0;
}

bool
checkByr (string & data, int pos)
{
  int year = 0;
  string str;

  while (data[pos] != ' ')
    {
      str.push_back (data[pos]);
      pos++;
    }

  if (str.length () != 4)
    return false;

  year = stoi (str);
  if (year >= 1920 && year <= 2002)
    return true;
  else
    return false;
}

bool
checkIyr (string & data, int pos)
{
  int year = 0;
  string str;

  for (int i = pos; data[i] != ' '; i++)
    str.push_back (data[i]);

  if (str.length () != 4)
    return false;

  year = stoi (str);
  if (year >= 2010 && year <= 2020)
    return true;
  else
    return false;
}

bool 
checkEyr (string & data, int pos)
{
  int year = 0;
  string str;

  for (int i = pos; data[i] != ' '; i++)
    str.push_back (data[i]);

  if (str.length () != 4)
    return false;

  year = stoi (str);
  if (year >= 2020 && year <= 2030)
    return true;
  else
    return false;
}

bool
checkHgt (string &data, int pos)
{
  int units = 0;		//centimeters: 0, inches: 1
  int height = 0;
  string str;

  for (int i = pos; data[i] != ' '; i++)
    {
      if (isdigit (data[i]) == 0)
	{
	  if (data[i] != 'c' && data[i] != 'i')
	    return false;
	  else
	    {
	      if (data[i] == 'i')
		units = 1;
	    }

	  break;
	}

      str.push_back (data[i]);
    }

  height = stoi (str);

  switch (units)
    {
    case 0:
      if (height >= 150 && height <= 193)
	return true;
      else
	return false;
      break;

    case 1:
      if (height >= 59 && height <= 76)
	return true;
      else
	return false;
      break;
    }
}

bool
checkHcl (string & data, int pos)
{
  int height = 0;
  string str;

  if (data[pos] != '#')
    return false;

  for (int i = pos + 1; data[i] != ' '; i++)
    {
      if (isdigit (data[i]) == 0)
	{
	  if (data[i] < 'a' || data[i] > 'f')
	    return false;
	}

      str.push_back (data[i]);
    }

  if (str.length () == 6)
    return true;
  else
    return false;
}

bool
checkEcl (string & data, int pos)
{
  string str;

  for (int i = pos; data[i] != ' '; i++)
    str.push_back (data[i]);

  if (str == "amb" || str == "blu" || str == "brn" || str == "gry"
      || str == "grn" || str == "hzl" || str == "oth")
    return true;
  else
    return false;
}

bool
checkPid (string & data, int pos)
{
  string str;

  for (int i = pos; data[i] != ' '; i++)
    str.push_back (data[i]);

  if (str.length () == 9)
    return true;
  else
    return false;
}

bool
isValid (string & passport)
{
  bool byrValid = false;
  bool iyrValid = false;
  bool eyrValid = false;
  bool hgtValid = false;
  bool hclValid = false;
  bool eclValid = false;
  bool pidValid = false;
  int byrPos = passport.find ("byr:") + 4;
  int iyrPos = passport.find ("iyr:") + 4;
  int eyrPos = passport.find ("eyr:") + 4;
  int hgtPos = passport.find ("hgt:") + 4;
  int hclPos = passport.find ("hcl:") + 4;
  int eclPos = passport.find ("ecl:") + 4;
  int pidPos = passport.find ("pid:") + 4;

  if (byrPos != 3 && iyrPos != 3 && eyrPos != 3 && hgtPos != 3 && hclPos != 3
      && eclPos != 3 && pidPos != 3)
    {
      byrValid = checkByr (passport, byrPos);
      iyrValid = checkIyr (passport, iyrPos);
      eyrValid = checkEyr (passport, eyrPos);
      hgtValid = checkHgt (passport, hgtPos);
      hclValid = checkHcl (passport, hclPos);
      eclValid = checkEcl (passport, eclPos);
      pidValid = checkPid (passport, pidPos);

      if (byrValid && iyrValid && eyrValid && hgtValid && hclValid && eclValid
	  && pidValid)
	return true;
      else
	return false;
    }
  else
    return false;
}
