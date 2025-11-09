#include <iostream>
using namespace std;

// Struct buat nyimpen data mahasiswa
struct Mahasiswa {
    string nama;
    int nilai;
};

// Fungsi buat nuker dua struct Mahasiswa
void swap(Mahasiswa* a, Mahasiswa* b) {
    Mahasiswa temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi partisi buat Quick Sort (berdasarkan nilai)
int partition(Mahasiswa arr[], int low, int high) {
    int pivot = arr[high].nilai;  // Pivot berdasarkan nilai
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].nilai <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Fungsi Quick Sort
void quickSort(Mahasiswa arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fungsi buat menampilkan array of struct
void printArray(Mahasiswa arr[], int size) {
    cout << "Nama\t\tNilai" << endl;
    cout << "-------------------" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i].nama << "\t\t" << arr[i].nilai << endl;
    }
}

int main() {
    int n;
    
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;
    
    Mahasiswa mhs[n];
    
    cout << "Masukkan data mahasiswa (nama dan nilai):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Mahasiswa " << i + 1 << " - Nama: ";
        cin >> mhs[i].nama;
        cout << "Mahasiswa " << i + 1 << " - Nilai: ";
        cin >> mhs[i].nilai;
    }
    
    cout << "\nData sebelum diurutkan:" << endl;
    printArray(mhs, n);
    
    quickSort(mhs, 0, n - 1);
    
    cout << "\nData setelah diurutkan (berdasarkan nilai ascending):" << endl;
    printArray(mhs, n);
    
    return 0;
}