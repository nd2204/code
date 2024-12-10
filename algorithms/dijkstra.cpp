#include <iostream>
#include <cstring>
#include <memory.h>

#define MAX 1000000
#define MAX_NODE 50
#define CMAP(x) (char)((x) + 'A')

// Vertex count
int n;

// Node Tags
int pre[MAX_NODE];
int dst[MAX_NODE];

// Path Data
int mat[MAX_NODE][MAX_NODE];

// Keep track of visited node
bool visited[MAX_NODE];

using namespace std;

void nhap() {
  FILE* f = freopen("dijkstra_input.txt", "r", stdin);
  if (!f) {
    exit(-1);
  }
  cin >> n;
  printf("So dinh: %d\n", n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
      if (mat[i][j] == 0) mat[i][j] = MAX;
    }
  }
  fclose(f);
}

void xuat() {
  printf("Thong tin do thi vua nhap:\n");
  printf("- So dinh: %d\n", n);
  printf("- Ma tran trong so cua do thi:\n");

  for (int i = 0; i < n; i++) {
    printf("  ");
    for (int j = 0; j < n; j++) {
      printf("%7d ", mat[i][j]);
    }
    printf("\n");
  }
}

bool isAllVisited() {
  for (int i = 0; i < n; i++) {
    if (!visited[i]) return false;
  }
  return true;
}

// Print path from end to start
void show_path(int src, int tar) {
  printf("Duong di ngan nhat tu %c den %c la:\n", CMAP(src), CMAP(tar));
  int p = pre[tar];
  printf("%c <-%d- ", CMAP(tar), mat[tar][p]);

  while (p != src) {
    printf("%c <-%d- ", CMAP(p), mat[p][pre[p]]);
    p = pre[p];
  }

  printf("%c\n", CMAP(src));
  printf("Do dai duong di la: %d\n", dst[tar]);
}

void dijkstra(int src, int tar) {
  // Init Graph Tags
  // 1. init the distance of the src to other vert
  for (int v = 0; v < n; v++) {
    dst[v] = mat[src][v]; // or mat[v][src] but current is more cache friendly
    pre[v] = src;
    visited[v] = false;
  }
  // 2. init src vert tags
  dst[src] = 0;
  pre[src] = -1;
  visited[src] = true;

  // 3. main loop for visiting every node and update their tags
  int minp, u;
  while (!isAllVisited()) {
    if (visited[tar]) break;
    minp = MAX;
    // 3.1 find cheapest next node as u
    for ( int v = 0; v < n; ++v ) {
      if ( (!visited[v]) && (dst[v] < minp) ) {
        u = v;
        minp = dst[v];
      }
    }
    visited[u] = true;

    // 3.2 update the distance to the remaining univisited node from u
    for (int v = 0; v < n; ++v) {
      if ( (!visited[v]) && (dst[u] + mat[u][v] < dst[v]) ) {
        dst[v] = dst[u] + mat[u][v];
        pre[v] = u;
      }
    }
  }
}

int main() {
  nhap();
  xuat();
  dijkstra(0, n-1);
  show_path(0, n-1);
}
