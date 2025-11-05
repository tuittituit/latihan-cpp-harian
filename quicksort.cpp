#include <iostream>
using namespace std;

// Fungsi untuk menukar dua elemen
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk partisi array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pilih elemen terakhir sebagai pivot
    int i = (low - 1);      // Index elemen yang lebih kecil
    
    for (int j = low; j <= high - 1; j++) {
        // Jika elemen saat ini lebih kecil atau sama dengan pivot
        if (arr[j] <= pivot) {
            i++;  // Increment index elemen yang lebih kecil
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Fungsi utama Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi adalah partitioning index, arr[pi] sekarang di posisi yang benar
        int pi = partition(arr, low, high);
        
        // Urutkan elemen secara rekursif sebelum dan setelah partisi
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fungsi untuk menampilkan array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    
    cout << "Masukkan jumlah elemen: ";
    cin >> n;
    
    int arr[n];
    
    cout << "Masukkan " << n << " elemen: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Array sebelum diurutkan: ";
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1);
    
    cout << "Array setelah diurutkan (ascending): ";
    printArray(arr, n);
    
    return 0;
}