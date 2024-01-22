#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{

  void printMenu(char *strings[], unsigned int numStrings, unsigned char width)
  {
    cout << setfill('*') << setw((int)width) << endl;
    for (int i = 0; i < strings.size(); ++i)
    {
      cout << "* ";
      cout << i << '-' << " ";
      cout << string[i];
    }
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
    string formattedString = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + timeSuffix;
    return formattedString; // replace this placeholder with return of your formatted string
  }

  string twoDigitString(unsigned int n)
  {
    string convertedOutput = to_string(n);

    if ((0 <= n) && (n <= 9))
      convertedOutput = '0' + convertedOutput;

    return convertedOutput;
  }

  // void displayClocks(unsigned int h, unsigned int m, unsigned int s)
  //   {
  //       cout << "***************************" << "   " << "***************************" << endl;
  //       cout << "*" << "      " << "12-HOUR CLOCK" << "      " << "*" << "   ";
  //       cout << "*" << "      " << "24-HOUR CLOCK" << "      " << "*" << "   " << endl;
  //       cout << endl;
  //       cout << "*" << "      " << formatTime12(h, m, s) << "       " << "*" << "   ";
  //       cout << "*" << "        " << formatTime24(h, m, s) << "         " << "*" << endl;
  //       cout << "***************************" << "   " << "***************************" << endl;
  //   }
}