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
void sorting_harga_ascending(Data nestedArray[][MAX_BARANG], int jumlah_menu);
void sorting_nama_descending(Data nestedArray[][MAX_BARANG], int jumlah_menu);
void sorting_rating_ascending(Data nestedArray[][MAX_BARANG], int jumlah_menu);
void searching_nama_binary(Data nestedArray[][MAX_BARANG], int jumlah_menu);
int binarySearch(Data nestedArray[][MAX_BARANG], int l, int r, string target);
int linearSearch_harga(Data nestedArray[][MAX_BARANG], int jumlah_menu, int target);
void searching_harga_linear(Data nestedArray[][MAX_BARANG], int jumlah_menu);
void back();
void quickSort(Data nestedArray[][MAX_BARANG], int low, int high);
int partition(Data nestedArray[][MAX_BARANG], int low, int high);
void printArray(Data nestedArray[][MAX_BARANG], int jumlah_menu);

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
        cout << "5. Sorting ascending melalui Rating (Quicksort)" << endl;
        cout << "6. Searching Data ascending melalui harga (Bubblesort dan Sequential search)" << endl;
        cout << "7. Searching data descending melalui nama (selection sort dan Binary search)" << endl;
        cout << "8. Keluar" << endl;
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
                quickSort(nestedArray, 0, jumlah_menu - 1);
                cout << "Data telah diurutkan berdasarkan rating secara ascending." << endl;
                lihatBarang(nestedArray, jumlah_menu);
                break;
            case 6:
                sorting_harga_ascending(nestedArray, jumlah_menu);
                cout << "Data telah diurutkan berdasarkan harga secara ascending.  " << endl;
                cout << endl;
                searching_harga_linear(nestedArray, jumlah_menu);
                break;
            case 7:
                sorting_nama_descending(nestedArray, jumlah_menu); 
                cout << "Data telah diurutkan berdasarkan Nama secara Descending.  " << endl;
                searching_nama_binary(nestedArray, jumlah_menu); 
                break;
            case 8:
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
        jumlah_menu++;
        back();
        jumlah_menu++;
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
    string teks = "List Habis";
    string *teksptr = &teks;
    *teksptr = "List Selesai";
    cout << *teksptr <<endl;
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
        jumlah_menu--;
    } else {
        cout << "Nomor barang tidak valid." << endl;
        back();
    }
}

int binarySearch(Data nestedArray[][MAX_BARANG], int l, int r, string target) {
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (nestedArray[mid][0].name == target)
            return mid;

        if (nestedArray[mid][0].name > target)
            l = mid + 1; // Ubah ke arah yang berlawanan dengan urutan ascending
        else
            r = mid - 1; // Ubah ke arah yang berlawanan dengan urutan ascending
    }

    return -1; // Mengembalikan -1 jika barang tidak ditemukan
}


void searching_nama_binary(Data nestedArray[][MAX_BARANG], int jumlah_menu) {
    string target;
    cout << "Masukkan nama barang yang ingin dicari: ";
    cin >> target;

    // Panggil binarySearch
    int index = binarySearch(nestedArray, 0, jumlah_menu - 1, target);

    // Output hasil pencarian
    if (index != -1) {
        cout << "Nama: " << nestedArray[index][0].name << endl;
        cout << "Harga: Rp" << nestedArray[index][0].value << endl;
        cout << "Tipe: " << nestedArray[index][0].tipe.kategori << endl;
        cout << "Rating: " << nestedArray[index][0].tipe.rating << endl;
        cout << "Barang ditemukan pada index " << index << " Atau urutan ke "<< index + 1 << ":" << endl;
    } else {
        cout << "Barang tidak ditemukan." << endl;
    }
}


int linearSearch_harga(Data nestedArray[][MAX_BARANG], int jumlah_menu, int target) {
    for (int i = 0; i < jumlah_menu; ++i) {
        if (nestedArray[i][0].value == target) {
            return i;
        }
    }
    return -1; // Mengembalikan -1 jika barang tidak ditemukan
}

// Implementasi fungsi searching_harga_linear
void searching_harga_linear(Data nestedArray[][MAX_BARANG], int jumlah_menu) {
    int target;
    cout << "Masukkan harga barang yang ingin dicari: ";
    cin >> target;

    // Panggil linearSearch_harga
    int index = linearSearch_harga(nestedArray, jumlah_menu, target);

    // Output hasil pencarian
    if (index != -1) {
        cout << "Nama: " << nestedArray[index][0].name << endl;
        cout << "Harga: Rp" << nestedArray[index][0].value << endl;
        cout << "Tipe: " << nestedArray[index][0].tipe.kategori << endl;
        cout << "Rating: " << nestedArray[index][0].tipe.rating << endl;
        cout << "Barang ditemukan pada indeks " << index << " Atau pada urutan ke " << index + 1 << ":" << endl;
    } else {
        cout << "Barang tidak ditemukan." << endl;
    }
}


