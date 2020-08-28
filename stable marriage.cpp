#include <iostream>
using namespace std;

bool test(int c[], int p) {
  int mp[3][3] = {
  // 0,1,2 woman
    {0,2,1}, 	  // Man#0's preferences
    {0,2,1},		// Man#1's preferences
    {1,2,0}   	// Man#2's preferences
  };
	int wp[3][3] = {
  // 0,1,2 man
    {2,1,0},		// Woman#0's preferences
    {0,1,2},		// Woman#1's preferences
    {2,0,1}     // Woman#2's preferences
  };

  for (int i = 0; i < p; i++) {
    if (c[i] == c[p]) return false;
    if (mp[p][c[i]] < mp[p][c[p]] && wp[c[i]][p] < wp[c[i]][i]) return false;
    // if test man prefers i woman better and i woman prefers test man better
    if (wp[c[p]][i] < mp[c[p]][p] && mp[i][c[p]] < mp[i][c[i]]) return false;
    // if test woman prefers i man better and i man prefers test woman better
  }
  return true;
}

void print(int m[], int c) {
  cout << "Solution #" << c << ":" << endl;
  cout << "Man\tWoman" << endl;
  for (int i = 0; i < 3; i++)
    cout << i << "\t" << m[i] << endl;

  cout << endl;
}

int main() {
  int c[3] = {}, p = 0, a = 1; // c = couples, p = person, a = counter

  while (true) {
    p++;
    c[p] = -1;

    if (p > 2) {
      print(c, a++);
      p--;
    }

    while (true) {
      c[p]++;

      if (c[p] > 2) {
        p--;
        if (p < 0) return 0;
      }
      else if (test(c, p)) break;
    }
  }
}
