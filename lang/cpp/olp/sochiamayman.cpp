#include "iostream"

using namespace std;

inline bool isLuckyNumber(int n) {
  int count = 0, lastDigit;
  while (n > 0) {
    lastDigit = n % 10;
    count += (lastDigit == 4 || lastDigit == 7) - 1;
    n /= 10;
  }
  return !count;
}

inline bool isLuckyDivisor(int n) {
  if (!((n % 4) && (n % 7))) return 1;
  for (int i = 1; n/i > 0; i++) {
    if (n % i) continue;
    if (isLuckyNumber(n/i)) return 1;
  }
  return 0;
}

int main() {
  int N; cin >> N;
  if (isLuckyDivisor(N)) {
    cout << "YES";
    return 0;
  }
  cout << "NO";
}
