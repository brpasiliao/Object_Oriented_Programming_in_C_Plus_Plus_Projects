#include <iostream>
using namespace std;

int main() {
  int b[8][8] = {0}, a = 1, c = -1;

  nextColumn:
    c++;
    int r = -1;
    if (c > 7) goto print;

  nextRow:
    r++;
    if (r > 7) goto backtrack;

    for (int i = 0; i < c; i++) {   //horizontal test
      if (b[r][i] == 1) goto nextRow;
    }
    for (int x = 0; (r-x > -1) && (c-x > -1); x++) {   //up diagonal test
      if (b[r-x][c-x] == 1) goto nextRow;
    }
    for (int x = 0; (r+x < 8) && (c-x > -1); x++) {   //down diagonal test
      if (b[r+x][c-x] == 1) goto nextRow;
    }

    b[r][c] = 1;
    goto nextColumn;

  backtrack:
    c--;
    if (c < 0) return 0;
    r = 0;
    while (b[r][c] == 0)
      r++;
    b[r][c] = 0;
    goto nextRow;

  print:
    cout << "Solution #" << a << ": \n";
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        cout << b[i][j];
      }
      cout << endl;
    }
    cout << endl;
    a++;
    goto backtrack;

}
