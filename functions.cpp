#include <iostream>
#include <iomanip>
#include <string>
#include "functions.h"

using namespace std;

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
  //int currentHour = getHour();

  // if ((0 <= currentHour) && (currentHour <= 22))
  // {
  //   //setHour(currentHour + 1);
  // }
  // else
  // {
  //   //setHour(0);
  // }
}

void addOneMinute()
{
  //int currentMinute = getMinute();

  // if ((0 <= currentMinute) && (currentMinute <= 58))
  // {
  //   //setMinute(currentMinute + 1);
  // }
  // else
  // {
  //   //setMinute(0);
  //   addOneHour();
  // }
}

void addOneSecond()
{

  //int currentSecond = getSecond();

  // if ((0 <= currentSecond) && (currentSecond <= 58))
  // {
  //   //setSecond(currentSecond + 1);
  // }
  // else
  // {
  //   //setSecond(0);
  //   addOneMinute();
  // }
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

void mainMenu()
{
  cout << "Please enter a time." << endl;
  int userInput;
  while (getMenuChoice(userInput))
  {
    switch (userInput)
    {
    case 1:
      addOneHour();
      displayClocks(10, 10, 10);
      break;
    case 2:
      addOneMinute();
      displayClocks(20, 20, 20);
      break;
    case 3:
      addOneSecond();
      displayClocks(30, 30, 30);
      break;
    case 4:
      return;
    default:
      cout << "Invalid entry." << endl;
      continue;
    }
  }
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