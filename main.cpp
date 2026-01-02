#include "sistem.h"
#include "iostream"
using namespace std;


int main() {
    int pilihan;

    while (true) {
        cout << "=============================" << endl;
        cout << "       SELAMAT DATANG  " << endl;
        cout << "=============================" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                login();
                break;
            case 2:
                registerUser();
                break;
            case 3:
                return 0;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }
}

void adminMenu(){
    int pilih;
    do {
        cout << "=============================" << endl;
        cout << " SELAMAT DATANG MENU ADMIN " << endl;
        cout << "=============================" << endl;
        cout << "1. Daftar Peminjam" << endl;
        cout << "2. Edit Peminjaman" << endl;
        cout << "3. Aktivasi" << endl;
        cout << "4. Logout" << endl;
        cout << "Pilih: ";
        cin >> pilih;
        
    switch (pilih){
        case 1: 
        daftarPeminjam();
        break;
        case 2:
        editPeminjaman();
        break;
        case 3:
        aktivasiUser();
        break;
        case 4:
        cout << "Logout berhasil." << endl;
        break;
    }
    } while (pilih != 4);
}

void userMenu(){
    int pilih;
    do {
        cout << "=============================" << endl;
        cout << "   SELAMAT DATANG MENU USER  " << endl;
        cout << "=============================" << endl;
        cout << "1. Lokasi Peminjaman" << endl;
        cout << "2. Jadwal Pemakaian" << endl;
        cout << "3. Alat Tambahan" << endl;
        cout << "4. Logout" << endl;
        cout << "Pilih: ";
        cin >> pilih;

    switch (pilih){
        case 1: 
        lokasiPeminjaman();
        break;
        break;
        case 2:
        alatTambahan();
        break;
        case 3:
        cout << "Logout berhasil." << endl;
        break;
    }
    } while (pilih != 3);
}


