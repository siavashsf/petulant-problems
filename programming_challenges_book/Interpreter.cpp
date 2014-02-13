#include <iostream>

#define DEBUG(x) // x change to get the debug info

using namespace std;


void init(int* RAM, int* reg) {
  for (int i=0; i < 1000; ++i) {
    RAM = 0;
  }
  for (int i=0; i < 10; ++i) {
    reg = 0;
  }
}

int round_up(int n) {
  return n % 1000;
}

void break_number(int n, int* res) {
  int tmp = round_up(n);
  if (tmp < 100) {
    res[0] = 0;
    res[2] = tmp % 10;
    tmp = tmp / 10;
    res[1] = tmp % 10;
  } else if (99 < tmp && tmp < 1000) {
    res[2] = tmp % 10;
    tmp = tmp / 10;
    res[1] = tmp % 10;
    tmp = tmp / 10;
    res[0] = tmp % 10;
  } else { cout << "There is something seriously wrong here!" << endl; }
}


int main() {
  // allocate RAM
  int RAM[1000];
  // init the registers
  int reg[10];
  init(RAM,reg);
  // read the first single number 
  int round = 0;
  cin >> round;

  // for the number init RAM, 
  for (int i=0; i < round; ++i) {
    // read input file - fill the RAM
    int com = 100;
    int count = 0;
    do {
      cin >> com;
      if ((200 <= com && com <= 999) || (0 < com && com <= 99) || (com == 100)) {
	RAM[count] = com;
	++count;
      } else { break; } 
    } while (com != 100);

    int res = 1;
    for (int j=0;j <= count; ++j) {
      com = RAM[j];
      int command[3];
      if (!((200 <= com && com <= 999) || (0 < com && com <= 100))) {
	DEBUG(cout << "the number is invalid " << com << endl);
	break;
      } else if (com == 100) {
	DEBUG(cout << "halt " << com << endl);
	++res;
	break;
      } else if (0 < com && com <= 99) {
	DEBUG(cout << "goto " << com << endl);
	break_number(com, command);
	if (reg[command[2]] != 0){
	  j = reg[command[1]] - 1;
	  ++res;
	}
      } else if (200 <= com && com <= 299) {
	DEBUG(cout << "assign " << com << endl);
	break_number(com, command);
	reg[command[1]] = command[2];
	++res;
      } else if (300 <= com && com <= 399) {
	DEBUG(cout << "add " << com << endl);
	break_number(com, command);
	int tmp = reg[command[1]] + command[2];
	reg[command[1]] = round_up(tmp);
	++res;
      } else if (400 <= com && com <= 499) {
	DEBUG(cout << "mult " << com << endl);
	break_number(com, command);
	int tmp = reg[command[1]] * command[2];
	reg[command[1]] = round_up(tmp);
	++res;
      } else if (500 <= com && com <= 599) { 
	DEBUG(cout << "substitute " << com << endl);
	break_number(com, command);
	reg[command[1]] = reg[command[2]];
	++res;
      } else if (600 <= com && com <= 699) { 
	break_number(com, command);
	DEBUG(cout << "add reg " << com << endl);
	int tmp = reg[command[1]] + reg[command[2]];
	reg[command[1]] = round_up(tmp);
	++res;
      } else if (700 <= com && com <= 799) { 
	DEBUG(cout << "mult reg " << com << endl);
	break_number(com, command);
	int tmp = reg[command[1]] * reg[command[2]];
	reg[command[1]] = round_up(tmp);
	++res;
      } else if (800 <= com && com <= 899) { 
	DEBUG(cout << "assign RAM " << com << endl);
	break_number(com, command);
	reg[command[1]] = RAM[reg[command[2]]];
	++res;
      } else if (900 <= com && com <= 999) { 
	DEBUG(cout << "assign reg " << com << endl);
	break_number(com, command);
	RAM[reg[command[2]]] = reg[command[1]];
	++res;
      } 
    }
    cout << res << endl;
  } // end of for
  return 0;
}
