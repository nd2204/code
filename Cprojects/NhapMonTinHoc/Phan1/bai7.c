#include <stdio.h>
//Bai 7: nhap n in hien thi ra man hinh hinh tam giac nguoc bang dau *
void starLadderInverse(int a) {
  for (int i=0; i<a; i++){
    for (int j=0; j<a-i; j++){
      printf("*");
    }
    printf("\n");
  }
}

int main() {
  int n;
  printf("Nhap n:"); scanf("%d",&n);
  starLadderInverse(n);
}
