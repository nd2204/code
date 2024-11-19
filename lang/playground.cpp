#include <stdio.h>
#include <stdlib.h>


struct sv {
  char hoten[256];
  char que[1024];
  double diem;
};

void nhap(sv* const sv) {
  printf("Nhap ten: "); fgets();
}

int main() {
  int n;
  do {
    printf("Nhap n: "); scanf("%d", &n);
  } while(n > 50 || n < 0);

  FILE *handler = fopen("ketqua.txt", "w");
  if (!handler) {
    printf("Khong mo duoc file");
    return -1;
  }

}
