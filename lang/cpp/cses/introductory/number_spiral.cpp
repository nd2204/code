#include <iostream>
inline int imax(int a, int b) { return (a > b) ? a : b; }
inline int iabs(int a) { return (a < 0) ? -a : a; }
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  int r[N], c[N], sign;
  long long md;
  for (int i = 0; i < N; ++i) {
    cin >> r[i] >> c[i];
  }
  for (int i = 0; i < N; ++i) {
    md = imax(r[i], c[i]);
    if (r[i] < c[i])
      sign = (md & 1) ? 1 : -1;
    else 
      sign = (md & 1) ? -1 : 1;
    md = 1 + md * (md - 1) + sign * (iabs(r[i] - c[i]));
    cout << md << '\n';
  }
}
