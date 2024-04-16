#include <bits/stdc++.h>

using namespace std;

int main() {
  unordered_set<char> vowel = { 'a', 'e', 'u', 'i', 'o', 'y' };
  string s, buffer = ""; cin >> s;
  for (char c: s) {
    if (c >= 'A' && c <= 'Z') c += 32;
    if (!vowel.count(c)) buffer = (buffer + '.') + c ;
  }
  cout << buffer;
}
