#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    do {
        printf("Nhap n: "); scanf("%d", &n);
    } while (n <= 0 || n > 100);

    float *arr = malloc(n * sizeof(float));
    if (arr == NULL) { return -1; }

    float min, max;
    printf("Nhap a[0]: "); scanf("%f", &arr[0]);
    min = max = arr[0];

    for (int i = 1; i < n; ++i) {
        printf("Nhap a[%d]: ", i); scanf("%f", &arr[i]);
        if (min > arr[i]) min = arr[i];
        if (max < arr[i]) max = arr[i];
    }

    printf("min + max = %f", min + max);

    free(arr);
}
