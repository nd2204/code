#include <iostream>
#include <limits.h>
#include <memory.h>
#include <cstring>

using namespace std;

#define MAX_NODE_COUNT 50
/* #define INT_MAX 1000000; */
#define CMAP(c) (char)((c) + 'A')

int n, s, t;

int found[MAX_NODE_COUNT];
int dist[MAX_NODE_COUNT];
int mat[MAX_NODE_COUNT][MAX_NODE_COUNT];
bool visited[MAX_NODE_COUNT];

void nhap() {
  FILE* f = freopen("dijkstra_input.txt", "r", stdin);
  cin >> n;
  cout << "So dinh: " << n << endl;
  cin >> s >> t;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
      if (mat[i][j] == 0) mat[i][j] = INT_MAX;
    }
  }
  fclose(f);
}

void xuat() {
  cout << "Do thi vua nhap la:\n";
  cout << "- So dinh cua do thi: " << n << endl;
  cout << "- Ma tran trong so cua do thi:\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << mat[i][j] << "\t";
    }
    cout << "\n";
  }
}

void show_path() {
  const int end = t;
  cout << "Duong di ngan nhat tu " << CMAP(s) << " den " << CMAP(t) << " la\n";
  cout << CMAP(end) << "<=";

  int i = found[end];

  while (i != s) {
    cout << CMAP(i) << "<=";
    i = found[i];
  }

  cout << CMAP(s) << "\n";
  cout << "Do dai duong di la: " << dist[end];
}

bool isAllVisited() {
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) return false;
  }
  return true;
}

void dijkstra() {
  int u, minp;
  for (int v = 0; v < n; v++) {
    dist[v] = mat[s][v];
    found[v] = s;
    visited[v] = false;
  }
  dist[s] = 0;
  found[s] = -1;
  visited[s] = true;

  while (!isAllVisited()) {
    minp = INT_MAX;
    // Find cheapest next node
    for (int v = 0; v < n; v++) {
      if ((!visited[v]) && (dist[v] < minp)) {
        u = v;
        minp = dist[v];
      }
    }
    visited[u] = true;

    for (int v = 0; v < n; v++) {
      if ((!visited[v]) && (dist[u] + mat[u][v] < dist[v])) {
        dist[v] = dist[u] + mat[u][v];
        found[v] = u;
      }
    }
  }
}

int main() {
  nhap();
  xuat();
  dijkstra();
  show_path();
}
