/* @JUDGE_ID: 110102 10189 C++ "Minesweeper" */


/* @BEGIN_OF_SOURCE_CODE */
#include <iostream> 

using namespace std;

int main() {
  // read input m for row and n for column
  int m, n = 1;
  int field = 1;
  // stopping condition
  cin >> m >> n;
  while (m != 0 && n != 0) { 
    // red the m X n array line by line
    char A[m][n];
    for (int i=0; i < m; ++i) {
      for (int j=0; j < n; ++j) {
	cin >> A[i][j];
      }
    }
    // print the field number
    cout << "Field #" << field << ":" << endl;
    // go though the array one by one
    for (int i=0; i < m; ++i) {
      for (int j=0; j < n; ++j) {
	// compute the number of * adjusent to each element of the array (brute-force)
	int count = 0;
	if (A[i][j] == '*') { cout << "*"; }
	else {
	  // check elements above
	  int row = i-1;
	  if (row >= 0) {
	    for (int k=-1; k <= 1; ++k) {
	      if (j+k >= 0 && j+k < n) {
		if (A[row][j+k] == '*') {
		  count++;
		}
	      }
	    }
	  }
	  // check elements below
	  row = i+1;
	  if (row < m) {
	    for (int k=-1; k <= 1; ++k) {
	      if (j+k >= 0 && j+k < n) {
		if (A[row][j+k] == '*') {
		  count++;
		}
	      }
	    }
	  }

	  // check elements on sides
	  // check the left element
	  if (j > 0) { 
	    if (A[i][j-1] == '*') {
	      count++;
	    }
	  }
	  // check the right element
	  if (j+1 < n) {
	    if (A[i][j+1] == '*') {
	      count++;
	    }
	  }
	  // print the result
	  cout << count ;
	}
      }
      cout << endl;
    }
    cout << endl;
    field++;
    cin >> m >> n;
  }
  return 0;
}

/* @END_OF_SOURCE_CODE */
