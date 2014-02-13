#include <iostream> 
#include <vector>

using namespace std;

enum PART {
  SPACE = 0,
  HOR = 1,
  LEFT_VER = 2,
  RIGHT_VER = 3,
  BOTH_VER = 4
};

// hard code array 
int Number[10][5] = 
  {{1,4,0,4,1},
   {0,3,0,3,0},
   {1,3,1,2,1},
   {1,3,1,3,1},
   {0,4,1,3,0},
   {1,2,1,3,1},
   {1,2,1,4,1},
   {1,3,0,3,0},
   {1,4,1,4,1},
   {1,4,1,3,1}
};

int row = 0;
int column = 0;


void print_LCD(char** res) {
  //  cout << row << column;
  for (int i=0; i < row; ++i) {
    for (int j=0; j < column-1; ++j) {
      cout << res[i][j];
    }
    cout << endl;
  }
}


void make_digit(int d, int index, int s, char** res) {
  int i = 0; int line = 0;
  while (i < 5 && line < row) {
    if (Number[d][i] == HOR) {
      res[line][index] = ' ';
      for (int j=index+1; j < index+s+1; ++j) {
	res[line][j] = '-';
      }
      res[line][index+s+1] = ' ';
      ++line;
    }

    else if (Number[d][i] == SPACE) {
      res[line][index] = ' ';
      for (int j=index+1; j < index+s+1; ++j) {
	res[line][j] = ' ';
      }
      res[line][index+s+1] = ' ';
      ++line;
    }

    else if (Number[d][i] == LEFT_VER) {
      for (int k=line; k < line+s; ++k) {
	res[k][index] = '|';
	for (int j=index+1; j < index+s+1; ++j) {
	  res[k][j] = ' ';
	}
	res[k][index+s+1] = ' ';
      }
      line = line + s;
    }

    else if (Number[d][i] == RIGHT_VER) {
      for (int k=line; k < line+s; ++k) {
	res[k][index] = ' ';
	for (int j=index+1; j < index+s+1; ++j) {
	  res[k][j] = ' ';
	}
	res[k][index+s+1] = '|';
      }
      line = line + s;
    }

    else if (Number[d][i] == BOTH_VER) {
      for (int k=line; k < line+s; ++k) {
	res[k][index] = '|';
	for (int j=index+1; j < index+s+1; ++j) {
	  res[k][j] = ' ';
	}
	res[k][index+s+1] = '|';
      }
      line = line + s;
    }
    else { cout << "There is something seriously wrong here!" << endl; }
    ++i;
  }
}

// init res
void init(char** res) {
  for (int i=0; i < row; ++i) {
    for (int j=0; j < column; ++j) {
      res[i][j] = ' ';
    }
  }
}

// main function
int main() {
  // read from input
  int s, n;
  cin >> s >> n;
  char** res;
  while (s == n == 0) {
    // get digits
    int d = 0;
    int count = 0;
    int n_2 = n;
    vector<int> print_num;
    while (n_2 > 0) {
      d = n_2 % 10;
      n_2 = n_2 / 10;
      count++;
      print_num.push_back(d);
    } 
    // create an array to put the results into
    row = 2*s+3;
    column = (s+2+1)*(count);
    res = new char*[row];
    for (int i=0; i < row; ++i) {
      res[i] = new char[column];
    }
    // char res[row][column];
    //initialize res
    init(res);
    // fill up the res array
    n_2 = n;
    int index = 0;
    for (int i=print_num.size()-1; i >= 0; --i) {
      make_digit(print_num[i], index, s, res);
      index = index + s + 3;
    }
    // print the result
    print_LCD(res);
    cout << endl;
    cin >> s >> n;
  }
  // clearing the memory
  for (int i=0; i < row; ++i) {
    delete res[i];
  }   
  delete res;
  return 0;
}

