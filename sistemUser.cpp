#include "sistem.h"
#include "iostream"

using namespace std;

void lokasiPeminjaman(){

   string line;
   getline(file, line); // skip header

   string gedungInput, ruanganInput;
   cout << "Gedung: ";
   cin >> gedungInput;
   cin.ignore();

   cout << "Ruangan: ";
   getline(cin, ruanganInput);

   bool terpakai = false;

   while (getline(file, line)) {
      stringstream ss(line);
      string id, username, ruangan, hari, jam, alat, lokasi;

      getline(ss, id, ';');
      getline(ss, username, ';');
      getline(ss, lokasi, ';');
      getline(ss, ruangan, ';');
      getline(ss, hari, ';');
      getline(ss, jam, ';');
      getline(ss, alat, ';');

      if (ruangan == ruanganInput && lokasi == gedungInput) {
            terpakai = true;
            break;
      }
   }
   file.close();

   if (!terpakai) {
      cout << "Ruangan " << ruanganInput
            << " di gedung " << gedungInput
            << " KOSONG dan bisa dipinjam.\n";
   } else {
      cout << "Ruangan " << ruanganInput
            << " di gedung " << gedungInput
            << " SEDANG DIPAKAI.\n";
      cout << "Silakan pilih ruangan lain.\n";
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