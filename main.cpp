#include <iostream>
#include <iomanip>
#include <string>
#include "functions.h"

using namespace std;

//Our definitions from functions.h
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
  //First, prompt the user for the initial time
  getUserTime();
  cout << "Congratulations! You have entered a valid time. Above are your times in 12 and 24 hours." << endl;
  //Then we will get the next input that will be user choices 1-4. 

  int userInput;

  //Loop this until we receive an exit entry of 4!
  do
  {
    cout << endl << "Please update the time according to the choices below." << endl;
    //This will resemble the menu selections that allow us to add 1 hour,minute,or second at a time.
    printMenu();

    userInput = getMenuChoice(4); // Assuming there are four choices

    //Determine for each user input 1-4 whether to add an hour/min/sec and then display the time.
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
    //Anything not 1-4 will print invalid.
    default:
      cout << "Invalid entry." << endl;
      break;
    }
  } while (true);
}