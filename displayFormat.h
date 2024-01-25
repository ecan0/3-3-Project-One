#ifndef DISPLAYFUNCTIONS_H
#define DISPLAYFUNCTIONS_H

#include <string>

std::string nCharString(size_t n, char c);

std::string formatTime24(unsigned int h, unsigned int m, unsigned int s);

std::string formatTime12(unsigned int h, unsigned int m, unsigned int s);

std::string twoDigitString(unsigned int n);

#endif