#include <stdio.h>

int main() {
  int diemthi;
  printf("Nhap diem thi: "); scanf("%d",&diemthi);
  printf("Diem thi cua hoc sinh la: %d", diemthi);
  if (diemthi>=8 && diemthi<=10) printf("Do-Xep loai gioi");
  else if (diemthi == 7) printf("Do-Xep loai kha");
  else if (diemthi >=5 && diemthi <=6) printf("Do-Xep loai trung binh");
  else if (diemthi <5 && diemthi >0) printf("Truot-Xep loai kem");
  else printf("Diem khong hop le");
}
