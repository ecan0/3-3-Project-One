#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
  void mainMenu()
  {
    int userInput;
    while (getMenuChoice(userInput))
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
        return;
      default:
        continue;
      }
    }
  }

  void printMenu(char *strings[], unsigned int numStrings, int width)
  {

    cout << nCharString(width, '*') << endl;
    for (int i = 0; i < numStrings; ++i)
    {
      string givenString = strings[i];
      cout << "* ";
      cout << i + 1 << " - ";
      cout << givenString;
      int spaceLength = width - givenString.length() - 7;
      cout << nCharString(spaceLength, ' ') << "*" << endl;
      if (givenString != strings[numStrings - 1])
      {
        cout << endl;
      }
    }
    cout << nCharString(width, '*') << endl;
  }
  /**
   * Gets menu choice 1 through maxChoice, inclusive
   *
   * @param maxChoice, maximum choice index, a number between 2 and 9, inclusive
   * @return the first legal choice input, could be 1 through maxChoice, inclusive
   */
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

  /**
   * Adds one hour
   */
  void addOneHour()
  {
    int currentHour = getHour();

    if ((0 <= currentHour) && (currentHour <= 22))
    {
      setHour(currentHour + 1);
    }
    else
    {
      setHour(0);
    }
  }

  /**
   * Adds one minute
   */
  void addOneMinute()
  {
    int currentMinute = getMinute();

    if ((0 <= currentMinute) && (currentMinute <= 58))
    {
      setMinute(currentMinute + 1);
    }
    else
    {
      setMinute(0);
      addOneHour();
    }
  }

  /**
   * Adds one second
   */
  void addOneSecond()
  {

    int currentSecond = getSecond();

    if ((0 <= currentSecond) && (currentSecond <= 58))
    {
      setSecond(currentSecond + 1);
    }
    else
    {
      setSecond(0);
      addOneMinute();
    }
  }

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
    return formattedTime; // replace this placeholder with return of your formatted string
  }

  string twoDigitString(unsigned int n)
  {
    string convertedOutput = to_string(n);

    if ((0 <= n) && (n <= 9))
      convertedOutput = '0' + convertedOutput;

    return convertedOutput;
  }

void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
    cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl;
    cout << "*" << "      " << "12-HOUR CLOCK" << "      " << "*" << endl;
    cout << "*" << "      " << "24-HOUR CLOCK" << "      " << "*" << endl;
    cout << endl;
    cout << "*" << "      " << formatTime12(h,m,s) << "      " << "*" << endl;
    cout << "*" << "      " << formatTime24(h,m,s) << "      " << "*" << endl;
    cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl;
}
}