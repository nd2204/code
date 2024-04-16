#include <bits/stdc++.h>

using namespace std;

inline int lkbase_convert(int x) {
  static const int lkbase[2] = {4, 7};
  static int i = 0;
  return lkbase[x%2] * pow(10, i++) + lkbase_convert(x/2);
}

inline int next(int x) {
  cout << x << ":";
  int result = 4, lastDigit, digit;
  int i = 0;
  while (x < result) {
    if (result % 10 == 7) {
      result = result * 10 + 4;
    }
    result += 3;
    cout << result << endl;
  }
  return result;
}

int main() {
  cout << lkbase_convert(2);
  /* int l, r; cin >> l >> r; */
  /* int lksum = 0; */
  /* for (; l <= r; l++) { */
  /*   lksum += next(l); */
  /* } */
  /* cout << lksum; */
}
