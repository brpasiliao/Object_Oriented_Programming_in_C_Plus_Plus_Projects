#include <iostream>
#include <cmath>
using namespace std;

bool test(int c[], int n[][4], int b) {
  for (int i = 0; i < b; i++)
    if (c[b] == c[i]) return false;

  for (int i = 0; n[b][i] != -1; i++)
    if (abs(c[n[b][i]] - c[b])  == 1)
      return false;

  return true;
}

void print(int c[], int a) {
  cout << "Solution #" << a << endl;
  cout << " " << c[1]+1 << c[2]+1 << endl;
  cout << c[0]+1 << c[3]+1 << c[4]+1 << c[7]+1 << endl;
  cout << " " << c[5]+1 << c[6]+1 << endl;
  cout << endl;
}

int main() {
  int c[8] = {0}, b = 0, a = 1; // c = cross, b = box, a = solution #
  int n[8][4] = { // helper array of neighbors
    {-1},
    {0,-1},
    {1,-1},
    {0,1,2,-1},
    {1,2,3,-1},
    {0,3,4,-1},
    {3,4,5,-1},
    {2,4,6,-1},
  };

  while (true) {
    b++;
    c[b] = -1;

    if (b > 7) {
      print(c, a++);
      b--;
    }

    while (true) {
      c[b]++;

      if (c[b] > 7) {
        b--;
        if (b < 0) return 0;
      }
      else if (test(c, n, b)) break;
    }
  }
}
