#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
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

    cout << "\n========== DAFTAR PEMINJAMAN ==========\n";

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
        cout << "--------------------------------------\n";

        adaData = true;
    }

    if (!adaData) {
        cout << "Belum ada data peminjaman.\n";
    }

    file.close();
}

void editPeminjaman() {
    ifstream file("database/Peminjaman.csv");

    if (!file.is_open()) {
        cout << "Gagal membuka database peminjaman.\n";
        return;
    }

    vector<Peminjaman> data;
    string line;
    getline(file, line); // header

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

        data.push_back(p);
    }
    file.close();

    if (data.empty()) {
        cout << "Tidak ada data peminjaman.\n";
        return;
    }
    cout << "\n========== DATA PEMINJAMAN ==========\n";
    for (const auto& p : data) {
        cout << "ID: " << p.id
            << " | User: " << p.username
             << " | Ruang: " << p.ruangan
             << " | Hari: " << p.hari
             << " | Jam: " << p.jam << endl;
    }

    int idCari;
    cout << "\nMasukkan ID peminjaman yang ingin diubah: ";
    cin >> idCari;

    bool ditemukan = false;
    cin.ignore();

    for (auto& p : data) {
        if (p.id == idCari) {
            ditemukan = true;

            cout << "\n=== INPUT DATA BARU ===\n";
            cout << "Ruangan : ";
            getline(cin, p.ruangan);

            cout << "Hari    : ";
            getline(cin, p.hari);

            cout << "Jam     : ";
            getline(cin, p.jam);

            cout << "Alat    : ";
            getline(cin, p.alat);

            cout << "Lokasi  : ";
            getline(cin, p.lokasi);

            break;
        }
    }

    if (!ditemukan) {
        cout << "ID tidak ditemukan.\n";
        return;
    }

    ofstream out("database/Peminjaman.csv");
    out << "id;username;ruangan;hari;jam;alat;lokasi\n";

    for (const auto& p : data) {
        out << p.id << ";"
            << p.username << ";"
            << p.ruangan << ";"
            << p.hari << ";"
            << p.jam << ";"
            << p.alat << ";"
            << p.lokasi << endl;
    }

    out.close();
    cout << "\nData peminjaman BERHASIL diubah.\n";
}
