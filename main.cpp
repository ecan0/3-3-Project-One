#include <iostream>
#include <iomanip>
#include <string>
#include "functions.h"

using namespace std;

void getUserTime();
void printMenu();
int getMenuChoice(int maxChoice);
void addOneHour();
void addOneMinute();
void addOneSecond();
int getHours();
int getMinutes();
int getSeconds();
void displayClocks(int h, int m, int s);

int main() 
{
  getUserTime();
  cout << "Congratulations! You have entered a valid time. Above are your times in 12 and 24 hours." << endl;
  int userInput;

  do
  {
    cout << "Please update the time according to the choices below." << endl;
    printMenu();
    if (getMenuChoice(userInput))
    {
      switch (userInput)
      {
      case 1:
        addOneHour();
        break;
      case 2:
        addOneMinute();
        break;
      case 3:
        addOneSecond();
        break;
      case 4:
        cout << "Exiting program.";
        return 0;
      default:
        cout << "Invalid entry." << endl;
        break;
      }

      displayClocks(getHours(), getMinutes(), getSeconds());
    }
    else
    {
      cout << "Invalid choice. Please enter a valid menu option." << endl;
    }

  } while (true);
  return 0;
}