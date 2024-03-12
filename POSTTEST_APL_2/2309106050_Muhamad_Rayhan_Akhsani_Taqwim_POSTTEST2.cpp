#include <iostream>
using namespace std;


// Nama = Rayhan
// NIM = 2309106050


// Deklarasi struct Data
struct Data {
    string name;
    int value;
};

// fungsi
bool login();
void tambahBarang(Data nestedArray[][2], int &jumlah_menu, const int MAX_BARANG);
void lihatBarang(Data nestedArray[][2], int jumlah_menu);
void editBarang(Data nestedArray[][2], int jumlah_menu);
void hapusBarang(Data nestedArray[][2], int &jumlah_menu);

const int MAX_BARANG = 100;
int jumlah_menu = 3;
const int isi_menu = 2;
Data nestedArray[MAX_BARANG][isi_menu] = {
    {"Espresso",15000},
    {"Latte",20000},
    {"Cappucino",18000}
};

// fungsi utama
int main() {
    if (login()) {
        int input;
        do {
            cout << "\nMenu Utama:" << endl;
            cout << "1. Tambah Barang" << endl;
            cout << "2. Lihat Daftar Barang" << endl;
            cout << "3. Edit Barang" << endl;
            cout << "4. Hapus Barang" << endl;
            cout << "5. Keluar" << endl;
            cout << "Pilihan Anda: ";
            cin >> input;
            if (input == 1) {
                tambahBarang(nestedArray, jumlah_menu, MAX_BARANG);
            } else if (input == 2) {
                lihatBarang(nestedArray, jumlah_menu);
            } else if (input == 3) {
                editBarang(nestedArray, jumlah_menu);
            } else if (input == 4) {
                hapusBarang(nestedArray, jumlah_menu);
            } else if (input == 5) {
                cout << "Terima kasih telah menggunakan program." << endl;
            }
        } while (input != 5);
    } 
    return 0;
}

// fungsi login
bool login() {
    for (int i = 0; i < 3; i++) {  // Inisialisasi variabel i di sini
        string Nama, NIM;
        cout << "Masukkan nama anda: ";
        cin >> Nama;
        cout << "Masukkan NIM anda: ";
        cin >> NIM;
        if (Nama == "Rayhan" && NIM == "2309106050") {
            return true;
        } else {
            cout << "Nama atau NIM anda salah, silahkan coba sekali lagi...." << endl;
        }
    }
    cout << "Anda sudah salah mengisi 3 kali, program telah dihentikan!!!" << endl;
    return false;
}

// fungsi tambah barang ke array
void tambahBarang(Data nestedArray[][2], int &jumlah_menu, const int MAX_BARANG) {
    if (jumlah_menu < MAX_BARANG) {
        string namaBaru;
        int hargaBaru;
        cout << "Masukkan nama barang baru: ";
        cin >> namaBaru;
        cout << "Masukkan harga barang baru: ";
        cin >> hargaBaru;
        nestedArray[jumlah_menu][0].name = namaBaru;
        nestedArray[jumlah_menu][0].value = hargaBaru;
        jumlah_menu++;
        cout << "Barang berhasil ditambahkan." << endl;
    } else {
        cout << "Maaf, kapasitas barang sudah penuh." << endl;
    }
}

// fungsi menampilkan barang
void lihatBarang(Data nestedArray[MAX_BARANG][2], int jumlah_menu) {
    cout << "\nDaftar Barang:" << endl;
    for (int a = 0; a < jumlah_menu; a++) {
        cout << a+1 << ". " << nestedArray[a][0].name << " - Rp" << nestedArray[a][0].value << endl;
    }
}

// fungsi mengedit barang
void editBarang(Data nestedArray[][2], int jumlah_menu) {
    int indexEdit;
    cout << "Masukkan nomor barang yang ingin diedit: ";
    cin >> indexEdit;
    if (indexEdit >= 1 && indexEdit <= jumlah_menu) {
        string namaBaru;
        int hargaBaru;
        cout << "Masukkan nama barang baru: ";
        cin >> namaBaru;
        cout << "Masukkan harga barang baru: ";
        cin >> hargaBaru;
        nestedArray[indexEdit - 1][0].name = namaBaru;
        nestedArray[indexEdit - 1][0].value = hargaBaru;
        cout << "Barang berhasil diubah." << endl;
    } else {
        cout << "Nomor barang tidak valid." << endl;
    }
}

// fungsi menghapus barang
void hapusBarang(Data nestedArray[][2], int &jumlah_menu) {
    int indexHapus;
    cout << "Masukkan nomor barang yang ingin dihapus: ";
    cin >> indexHapus;
    if (indexHapus >= 1 && indexHapus <= jumlah_menu) {
        for (int i = indexHapus - 1; i < jumlah_menu - 1; i++) {
            nestedArray[i][0] = nestedArray[i + 1][0];
            nestedArray[i][1] = nestedArray[i + 1][1];
        }
        jumlah_menu--;
        cout << "Barang berhasil dihapus." << endl;
    } else {
        cout << "Nomor barang tidak valid." << endl;
    }
}
