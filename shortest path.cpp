#include <iostream>
using namespace std;

const int rows = 5, cols = 6;

int up(int x) {
  return (x+rows-1)%rows;
}

int down(int x) {
  return (x+1)%rows;
}

int main() {
  int table[rows][cols] = {
    {3,4,1,2,8,6},
    {6,1,8,2,7,4},
    {5,9,3,9,9,5},
    {8,4,1,3,2,6},
    {3,7,2,8,6,4}
  };

  int least = 0, step = 0;

  for (int j = 1; j < cols; j++) {
    for (int i = 0; i < rows; i++) {
      least = min(table[up(i)][j-1], min(table[i][j-1], table[down(i)][j-1]));
      table[i][j] += least;
    }
  }

  least = table[0][cols - 1];
  for (int i = 1; i < rows; i++) {
    if (table[i][cols - 1] < least) {
      least = table[i][cols - 1];
      step = i;
    }
  }

  cout << "The length of the shortest path is " << least << "." << endl;

  string path = ".";
  path = (char)(step + '0') + path;

  for (int i = cols - 1; i > 0; i--) {
    least = min(table[up(step)][i-1], min(table[step][i-1], table[down(step)][i-1]));

    if (least == table[up(step)][i-1]) step = up(step);
    else if (least == table[down(step)][i-1]) step = down(step);

    path = (char)(step + '0') + path;
  }

  cout << "The rows of the path from left to right are " << path << endl;

}
