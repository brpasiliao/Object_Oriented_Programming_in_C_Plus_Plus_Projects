#include <iostream>
using namespace std;


int main() {
  while (true) {
    string outcome;
    cout << "Enter the race outcome: ";
    cin >> outcome;
    if (outcome == "done") return 0;

    double teamData[26][3] = {}; // 0 = team runners, 1 = runner score, 2 = team score
    bool capital = true;

    for (int i = 0; (i < outcome.length()) && capital; i++) {
      if ((outcome.at(i) < 'A') || (outcome.at(i) > 'Z')) capital = false;
      int letter = outcome.at(i) - 'A';
      teamData[letter][0]++;
      teamData[letter][1] += i+1;
    }

    if (capital) {

      int teams = 0, runners = 0;
      bool same = true;

      for (int i = 0; (i < 26) && same; i++) {
        if (teamData[i][0] != 0) {
          teams++;
          if ((runners != teamData[i][0]) && (teams > 1)) same = false;
          runners = teamData[i][0];
        }
      }

      if (!same) cout << "The teams don't have the same number of runners.\n";

      else {

        cout << "There are " << teams << " teams.\n";
        cout << "Each team has " << runners << " runners.\n";

        int winner = 0, counter = 0;

        for (int i = 0; i < 26; i++) {
          if (teamData[i][0] != 0) {
            counter ++;
            teamData[i][2] = teamData[i][1] / runners;
            cout << (char)(i + 'A') << ": " << teamData[i][2] << endl;
            if (((teamData[i][2] < teamData[winner][2]) && (counter > 1)) || (counter == 1))
              winner = i;
          }
        }

        cout << "The winning team is team " << (char)(winner + 'A') << " with a score of " << teamData[winner][2] << ".\n";

      }
    }
  }
}
