#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N; cin >> N;

  int last, cur;
  cin >> last;
  long long move = 0;
  for (int i = 1; i < N; ++i) {
    cin >> cur;
    if (last > cur) {
      move += last - cur;
      continue;
    }
    last = cur;
  }
  cout << move;

  return 0;
}
