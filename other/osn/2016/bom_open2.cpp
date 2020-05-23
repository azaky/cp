#include <iostream>

using namespace std;

int subtask1_l = 6;
int subtask1[6] = {5, 5, 5, 5, 5, 5};
int subtask2_l = 16;
int subtask2[16] = {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
string s, balasan;
int n, t, r;

int main() {
  getline(cin, s);
  cin >> n >> t >> r;

  if (s[1] == '1') {
    for (int i=0; i<subtask1_l; i++) {
      cout << subtask1[i] << endl << flush;
      cin >> balasan;
    }
  }

  if (s[2] == '2') {
    for (int i=0; i<subtask2_l; i++) {
      cout << subtask2[i] << endl << flush;
      cin >> balasan;
    }
  }
}