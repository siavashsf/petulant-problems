#include <iostream> 

using namespace std;

int main() {
  int a, b;
  while (cin >> a >> b) {
    cout << "a is: " << a << endl;
    cout << "b is: " << b << endl;
    int countn = 0;
    int countmax = 0;
    if (a > b) { int tmp = b; b = a; a = tmp; }
    for (int i=a; i <= b; ++i) {
      int n = i;
      while (n != 1) {
	countn++;
	if (n%2 == 0) {
	  i = i/2;
	} else {
	  n = (3 * n) + 1;
	}
      }
      if ( countmax < countn) {
	countmax = countn;
      }
     
    }
    cout << a << " " << b << " " << countmax+1 << endl;
  }
  return 0;
}
