#include <iostream>
#include <cmath>
using namespace std;

bool test(int q[], int c, int n) {
  for (int i = 0; i < c; i++)
    if (((q[c]/n) - (q[i]/n)) == abs((q[c]%n) - (q[i]%n)))
      return false;
  return true;
}

int bishops(int n, int k) {
  int *q = new int[k](), configs = 0, c = 0;

  while (true) {
    c++;

    if (c >= k) {
      configs++;
      c--;
    }
    else q[c] = q[c-1];

    while (true) {
      q[c]++;

      if (q[c] > ((n*n)-1)) {
        c--;
        if (c < 0) {
          delete[]q;
          return configs;
        }
      }
      else if (test(q, c, n)) break;
    }
  }
}

int main() {
  int n, k;

  while (true) {
    cout << "Board size: ";
    cin >> n;
    if (n == -1) return 0;

    cout << "Number of bishops: ";
    cin >> k;

    if (k > n)
      cout << "Bishops has to be less than or equal to board size."
      << endl;
    else
      cout << "n:" << n << endl << "k:" << k << endl
      << "configs:" << bishops(n, k) << endl << endl;

  }
}
