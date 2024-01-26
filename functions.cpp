#include <iostream>
#include <iomanip>
#include <string>
#include "functions.h"

using namespace std;

int hours;
int minutes;
int seconds;

string nCharString(size_t n, char c)
{
  return string(static_cast<int>(n), c);
}
// print functions to screen
string twoDigitString(int n)
{
  string convertedOutput = to_string(n);

  if ((0 <= n) && (n <= 9))
    convertedOutput = '0' + convertedOutput;

  return convertedOutput;
}

int getMenuChoice(int maxChoice)
{
  int input;

  while (cin >> input)
  {
    if (input >= 1 && input <= maxChoice)
    {
      break;
    }
  }
  return input;
}

void addOneHour()
{
  if ((0 <= hours) && (hours <= 22))
  {
    hours = hours+1;
  }
  else
  {
    hours = 0;
  }
}

void addOneMinute()
{
  if ((0 <= minute) && (minute <= 58))
  {
    minute = minute+1;
  }
  else
  {
    minute = 0;
    addOneHour();
  }
}

void addOneSecond()
{
  if ((0 <= seconds) && (seconds <= 58))
  {
    seconds = seconds+1;
  }
  else
  {
    seconds=0;
    addOneMinute();
  }
}

string formatTime24(int h, int m, int s)
{
  return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
}

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

void displayClocks(int h, int m, int s)
{
  cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl;
  cout << "*"
       << "      "
       << "12-HOUR CLOCK"
       << "      "
       << "*" << endl;
  cout << "*"
       << "      "
       << "24-HOUR CLOCK"
       << "      "
       << "*" << endl;
  cout << endl;
  cout << "*"
       << "      " << formatTime12(h, m, s) << "      "
       << "*" << endl;
  cout << "*"
       << "      " << formatTime24(h, m, s) << "      "
       << "*" << endl;
  cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl;
}

void getUserTime()
{
  int input;
  cout << "Welcome to the Chada Tech clock!" << endl;
  cout << "Enter your times!" << endl;
  cout << "Hours (between 0-24 please)";
  while (cin >> input)
  {
    if ((input >= 0 && input <= 24))
    {
      hours = input;
      break;
    }
    else
    {
      cout << "That seems to be incorrect, try that again between 0 and 24.";
      continue;
    }
  }
  cout << "Minutes: (between 0-59 please) ";
  while (cin >> input)
  {
    if ((input >= 0 && input <= 59))
    {
      minutes = input;
      break;
    }
    else
    {
      cout << "That seems to be incorrect, try that again between 0 and 59.";
      continue;
    }
  }
  cout << "Seconds (between 0-59 please): ";
  while (cin >> input)
  {
    if ((input >= 0 && input <= 59))
    {
      seconds = input;
      break;
    }
    else
    {
      cout << "That seems to be incorrect, try that again between 0 and 59.";
      continue;
    }
  }
  displayClocks(hours,minutes,seconds);
}

void printMenu()
{
  cout << nCharString(26, '*') << endl;
  cout << "* 1 - Add One Hour        *" << endl;
  cout << "* 2 - Add One Minute      *" << endl;
  cout << "* 3 - Add One Second      *" << endl;
  cout << "* 4 - Exit Program        *" << endl;
  cout << nCharString(26, '*') << endl;
}

void mainMenu()
{
  cout << "Congratulations! You have entered a valid time. Above are your times in 12 and 24 hours." << endl;
  cout << "Please update the time according to the choices below." << endl;
  printMenu();
  int userInput;
  while (getMenuChoice(userInput))
  {
    switch (userInput)
    {
    case 1:
      addOneHour();
      displayClocks(hours, minutes, seconds);
      break;
    case 2:
      addOneMinute();
      displayClocks(hours, minutes, seconds);
      break;
    case 3:
      addOneSecond();
      displayClocks(hours, minutes, seconds);
      break;
    case 4:
      return;
    default:
      cout << "Invalid entry." << endl;
      continue;
    }
  }
}