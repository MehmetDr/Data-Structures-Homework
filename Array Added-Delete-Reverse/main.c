#include <stdio.h>

#define MAX 100

void yazdir(int arr[], int n) {
	int i;
    for( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void tersCevir(int arr[], int n) {
    int temp,i;
    for(i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

void elemanEkle(int arr[], int *n, int pos, int value) {
	int i;
    for(i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*n)++;
}

void elemanSil(int arr[], int *n, int pos) {
	int i;
    for(i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

int main() {
    int arr[MAX] = {10, 20, 30, 40};
    int n = 4;

    printf("Baslangic: ");
    yazdir(arr, n);

    elemanEkle(arr, &n, 2, 99);
    printf("Ekleme sonrasi: ");
    yazdir(arr, n);

    elemanSil(arr, &n, 1);
    printf("Silme sonrasi: ");
    yazdir(arr, n);

    tersCevir(arr, n);
    printf("Ters cevirme sonrasi: ");
    yazdir(arr, n);

    return 0;
}

