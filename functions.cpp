#include <iostream>
#include <iomanip>
#include <string>
#include <limits> // Include for numeric_limits.
#include "functions.h"

using namespace std;

//variables to control our time. these will be updated by the functions
int hours;
int minutes;
int seconds;

//accessor functions for our times.
int getHours() { return hours; }

int getMinutes() { return minutes; }

int getSeconds() { return seconds; }

//returns a number of chars as specified by n.
string nCharString(size_t n, char c)
{
  return string(static_cast<size_t>(n), c);
}

//Appends 0 to time value if it's between 0-9 for formatting purposes.
string twoDigitString(int n)
{
  string convertedOutput = to_string(n);

  if ((0 <= n) && (n <= 9))
    convertedOutput = '0' + convertedOutput;

  return convertedOutput;
}

//Takes user input value of 1-4 and checks to ensure it's an integer value.
int getMenuChoice(int maxChoice)
{
  int input;

  //loops until recieves correct input
  while (true)
  {
    cout << endl
         << "Enter your choice (1-" << maxChoice << "): ";

    // Check if the input is an integer
    if (cin >> input)
    {
      // Check if the input is within the valid range
      if (input >= 1 && input <= maxChoice)
      {
        break;
      }
      else
      {
        cout << endl << "Invalid choice. Please enter a number between 1 and " << maxChoice << "." << endl;
      }
    }
    else
    {
      // Handle non-integer input
      cout << endl << "Invalid input. Please enter a valid integer." << endl;
      cin.clear();                                         // Clear the error state
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }
  }
  return input;
}

//Check if input is between 0 and 22. Edge case of 23 will reset to 00 hours if needed to add.
void addOneHour()
{
  if ((0 <= hours) && (hours <= 22))
  {
    hours = hours + 1;
  }
  else
  {
    hours = 0;
  }
}

//Check if input is between 0 and 58. Edge case of 59 will reset to 00 hours if needed to add.
void addOneMinute()
{
  if ((0 <= minutes) && (minutes <= 58))
  {
    minutes = minutes + 1;
  }
  else
  {
    minutes = 0;
    addOneHour();
  }
}

//Check if input is between 0 and 58. Edge case of 59 will reset to 00 hours if needed to add.
void addOneSecond()
{
  if ((0 <= seconds) && (seconds <= 58))
  {
    seconds = seconds + 1;
  }
  else
  {
    seconds = 0;
    addOneMinute();
  }
}

//Display 24 hour as string formatted in HH:MM:SS.
string formatTime24(int h, int m, int s)
{
  return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
}

//Display 12 hour as string formatted in HH:MM:SS A M/P M.
string formatTime12(int h, int m, int s)
{
  // variable to delegate if it's AM or PM
  string timeSuffix;

  if ((0 <= h) && (h <= 11))
  {
    timeSuffix = " A M";
    // edge case for midnight
    if (h == 0)
    {
      h = 12;
    }
  }
  else
  {
    timeSuffix = " P M";
    // edge case for noon
    if (h != 12)
      h = h - 12;
  }
  string formattedTime = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + timeSuffix;
  return formattedTime;
}


//Displays both times in 12/24 hr format simultaneously.
//Compared to the Sense solution, I think mine is simpler and more readible. 
//It also omits unnecessary calculations since everything is a fixed length anyway.
void displayClocks(int h, int m, int s)
{
  cout<< endl << "***************************  ***************************" << endl;
	cout<< "*       12-Hour Clock     *  *       24-Hour Clock     *" << endl;
	cout<< "*       " << formatTime12(h,m,s) << "      *  *       " << formatTime24(h,m,s) << "          *" << endl;
	cout<< "***************************  ***************************" << endl;
}

//Entry prompt to get the initial time from the user.
void getUserTime()
{
  int input;
  cout << "Welcome to the Chada Tech clock!" << endl;
  cout << endl
       << "Enter your times!" << endl;
  cout << endl
       << "Hours (between 0-24 please): ";

  //Loops for input and determines hours, minutes, and seconds.
  while (cin >> input)
  {
    //Checks for hour inputs between 0 and 23.
    if ((input >= 0 && input <= 23))
    {
      hours = input;
      break;
    }
    else
    {
      cout << endl
           << "That seems to be incorrect, try that again between 0 and 24." << endl;
      continue;
    }
  }

  //Clear input buffer for next input.
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  //Checks for minute inputs between 0 and 59.
  cout << endl
       << "Minutes (between 0-59 please): ";
  while (cin >> input)
  {
    if ((input >= 0 && input <= 59))
    {
      minutes = input;
      break;
    }
    else
    {
      cout << endl
           << "That seems to be incorrect, try that again between 0 and 59." << endl;
      continue;
    }
  }
  //Clear input buffer for next input.
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  
  //Checks for second inputs between 0 and 59.
  cout << endl
       << "Seconds (between 0-59 please): ";
  while (cin >> input)
  {
    if ((input >= 0 && input <= 59))
    {
      seconds = input;
      break;
    }
    else
    {
      cout << endl
           << "That seems to be incorrect, try that again between 0 and 59." << endl;
      continue;
    }
  }
  //Clear input buffer for next input.
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  //After all inputs are logged and loops end, display time.
  displayClocks(hours, minutes, seconds);
}

//Print the user options for adding time amounts and exit.
void printMenu()
{
  cout << endl
       << nCharString(26, '*') << endl;
  cout << "* 1 - Add One Hour       *" << endl;
  cout << "* 2 - Add One Minute     *" << endl;
  cout << "* 3 - Add One Second     *" << endl;
  cout << "* 4 - Exit Program       *" << endl;
  cout << nCharString(26, '*') << endl;
}