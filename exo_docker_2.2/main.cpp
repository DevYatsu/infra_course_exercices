#include <iostream>
using namespace std;

typedef unsigned long long big_number;

big_number fib(short n) {
  if (n <= 1)
    return 1;

  big_number a, b;
  a = b = 1;
  big_number c = 0;
  for (big_number i = 2; i < n; i++) {
    c = a + b;
    a = b;
    b = c;
  }
  return c;
}

int main() {
  for (short i = 0; i < 2000; i++)
    cout << fib(i) << endl;
  return 0;
}
