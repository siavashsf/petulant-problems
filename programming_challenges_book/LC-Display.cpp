#include <iostream>
#include <vector>

using namespace std;

// hard code array 
bool Number[10][7] = 
  {{1,1,1,0,1,1,1},
   {0,0,1,0,0,1,0},
   {1,0,1,1,1,0,1},
   {1,0,1,1,0,1,1},
   {0,1,1,1,0,1,0},
   {1,1,0,1,0,1,1},
   {1,1,0,1,1,1,1},
   {1,0,1,0,0,1,0},
   {1,1,1,1,1,1,1},
   {1,1,1,1,0,1,0}
};

bool horizontal[7] = {1,0,0,1,0,0,1};

void print_vector(vector<const bool*> n) {
  int tmp;
  for (int i=n.size()-1; i >= 0; --i) {
    cout << '[' ;
    for (int j=0; j < 7; ++j) {
      cout << n[i][j];
    }
    cout << ']';
  }
  cout << endl;
}

void print_horizontal(bool d, int s) {
  char c;
  if (d) {
    c = '-';
  } else {
    c = ' ';
  }
  cout << ' ';
  for (int i=0; i < s; i++) {
    cout << c;
  }
  cout << ' ';
}

void print_vertical(bool c) {
  char c;
  if (d) {
    c = '|';
  } else {
    c = ' ';
  }
  cout << c;
}


void print_char(char c, int s) {
  for (int i=0; i < s; ++i){
    cout << c ;
  }
}

// typedef bool BBBB[7];
// typedef vector<BBBB> BOOL_ARRAY;

void print_lines(int s, bool b) {
  char c;
  if (b) {
    c = '-';
  } else {
    c = '|';
  }
  print_char(c, s);
}

// function to print out the number given the array
void print_LCD(vector<const bool*> n, int s) {
  print_vector(n);
  // index for LCD number representation
  int j = 0;
  const char b = ' ';
  while (j < 7) {
    for (int i = n.size()-1; i >= 0; --i) {
      if (horizontal[j]) {
	// print empty
	  print_char(b, s);
	if (n[i][j] == 0) {
	  // print empty
	  print_char(b, s);
	} else {
	  // print a horizontal line
	  print_lines(s, true);
	}
	// print empty
	print_char(b, s);
      } else {
	// // print empty
	// print_char(b, s);
	if (n[i][j] == 0) {
	  // print empty
	  print_char(b, s);
	} else {
	  // print vertical
	  print_lines(s, false);
	}
	// print_char(b, s);
      }
      // for 2 and 5
      if (j == 1 || j == 4) {
	++j;
	// print empty
	print_char(b, s);
	if (n[i][j] == 0) {
	  // print empty
	  print_char(b, s);
	} else {
	  // print vertical
	  print_lines(s, false);
	}
	// print_char(b, s);
      }
      if (i != n.size()) { --j; }
    }
    cout << endl;
    ++j;
  } // end of while
}

// main function
int main() {
  // read from input
  int s, n;
  cin >> s >> n;
  while (s == n == 0) {
    // get digits
    int d = 0;
    int count = 0;
    int n_2 = n;
    vector<const bool*> print_num;
    while (n_2 > 0) {
      d = n_2 % 10;
      n_2 = n_2 / 10;
      count++;
      const bool* b = Number[d];
      print_num.push_back(b);
    }    
    print_LCD(print_num, s);
    cin >> s >> n;
  }
  return 0;
}
