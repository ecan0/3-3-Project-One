#ifdef FUNCTIONS_H // guards
#define FUNCTIONS_H

#include <string>

using namespace std;

std::string nCharString(size_t n, char c);

std::string formatTime24(int h, int m, int s);

std::string formatTime12() int h, int m, int s);

std::string twoDigitString(int n);

void addOneHour();

void addOneMinute();

void addOneSecond();

void mainMenu();

void printMenu();

void displayClocks(int h, int m, int s);

int getMenuChoice(int maxChoice);

int getUserTime();

#endif