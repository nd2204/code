#include <iostream>

using namespace std;

inline int max(int a, int b) { return (a > b) ? a : b; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  s.reserve(1000000);
  cin >> s;

  int best = 0;
  int count = 0;
  char c = s[0];
  const int len = s.size();

  for (int i = 0; i < len; ++i) {
    count++;
    if (s[i] != c) {
      c = s[i];
      count = 1;
    }
    best = max(best, count);
  }

  cout << best;

  return 0;
}
