#include "sistem.h"
#include "iostream"
using namespace std;

main (){
    string role = login();
    if (role == "admin"){
        adminMenu();
    }
    else if (role == "user"){
        userMenu();
    }
}

void adminMenu(){
    int pilih;
    do {
        cout << "=============================" << endl;
        cout << "   SELAMAT DATANG MENU ADMIN " << endl;
        cout << "=============================" << endl;
        cout << "1. Daftar Peminjam" << endl;
        cout << "2. View Peminjam" << endl;
        cout << "3. Logout" << endl;
        cout << "Pilih: ";
        cin >> pilih;
        
    switch (pilih){
        case 1: 
        daftarPeminjam();
        break;
        case 2:
        viewPeminjam();
        break;
        case 3:
        cout << "Logout berhasil." << endl;
        break;
    }
    } while (pilih != 3);
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
        case 2:
        jadwalPemakaian();
        break;
        case 3:
        alatTambahan();
        break;
        case 4:
        cout << "Logout berhasil." << endl;
        break;
    }
    } while (pilih != 4);
}


