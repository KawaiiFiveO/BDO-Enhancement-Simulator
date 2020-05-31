using namespace std;
#include <iostream>
#include <cstdlib>
#include <time.h>

int main ()
{
  string again = "y";
  while (again == "y") {
  string crons = "";
  int times = 0;
  int failstack = 0;
  double start = 0;
  int multiplier = 0;
  double plus = 0;
  int type = 0;
  double test = 0;
  int success = 0;

  srand ((unsigned int) time (NULL));

  cout << "Starting failstacks: ";
  cin >> failstack;
  if (failstack < 0)
    {
      cout << "Error: Invalid failstacks";
      exit (EXIT_FAILURE);
    }

  cout << "Enhancement type (1 TRI, 2 TET, 3 PEN, 4 +15, Blackstar 5, 6, 7): ";
  cin >> type;
  if (type == 1)
    {
      start = 6.25;
      multiplier = 4;
    }
  else if (type == 2)
    {
      start = 2;
      multiplier = 5;
    }
  else if (type == 3)
    {
      start = .3;
      multiplier = 6;
    }
  else if (type == 4)
    {
      start = 2;
      multiplier = 1;
    }
  else if (type == 5)
    {
      start = 3.4;
      multiplier = 4;
    }
  else if (type == 6)
    {
      start = .51;
      multiplier = 5;
    }
  else if (type == 7)
    {
      start = .2;
      multiplier = 6;
    }
  else
    {
      cout << "Error: Invalid enhancement type\n";
      exit (EXIT_FAILURE);
    }

  cout << "Use Cron Stones? (y/n): ";
  cin >> crons;
  if (crons == "y")
    {
	  multiplier = 0;
    }
	
  cout << "Number of attempts: ";
  cin >> times;
  if (times < 1)
    {
      cout << "Error: Invalid attempts";
      exit (EXIT_FAILURE);
    }
  
  plus = start / 10;
  double first = start + (failstack * plus);
  start = 1 - (start / 100);
  plus = plus / 100;
  double chance = start;
  start = start - (failstack * plus);
  double recursive = 1;

  for (int i = 0; i < times; i++)
    {
      recursive = recursive * start;
      test = ((float) rand () / (float) (RAND_MAX));
      if (test > start)
	{
	  success++;
	cout << "Enhancement Success! (+" << failstack << " " << 100*(1-start) << "%)\n";
	}
	  else if (crons == "y")
	{
	  cout << "Enhancement Failed, Item Protected\n";
	}
      else
	{
	  cout << "Enhancement Failed, Enhancement Level Drop (+" << failstack << " " << 100*(1-start) << "%)\n";
	}
	  start = start - (plus * multiplier);
      failstack = failstack + multiplier;
    }

  chance = chance - (plus * failstack);
  recursive = (1 - recursive) * 100;
  chance = (1 - chance) * 100;
  cout << "You succeeded " << success << " time(s) out of " << times << ".\n";
  cout << failstack << " failstacks at end\n";
  cout << first << "% chance to succeed on first click\n";
  cout << recursive << "% chance to succeed at least once\n";
  cout << chance << "% chance to succeed on the next attempt\n";
  cout << "Continue? (y/n): ";
  cin >> again;
  }
  return 0;
}