#include <iostream>
#include <string>

using namespace std;

int main()
{

  string twoDigitString(unsigned int n)
  {
    string convertedOutput = to_string(n);
    
    if ((0 <= n) && (n<= 9))
      convertedOutput = '0' + convertedOutput;

    return convertedOutput;
  }

  void displayClocks(unsigned int h, unsigned int m, unsigned int s) 
    {
        cout << "***************************" << "   " << "***************************" << endl;
        cout << "*" << "      " << "12-HOUR CLOCK" << "      " << "*" << "   ";
        cout << "*" << "      " << "24-HOUR CLOCK" << "      " << "*" << "   " << endl;
        cout << endl;
        cout << "*" << "      " << formatTime12(h, m, s) << "       " << "*" << "   ";
        cout << "*" << "        " << formatTime24(h, m, s) << "         " << "*" << endl;
        cout << "***************************" << "   " << "***************************" << endl;
    }
}