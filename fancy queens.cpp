#include <iostream>
#include <cmath>
using namespace std;

bool test(int q[], int c) {
  for (int i = 0; i < c; i++)
    if (q[i] == q[c] || ((c - i) == abs(q[c] - q[i]))) return false;
  return true;
}

void print(int q[], int a) {
  typedef char box[5][7];
  box *board[8][8], wb, bb,
  bq = {
    {char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
    {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
    {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
    {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
    {char(219),char(219),char(219),char(219),char(219),char(219),char(219)}
  },
  wq = {
    {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },
    {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },
    {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
    {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
    {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      }
  };

  for (int i=0; i<5; i++) {
    for (int j=0; j<7; j++) {
      wb[i][j] = ' ';
      bb[i][j] = char(219);
    }
  }

  for (int i = 0; i < 8; i++) { // chess row
    for (int j = 0; j < 8; j++) { // chess column

      if ((i+j) % 2 == 0) {
        if (q[j] == i) board[i][j] = &bq;
        else board[i][j] = &bb;
      }
      else {
        if (q[j] == i) board[i][j] = &wq;
        else board[i][j] = &wb;
      }
    }
  }

  cout << "Solution #" << a << ": " << endl;
  cout << ' ';
  for (int i = 0; i < 56; i++) cout << "_";
  cout << ' ';
  cout << endl;

  for (int i = 0; i < 8; i++) { // chess row
    for (int k = 0; k < 5; k++) { // box row
      cout << '|';

      for (int j = 0; j < 8; j++) { // chess column
        for (int l = 0; l < 7; l++) cout << (*board[i][j])[k][l];
      }

      cout << '|' << endl;
    }
  }

  cout << ' ';
  for (int i = 0; i < 56; i++) cout << "-";
  cout << ' ';
  cout << endl << endl;

}

int main() {

  int q[8], a = 1, c = -1;

  while (true) { // column loop
    c++;


    if (c > 7) {
      print(q, a++);
      c--;
    }
    else q[c] = -1;

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
