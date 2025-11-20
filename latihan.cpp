#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

// Fungsi buat nampilin data mahasiswa
void tampilkanData(Mahasiswa mhs[], int n) {
    cout << "\n=== DAFTAR MAHASISWA ===" << endl;
    cout << "=============================================" << endl;
    cout << left << setw(5) << "No" << setw(20) << "Nama" 
         << setw(15) << "NIM" << setw(10) << "IPK" << endl;
    cout << "=============================================" << endl;
    
    for (int i = 0; i < n; i++) {
        cout << left << setw(5) << i + 1 
             << setw(20) << mhs[i].nama 
             << setw(15) << mhs[i].nim 
             << setw(10) << fixed << setprecision(2) << mhs[i].ipk << endl;
    }
}

// Bubble Sort berdasarkan Nama (Ascending)
void bubbleSortNama(Mahasiswa mhs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (mhs[j].nama > mhs[j + 1].nama) {
                // Tukar posisi
                Mahasiswa temp = mhs[j];
                mhs[j] = mhs[j + 1];
                mhs[j + 1] = temp;
            }
        }
    }
}

// Bubble Sort berdasarkan IPK (Descending)
void bubbleSortIPK(Mahasiswa mhs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (mhs[j].ipk < mhs[j + 1].ipk) {
                // Tukar posisi
                Mahasiswa temp = mhs[j];
                mhs[j] = mhs[j + 1];
                mhs[j + 1] = temp;
            }
        }
    }
}

// Bubble Sort berdasarkan NIM (Ascending)
void bubbleSortNIM(Mahasiswa mhs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (mhs[j].nim > mhs[j + 1].nim) {
                // Tukar posisi
                Mahasiswa temp = mhs[j];
                mhs[j] = mhs[j + 1];
                mhs[j + 1] = temp;
            }
        }
    }
}

void programMahasiswa() {
    const int MAX = 5;
    Mahasiswa mhs[MAX];
    int n;
    
    cout << "\n=== PROGRAM SORTING DATA MAHASISWA ===" << endl;
    cout << "Masukkan jumlah mahasiswa (maksimal " << MAX << "): ";
    cin >> n;
    
    if (n > MAX) {
        cout << "Jumlah melebihi batas maksimal!" << endl;
        return;
    }
    
    cout << "\n--- Input Data Mahasiswa ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Mahasiswa " << i + 1 << ":" << endl;
        cout << "Nama: ";
        cin.ignore();
        getline(cin, mhs[i].nama);
        cout << "NIM: ";
        cin >> mhs[i].nim;
        cout << "IPK: ";
        cin >> mhs[i].ipk;
        cout << endl;
    }
    
    cout << "--- Data Sebelum Sorting ---" << endl;
    tampilkanData(mhs, n);
    
    int pilihan;
    do {
        cout << "\n=== MENU SORTING ===" << endl;
        cout << "1. Sort by Nama (A-Z)" << endl;
        cout << "2. Sort by IPK (Tertinggi-Terendah)" << endl;
        cout << "3. Sort by NIM (A-Z)" << endl;
        cout << "4. Tampilkan Data" << endl;
        cout << "5. Kembali ke Menu Utama" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                bubbleSortNama(mhs, n);
                cout << "Data berhasil diurutkan berdasarkan Nama!" << endl;
                tampilkanData(mhs, n);
                break;
            case 2:
                bubbleSortIPK(mhs, n);
                cout << "Data berhasil diurutkan berdasarkan IPK!" << endl;
                tampilkanData(mhs, n);
                break;
            case 3:
                bubbleSortNIM(mhs, n);
                cout << "Data berhasil diurutkan berdasarkan NIM!" << endl;
                tampilkanData(mhs, n);
                break;
            case 4:
                tampilkanData(mhs, n);
                break;
            case 5:
                cout << "Kembali ke menu utama..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while(pilihan != 5);
}