#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    int arr[N];

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int best = 0, left = 0, right = 0;
    unordered_set<int> s;
    for (; right < N; ++right) {
        s.insert(arr[right]);
        while (s.size() > (unsigned int) M) {
            s.erase(arr[left]);
            left++;
        }
        best = max(best, right - left + 1);
    }

    cout << best;
}
