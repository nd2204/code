#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int tc, N, C;
    cin >> tc;
    cin >> N >> C;

    int x[N];
    for (int i = 0; i < tc; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> x[j];
        }
        sort(x, x + N);
    }
    return 0;
}
