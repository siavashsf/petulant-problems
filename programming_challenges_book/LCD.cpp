/* @JUDGE_ID: 110102 10189 C++ "Minesweeper" */


/* @BEGIN_OF_SOURCE_CODE */
#include <iostream>

using namespace std;

void LCDisplay(int d, int s) {
  // print the number in LCD mode
  
  // print an extra blank column
}

int main() {
  // reading the input
  int s, n = 0;
  cin >> s >> n;
  while (!s == n == 0) {
    //devide the numbers
    while (n > 0) {
      int d = n % 10;
      n = n / 10;
      // call a funciton display to print each number
      LCDisplay(d, s);
    }
  }
  return 0;

}


/* @END_OF_SOURCE_CODE */
