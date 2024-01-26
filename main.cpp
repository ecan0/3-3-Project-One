#include <iostream>
#include <iomanip>
#include <string>
#include "functions.h"

using namespace std;

void getUserTime();
void printMenu();
void mainMenu();

int main() 
{
  getUserTime();
  mainMenu();
  printMenu();
  return 0;
}