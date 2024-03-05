#include <iostream>
using namespace std;

//Nama = Muhamad Rayhan Akhsani Taqwim, NIM = 2309106050

bool login();
int ulang();
void Konversi();

//Main function
int main() {
    if (login()) {
        Konversi();
    } 
    return 0;
}

//function login
bool login() {
    int i;
    for (i = 0; i < 3; i++) {
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



//function untuk mengulang konversi sesuai kemauan user
int ulang() {
    char pilih;
    cout << "Apakah anda ingin konversi lagi? (Y/N) : ";
    cin >> pilih;
    if (pilih == 'Y' || pilih == 'y') {
        Konversi();
    }   else if (pilih == 'N' || pilih == 'n') {
        return 0;
    }
    return 0;
}

//function untuk mengkonversi
void Konversi(){
    int input;
    double Km_jam, Cm_detik, M_detik, Mil_jam; 
    cout << "Menu Konversi Kecepatan: " << endl;
    cout << "1. Kilometer/Jam ke (Centimeter/detik, Meter/detik, Mil/jam): " << endl;
    cout << "2. Konversi Centimeter/detik ke (Kilometer/jam, Meter/detik, Mil/jam)" << endl;
    cout << "3. Konversi Meter/detik ke (Kilometer/jam, Meter/detik, Mil/jam)" << endl; 
    cout << "4. Konversi Mil/jam ke (Kilometer/jam, Centimeter/detik, Meter/detik)" << endl;
    cin >> input;
    if ( input == 1) {
        cout << "Masukkan Km/jam: ";
        cin >> Km_jam;
        Cm_detik = Km_jam* 100000 / 3600;
        M_detik = Km_jam * 1000 / 3600;
        Mil_jam = Km_jam / 1.609;
        cout << "Hasil konversi: " << Cm_detik << " cm/detik, " << M_detik << " m/detik, " << Mil_jam << " mil/jam" << endl;
        ulang();
    } else if ( input == 2) {
        cout << "Masukkan kecepatan dalam Centimeter/detik: ";
        cin >> Cm_detik;
        Km_jam = Cm_detik * 3600 / 100000;
        M_detik = Cm_detik / 100;
        Mil_jam = Cm_detik * 0.0223694 / 1.60934;
        cout << "Hasil konversi: " << Km_jam << " km/jam, " << M_detik << " m/detik, " << Mil_jam << " mil/jam" << endl;
        ulang();
    } else if ( input == 3) {
    cout << "Masukkan kecepatan dalam Meter/detik: ";
    cin >> M_detik;
    Km_jam = M_detik * 3600 / 1000;
    Cm_detik = M_detik * 100;
    Mil_jam = M_detik * 2.23694;
    cout << "Hasil konversi: " << Km_jam << " km/jam, " << Cm_detik << " cm/detik, " << Mil_jam << " mil/jam" << endl;
    ulang();
    } else if ( input == 4) {
        cout << "Masukkan kecepatan dalam Mil/jam: ";
        cin >> Mil_jam;
        Km_jam = Mil_jam * 1.609;
        Cm_detik = Mil_jam * 44704;
        M_detik = Mil_jam * 1609 / 3600;
        cout << "Hasil konversi: " << Km_jam << " km/jam, " << Cm_detik << " cm/detik, " << M_detik << " m/detik" << endl;
        ulang();
    } else {
        cout<< "Input anda harus berupa interger 1-4...";
    }
}

