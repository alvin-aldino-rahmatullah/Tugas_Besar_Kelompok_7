#include "sistem.h"
#include "iostream"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>

using namespace std;

// ================= VOID LOKASI PEMINJAMAN =================
void lokasiPeminjaman() {
   ifstream file("database/Peminjaman.csv");
   if (!file.is_open()) {
      cout << "File Peminjaman.csv tidak ditemukan!\n";
      return;
   }

   string line;
    getline(file, line); // skip header

    // BERSIHKAN BUFFER DARI MENU
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   string gedungInput, ruanganInput;
   cout << "Gedung: ";
   getline(cin, gedungInput);

   cout << "Ruangan: ";
   getline(cin, ruanganInput);

   bool terpakai = false;

   while (getline(file, line)) {
      stringstream ss(line);
      string id, username, ruangan, hari, jam, alat, lokasi;

      getline(ss, id, ';');
      getline(ss, username, ';');
      getline(ss, ruangan, ';');
      getline(ss, hari, ';');
      getline(ss, jam, ';');
      getline(ss, alat, ';');
      getline(ss, lokasi, ';');

      if (ruangan == ruanganInput && lokasi == gedungInput) {
            terpakai = true;
            break;
      }
   }
   file.close();

   if (terpakai) {
      cout << "Ruangan " << ruanganInput
         << " di gedung " << gedungInput
         << " SEDANG DIPAKAI.\n";
   } else {
      cout << "Ruangan " << ruanganInput
         << " di gedung " << gedungInput
         << " KOSONG dan bisa dipinjam.\n";
   }
}

void alatTambahan(){
   string namaAlat;
   int jumlah;

   cout << "\n=== TAMBAH ALAT PINJAMAN ===\n";
   cout << "Nama alat   : ";
   cin.ignore();
   getline(cin, namaAlat);

   cout << "Jumlah alat : ";
   cin >> jumlah;

   if (jumlah <= 0) {
      cout << "Jumlah tidak valid!\n";
      return;
   }

   cout << "\nAlat berhasil ditambahkan!\n";
   cout << "Detail Peminjaman:\n";
   cout << "- Alat   : " << namaAlat << endl;
   cout << "- Jumlah : " << jumlah << endl;
}

void jadwalPemakaian(){
   cout << "Jadwal Pemakaian dipilih"<< endl;
}