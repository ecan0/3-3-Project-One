#include <iostream>
#include <iomanip>
#include <string>
#include "functions.h"

using namespace std;

// print functions to screen
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

  void displayClocks(unsigned int h, unsigned int m, unsigned int s)
  {
    cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl;
    cout << "*" << "      " << "12-HOUR CLOCK" << "      " << "*" << endl;
    cout << "*" << "      " << "24-HOUR CLOCK" << "      " << "*" << endl;
    cout << endl;
    cout << "*" << "      " << formatTime12(h,m,s) << "      " << "*" << endl;
    cout << "*" << "      " << formatTime24(h,m,s) << "      " << "*" << endl;
    cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl;
  }

  unsigned int getMenuChoice(unsigned int maxChoice)
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