void sorting_nama_descending(Data nestedArray[][MAX_BARANG], int jumlah_menu) {
    cout << "Data sebelum diurutkan: " << endl;
    printArray(nestedArray, jumlah_menu);

    // Selection sort untuk mengurutkan nama secara descending
    for (int i = 0; i < jumlah_menu - 1; ++i) {
        int max_index = i;
        for (int j = i + 1; j < jumlah_menu; ++j) {
            if (nestedArray[j][0].name > nestedArray[max_index][0].name) {
                max_index = j;
            }
        }
        if (max_index != i) {
            swap(nestedArray[i][0], nestedArray[max_index][0]);
        }
    }

    cout << "Data setelah diurutkan berdasarkan nama secara descending: " << endl;
    printArray(nestedArray, jumlah_menu);
}

void swap(int *data1, int *data2){
	int temp = *data1;
	*data1 = *data2;
	*data2 = temp;
}


int partition(Data nestedArray[][MAX_BARANG], int low, int high) {
    float pivot = nestedArray[high][0].tipe.rating;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (nestedArray[j][0].tipe.rating <= pivot) {
            i++;
            swap(nestedArray[i][0], nestedArray[j][0]);
        }
    }
    swap(nestedArray[i + 1][0], nestedArray[high][0]);
    return (i + 1);
}

void quickSort(Data nestedArray[][MAX_BARANG], int low, int high) {
    if (low < high) {
        int pi = partition(nestedArray, low, high);
        quickSort(nestedArray, low, pi - 1);
        quickSort(nestedArray, pi + 1, high);
    }
}



void printArray(Data nestedArray[][MAX_BARANG],int jumlah_menu){
	int i;
	for(i = 0;i<jumlah_menu;i++){
		cout << i + 1 << ". " << nestedArray[i][0].name << " - Rp" << nestedArray[i][0].value  
        << " - Tipe : " <<nestedArray[i][0].tipe.kategori << " - Rating : " << nestedArray[i][0].tipe.rating<< endl;
	}
	cout<<endl;
}

void sorting_rating_ascending(Data nestedArray[][MAX_BARANG], int jumlah_menu) {
    cout << "Data sebelum diurutkan: " << endl;
    printArray(nestedArray, jumlah_menu);
    
    quickSort(nestedArray, 0, jumlah_menu - 1);
    
    cout << "Data setelah diurutkan berdasarkan rating secara ascending: " << endl;
    printArray(nestedArray, jumlah_menu);
}




void sorting_harga_ascending(Data nestedArray[][MAX_BARANG],int jumlah_menu) {
    int swap_harga, i, j;
    float swap_rating;
    string swap_nama, swap_kategori;
cout << "Data sebelum diurutkan: " << endl;
for (i = 0; i < jumlah_menu; i++) {
    if (nestedArray[i][0].value != 0) {
        cout << " " << nestedArray[i][0].value;
    }
}
for (i = 0; i < jumlah_menu; i++) {
for (j = 0; j < (jumlah_menu -i-1); j++) {
if(nestedArray[j][0].value > nestedArray[j+1][0].value) {
// pindah nama
swap_nama = nestedArray[j][0].name;
nestedArray[j][0].name = nestedArray[j+1][0].name;
nestedArray[j+1][0].name = swap_nama;
// pindah harga
swap_harga = nestedArray[j][0].value;
nestedArray[j][0].value = nestedArray[j+1][0].value;
nestedArray[j+1][0].value = swap_harga;
// pindah kategori
swap_kategori = nestedArray[j][0].tipe.kategori;
nestedArray[j][0].tipe.kategori = nestedArray[j+1][0].tipe.kategori;
nestedArray[j+1][0].tipe.kategori = swap_kategori;
// pindah rating
swap_rating = nestedArray[j][0].tipe.rating;
nestedArray[j][0].tipe.rating = nestedArray[j+1][0].tipe.rating;
nestedArray[j+1][0].tipe.rating = swap_rating;
}
}
cout << endl;
cout << endl;
cout << "Proses [" << i + 1 << "]";
for (int k = 0; k < 50; k++) {
if (nestedArray[k][0].value != 0) {
cout << " " << nestedArray[k][0].value;
}
}
}
cout << endl;
cout << endl;
cout << "Data sesudah diurutkan berdasarkan harga ascending: " << endl;
for (i = 0; i < MAX_BARANG; i++) {
    if (nestedArray[i][0].value != 0) {
        cout << i + 1 << ". " << nestedArray[i][0].name << " - Rp" 
        << nestedArray[i][0].value  << " - Tipe : " <<nestedArray[i][0].tipe.kategori 
        << " - Rating : " << nestedArray[i][0].tipe.rating<< endl;
    }
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