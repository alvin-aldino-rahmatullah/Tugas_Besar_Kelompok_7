#include "sistem.h"
#include "iostream"

using namespace std;

void lokasiPeminjaman(){
   cout << "Lokasi Peminjaman dipilih"<< endl;
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