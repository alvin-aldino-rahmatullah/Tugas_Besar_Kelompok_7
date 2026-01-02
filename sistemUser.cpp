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

   int lastId = 0;

   while (getline(file, line)) {
      stringstream ss(line);
      string sid;
      getline(ss, sid, ';');
      lastId = stoi(sid);
   }
   file.close();

   int newId = lastId + 1;

   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   Peminjaman p;
   p.id = newId;

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

   p.alat = "-";

   file.open("database/Peminjaman.csv");
   getline(file, line);

   bool terpakai = false;
   while (getline(file, line)) {
      stringstream ss(line);
      Peminjaman cek;
      string sid;

      getline(ss, sid, ';');
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
      cout << "Ruangan sedang dipakai.\n";
      return;
   }

   ofstream out("database/Peminjaman.csv", ios::app);
   out << p.id << ";" << p.username << ";" << p.ruangan << ";"
      << p.hari << ";" << p.jam << ";" << p.alat << ";" << p.lokasi << endl;
   out.close();

   cout << "Peminjaman berhasil disimpan.\n";
   cout << "ID Peminjaman: " << p.id << endl;
}

void alatTambahan() {
   ifstream file("database/Peminjaman.csv");
   if (!file.is_open()) {
      cout << "File Peminjaman.csv tidak ditemukan!\n";
      return;
   }

   string data[200];
   int n = 0;

   while (getline(file, data[n])) {
      n++;
   }
   file.close();

   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   int idInput;
   cout << "Masukkan ID Peminjaman: ";
   cin >> idInput;
   cin.ignore();

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

      if (p.id == idInput) {
            ditemukan = true;

            cout << "\nData Peminjaman:\n";
            cout << "Username : " << p.username << endl;
            cout << "Ruangan  : " << p.ruangan << endl;
            cout << "Lokasi   : " << p.lokasi << endl;
            cout << "Alat lama: " << p.alat << endl;

            string alatBaru;
            cout << "\nMasukkan alat tambahan: ";
            getline(cin, alatBaru);


            if (p.alat == "-" || p.alat.empty()) {
               p.alat = alatBaru;
            } else {
               p.alat = p.alat + ", " + alatBaru;
            }

            data[i] = to_string(p.id) + ";" + p.username + ";" +
               p.ruangan + ";" + p.hari + ";" + p.jam + ";" +
               p.alat + ";" + p.lokasi;

            cout << "Alat tambahan berhasil ditambahkan.\n";
            break;
      }
   }

   if (!ditemukan) {
      cout << "ID peminjaman tidak ditemukan.\n";
      return;
   }

   ofstream out("database/Peminjaman.csv");
   for (int i = 0; i < n; i++) {
      out << data[i] << endl;
   }
   out.close();
}