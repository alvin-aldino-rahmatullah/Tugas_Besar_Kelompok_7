#include <iostream>
#include <fstream>
#include <sstream>
#include "sistem.h"

using namespace std;

void daftarPeminjam() {
    ifstream file("database/Peminjaman.csv");

    if (!file.is_open()) {
        cout << "Gagal membuka database peminjaman.\n";
        return;
    }

    string line;
    getline(file, line); // lewati header

    cout << "\n================ DAFTAR PEMINJAMAN =================\n";

    bool adaData = false;

    while (getline(file, line)) {
        stringstream ss(line);
        string temp;
        Peminjaman p;

        getline(ss, temp, ';');
        p.id = stoi(temp);

        getline(ss, p.username, ';');
        getline(ss, p.ruangan, ';');
        getline(ss, p.hari, ';');
        getline(ss, p.jam, ';');
        getline(ss, p.alat, ';');
        getline(ss, p.lokasi, ';');

        cout << "ID       : " << p.id << endl;
        cout << "User     : " << p.username << endl;
        cout << "Ruangan  : " << p.ruangan << endl;
        cout << "Hari     : " << p.hari << endl;
        cout << "Jam      : " << p.jam << endl;
        cout << "Alat     : " << p.alat << endl;
        cout << "Lokasi   : " << p.lokasi << endl;
        cout << "---------------------------------------------------\n";

        adaData = true;
    }

    if (!adaData) {
        cout << "Belum ada data peminjaman.\n";
    }

    file.close();
}


void viewPeminjam(){
   cout << "View Peminjam dipilih"<< endl;
}