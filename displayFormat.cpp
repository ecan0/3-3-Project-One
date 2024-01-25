#include "displayFormat.h"

using namespace std;

string nCharString(size_t n, char c)
  {
    return string(static_cast<int>(n), c);
  }

  string formatTime24(unsigned int h, unsigned int m, unsigned int s)
  {
    return formattedTime = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
  }

  string formatTime12(unsigned int h, unsigned int m, unsigned int s)
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

  string twoDigitString(unsigned int n)
  {
    string convertedOutput = to_string(n);

    if ((0 <= n) && (n <= 9))
      convertedOutput = '0' + convertedOutput;

    return convertedOutput;
  }
