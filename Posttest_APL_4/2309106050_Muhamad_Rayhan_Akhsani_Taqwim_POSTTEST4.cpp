#include <iostream>
using namespace std;

// Deklarasi struct Tipe
struct Tipe {
    string kategori;
    float rating;
};

struct Data {
    string name;
    int value;
    Tipe tipe;
};

// fungsi
const int MAX_BARANG = 100;
int jumlah_menu = 5;
char kembali;
bool login();
void main2();
void tambahBarang(Data nestedArray[][MAX_BARANG], int &jumlah_menu);
void lihatBarang(Data nestedArray[][MAX_BARANG], int jumlah_menu);
void editBarang(Data nestedArray[][MAX_BARANG], int jumlah_menu);
void hapusBarang(Data nestedArray[][MAX_BARANG], int &jumlah_menu);
void back();

Data nestedArray[MAX_BARANG][MAX_BARANG] = {
    {"Espresso", 15000, {"Minuman", 8.5}},
    {"Latte", 20000, {"Minuman", 9.5}},
    {"Cappucino", 18000, {"Minuman", 8.8}},
    {"Waffle", 35000, {"Makanan", 7.8}},
    {"Banana Split", 25000, {"Minuman", 8.8}}
};

void main2() {
    int input = 0;
    do {
        cout << "\nMenu Utama:" << endl;
        cout << "1. Tambah Barang" << endl;
        cout << "2. Lihat Daftar Barang" << endl;
        cout << "3. Edit Barang" << endl;
        cout << "4. Hapus Barang" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> input;
        switch (input) {
            case 1:
                tambahBarang(nestedArray, jumlah_menu);
                break;
            case 2:
                lihatBarang(nestedArray, jumlah_menu);
                break;
            case 3:
                editBarang(nestedArray, jumlah_menu);
                break;
            case 4:
                hapusBarang(nestedArray, jumlah_menu);
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program." << endl;
                return;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (true);
}

void back() {
    cout << "Apakah anda ingin kembali ke menu?(Y/N) : ";
    cin >> kembali;
    if (kembali == 'Y') {
        main2();
    } else if (kembali == 'y') {
        main2();
    } else if (kembali == 'N') {
        cout << "Terima kasih telah menggunakan program." << endl;
        exit(0);
    } else if (kembali == 'n') {
        cout << "Terima kasih telah menggunakan program." << endl;
        exit(0);
    }
}

bool login() {
    for (int i = 0; i < 3; i++) {
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

void tambahBarang(Data nestedArray[][MAX_BARANG], int &jumlah_menu) {
    if (jumlah_menu < MAX_BARANG) {
        string namaBaru, kategoriBaru;
        int hargaBaru;
        float ratingBaru;
        cout << "Masukkan nama barang baru: ";
        cin >> namaBaru;
        cout << "Masukkan harga barang baru: ";
        cin >> hargaBaru;
        cout << "Masukkan kategori baru: ";
        cin >> kategoriBaru;
        cout << "Masukkan rating baru: ";
        cin >> ratingBaru;
        nestedArray[jumlah_menu][0] = {namaBaru, hargaBaru, {kategoriBaru, ratingBaru}};
        jumlah_menu++;
        cout << "Barang berhasil ditambahkan." << endl;
        back();
    } else {
        cout << "Maaf, kapasitas barang sudah penuh." << endl;
        back();
    }
}

void lihatBarang(Data nestedArray[][MAX_BARANG], int jumlah_menu) {
    cout << "\nDaftar Barang:" << endl;
    for (int a = 0; a < jumlah_menu; a++) {
        cout << a + 1 << ". " << nestedArray[a][0].name << " - Rp" << nestedArray[a][0].value  << " - Tipe : " <<nestedArray[a][0].tipe.kategori << " - Rating : " << nestedArray[a][0].tipe.rating<< endl;
    }
    back();
}

void editBarang(Data nestedArray[][MAX_BARANG], int jumlah_menu) {
    int indexEdit;
    cout << "Masukkan nomor barang yang ingin diedit: ";
    cin >> indexEdit;
    if (indexEdit >= 1 && indexEdit <= jumlah_menu) {
        string namaBaru, kategoriBaru;
        int hargaBaru;
        float ratingBaru;
        cout << "Masukkan nama barang baru: ";
        cin >> namaBaru;
        cout << "Masukkan harga barang baru: ";
        cin >> hargaBaru;
        cout << "Masukkan kategori baru: ";
        cin >> kategoriBaru;
        cout << "Masukkan rating baru: ";
        cin >> ratingBaru;
        nestedArray[indexEdit - 1][0] = {namaBaru, hargaBaru, {kategoriBaru, ratingBaru}};
        cout << "Barang berhasil diubah." << endl;
        back();
    } else {
        cout << "Nomor barang tidak valid." << endl;
        back();
    }
}

void hapusBarang(Data nestedArray[][MAX_BARANG], int &jumlah_menu) {
    int indexHapus;
    cout << "Masukkan nomor barang yang ingin dihapus: ";
    cin >> indexHapus;
    if (indexHapus >= 1 && indexHapus <= jumlah_menu) {
        for (int i = indexHapus - 1; i < jumlah_menu - 1; i++) {
            nestedArray[i][0] = nestedArray[i + 1][0];
        }
        jumlah_menu--;
        cout << "Barang berhasil dihapus." << endl;
        back();
    } else {
        cout << "Nomor barang tidak valid." << endl;
        back();
    }
}

int main() {
    if (login()) {
        main2();
    } else {
        cout << "Terima kasih telah menggunakan program." << endl;
    }
    return 0;
}
