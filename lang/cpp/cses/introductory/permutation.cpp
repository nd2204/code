#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N; cin >> N;
  if (N == 3 || N <= 0 || N == 2) {
    cout << "NO SOLUTION";
  } else {
    for (int i = 2; i <= N; i += 2) cout << i << " ";
    for (int i = 1; i <= N; i += 2) cout << i << " ";
  }
}
