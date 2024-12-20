#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // Library untuk menghitung waktu eksekusi

#define MAX_SIZE 100  // Batas maksimum elemen array

// Fungsi untuk melakukan Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Tukar nilai
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Fungsi untuk membaca angka dari file dan mengembalikan jumlah elemen yang dibaca
int readFromFile(const char *filename, int arr[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Gagal membuka file: %s\n", filename);
        return -1;
    }

    int i = 0;
    while (fscanf(file, "%d", &arr[i]) != EOF) {
        i++;
        if (i >= MAX_SIZE) {
            printf("Peringatan: Jumlah elemen melebihi batas maksimum (%d).\n", MAX_SIZE);
            break;
        }
    }

    fclose(file);
    return i;
}

// Fungsi untuk menulis hasil pengurutan ke dalam file
void writeToFile(const char *filename, int arr[], int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Gagal membuka file untuk menulis: %s\n", filename);
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", arr[i]);
    }

    fclose(file);
}

int main() {
    const char *inputFilename = "D:\\headache\\fundamental programing\\pjbl program pengurutan angka\\input_6.txt";  // Nama file input
    const char *outputFilename = "D:\\headache\\fundamental programing\\pjbl program pengurutan angka\\output_6.txt"; // Nama file output
    int arr[MAX_SIZE];  // Array untuk menampung angka
    int n;              // Jumlah angka yang dibaca

    // Variabel untuk menghitung waktu eksekusi
    clock_t start, end;
    double cpu_time_used;

    // Membaca data dari file
    n = readFromFile(inputFilename, arr);
    if (n == -1) {
        return 1;  // Keluar jika gagal membuka file
    }

    // Menampilkan angka sebelum diurutkan
    printf("Angka sebelum diurutkan:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Menghitung waktu eksekusi sorting
    start = clock();
    bubbleSort(arr, n);
    end = clock();

    // Menghitung waktu yang digunakan
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Menampilkan angka setelah diurutkan
    printf("Angka setelah diurutkan:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Menampilkan waktu eksekusi
    printf("Waktu eksekusi pengurutan: %.6f detik\n", cpu_time_used);

    // Menyimpan hasil pengurutan ke dalam file output
    writeToFile(outputFilename, arr, n);

    printf("Hasil pengurutan telah disimpan ke file '%s'.\n", outputFilename);

    return 0;
}
