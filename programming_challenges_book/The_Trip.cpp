/* @JUDGE_ID: 110102 10189 C++ "Minesweeper" */


/* @BEGIN_OF_SOURCE_CODE */
#include <iostream> 
#include <stdio.h>

using namespace std;

int main() {
  int lines = 0;
  // read the first line
  cin >> lines;
  while (lines > 0) {
    int A[lines];
    double tmp = 0.0;
    int sum = 0;
    // read each input
    for (int i=0;i < lines; ++i) {
      cin >> tmp;
      A[i] = (int)(tmp*100);
      sum += A[i];
    }

    double double_avg = sum / (double)lines;
    // cout << "double_avg= " << double_avg << sum << endl;
    int avg = 0;
    
    // round up the avg
    int tmp2 = (int)(double_avg*10) % 10;
    // cout << "avg*1000 is " << (int)(avg*1000.00) << endl; 
    // cout << "tmp2 is " << tmp2 << endl;
    if (tmp2 >= 5) {
      avg = (int)(double_avg) + 1;
    } else {
      avg = (int)double_avg;
    }
    
    // cout << avg << endl;
    // go through the spent list and sum the min exchange
    int exchange = 0;
    for (int i=0;i < lines; ++i) {
      if (A[i] > avg) {
	exchange += (A[i] - avg);
      }
    }
    double tmp3 = exchange/100.00;
    printf("$%.2f\n", tmp3);
    // cout << "$" << exchange << endl;
    // read a new line for a new input
    cin >> lines;
  }
  return 0;
}

/* @END_OF_SOURCE_CODE */
