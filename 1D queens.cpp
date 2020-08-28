#include <iostream>
#include <cmath>
using namespace std;

bool test(int q[], int c) {
  for (int i = 0; i < c; i++)
    if (q[i] == q[c] || ((c - i) == abs(q[c] - q[i]))) return false;
  return true;
}

void print(int q[], int &a) {
  cout << "Solution #" << a++ << ": ";
  for (int i = 0; i < 8; i++) cout << q[i];
  cout << endl;
}

int main() {
  int q[8], a = 1, c = -1;

  while (true) { // column loop
    c++;
    q[c] = -1;

    if (c > 7) {
      print(q, a);
      c--;
    }

    while (true) { // row loop
      q[c]++;

      if (q[c] > 7) {
        c--;
        if (c < 0) return 0;
      }
      else if (test(q, c)) break;
    }
  }
}
