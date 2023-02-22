#include <stdio.h>
//Bai 8
void starQuad(int row, int column) {
  for (int i=0; i<row; i++){
    for (int j=0; j<column; j++) {
      printf("*");
    }
    printf("\n");
  }
}
int main() {
  int n,m;
  printf("Nhap so hang n: "); scanf("%d",&n);
  printf("Nhap so cot m: "); scanf("%d",&m);
  starQuad(n,m);
}
