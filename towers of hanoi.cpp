#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cout << "Please enter the number of rings to move: ";
  cin >> n;

  vector<int> tower[3];
  for (int i = n+1; i > 0; i--) tower[0].push_back(i);
  tower[1].push_back(n+1);
  tower[2].push_back(n+1);

  int from = 0; // tower with the ring to move
  int moves = 0;
  int first, second;

  if ((n % 2) != 0) { // odd
    first = 1; second = 2;
  }
  else { // even
    first = 2; second = 1;
  }

  while (tower[1].size() != (n+1)) {
    int to;
    int after = (from + first) % 3; // tower after from
    int before = (from + second) % 3; // tower before from

    if (tower[after].back() > tower[from].back()) to = after;
    else to = before;

    tower[to].push_back(tower[from].back());
    tower[from].pop_back();

    cout << "Move #" << ++moves << ": Transfer ring "
    << tower[to].back() << " from tower " << (char)(from + 'A')
    << " to tower " << (char)(to + 'A') << endl;

    if (tower[(to + first) % 3].back() < tower[(to + second) % 3].back())
      from = (to + first) % 3;
    else from = (to + second) % 3;

  }
}
