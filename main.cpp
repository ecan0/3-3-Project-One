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

    // Corrected usage of getMenuChoice
    userInput = getMenuChoice(4); // Assuming there are four choices

    switch (userInput)
    {
    case 1:
      addOneHour();
      displayClocks(getHours(), getMinutes(), getSeconds());
      break;
    case 2:
      addOneMinute();
      displayClocks(getHours(), getMinutes(), getSeconds());
      break;
    case 3:
      addOneSecond();
      displayClocks(getHours(), getMinutes(), getSeconds());
      break;
    case 4:
      cout << "Exiting program.";
      return 0;
    default:
      cout << "Invalid entry." << endl;
      break;
    }

    

  } while (true);
}