#ifdef FUNCTION_H // guards
#define FUNCTION_H

#include <string>

std::string nCharString(size_t n, char c);

std::string formatTime24(unsigned int h, unsigned int m, unsigned int s);

std::string formatTime12(unsigned int h, unsigned int m, unsigned int s);

std::string twoDigitString(unsigned int n);

void addOneHour();

void addOneMinute();

void addOneSecond();

void mainMenu();

void printMenu();

void displayClocks(unsigned int h, unsigned int m, unsigned int s);

unsigned int getMenuChoice(unsigned int maxChoice);

#endif