#include "sistem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

void lokasiPeminjaman() {
   ifstream file("database/Peminjaman.csv");
   if (!file.is_open()) {
      cout << "File Peminjaman.csv tidak ditemukan!\n";
      return;
   }

   string line;
   getline(file, line); 

   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   Peminjaman p;

   cout << "ID       : ";
   cin >> p.id;
   cin.ignore();

   cout << "Username : ";
   getline(cin, p.username);

   cout << "Ruangan  : ";
   getline(cin, p.ruangan);

   cout << "Hari     : ";
   getline(cin, p.hari);

   cout << "Jam      : ";
   getline(cin, p.jam);

   cout << "Lokasi   : ";
   getline(cin, p.lokasi);

   bool terpakai = false;

   while (getline(file, line)) {
      stringstream ss(line);
      Peminjaman cek;

      string sid;
      getline(ss, sid, ';');
      cek.id = stoi(sid);
      getline(ss, cek.username, ';');
      getline(ss, cek.ruangan, ';');
      getline(ss, cek.hari, ';');
      getline(ss, cek.jam, ';');
      getline(ss, cek.alat, ';');
      getline(ss, cek.lokasi, ';');

      if (cek.ruangan == p.ruangan && cek.lokasi == p.lokasi) {
            terpakai = true;
            break;
      }
   }
   file.close();

   if (terpakai) {
      cout << "❌ Ruangan sedang dipakai.\n";
      return;
   }

   ofstream out("database/Peminjaman.csv", ios::app);
   out << p.id << ";" << p.username << ";" << p.ruangan << ";"
      << p.hari << ";" << p.jam << ";" << p.alat << ";" << p.lokasi << endl;
   out.close();

   cout << "✅ Peminjaman ruangan berhasil disimpan.\n";
}

// ================= ALAT TAMBAHAN =================
void alatTambahan() {
   ifstream file("database/Peminjaman.csv");
   if (!file.is_open()) {
      cout << "File Peminjaman.csv tidak ditemukan!\n";
      return;
   }

   string data[200];
   int n = 0;

   while (getline(file, data[n])) n++;
   file.close();

   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   string ruanganInput, alatInput;
   cout << "Ruangan : ";
   getline(cin, ruanganInput);

   cout << "Alat tambahan : ";
   getline(cin, alatInput);

   bool ditemukan = false;

   for (int i = 1; i < n; i++) {
      stringstream ss(data[i]);
      Peminjaman p;
      string sid;

      getline(ss, sid, ';');
      p.id = stoi(sid);
      getline(ss, p.username, ';');
      getline(ss, p.ruangan, ';');
      getline(ss, p.hari, ';');
      getline(ss, p.jam, ';');
      getline(ss, p.alat, ';');
      getline(ss, p.lokasi, ';');

      if (p.ruangan == ruanganInput) {
            p.alat = alatInput;
            data[i] = to_string(p.id) + ";" + p.username + ";" +
               p.ruangan + ";" + p.hari + ";" + p.jam + ";" +
               p.alat + ";" + p.lokasi;
            ditemukan = true;
            break;
      }
   }

   if (!ditemukan) {
      cout << "❌ Ruangan tidak ditemukan atau belum dipinjam.\n";
      return;
   }

   ofstream out("database/Peminjaman.csv");
   for (int i = 0; i < n; i++)
      out << data[i] << endl;
   out.close();

   cout << "Alat tambahan berhasil ditambahkan.\n";
}



