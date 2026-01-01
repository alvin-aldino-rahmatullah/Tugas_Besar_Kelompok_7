#ifndef SISTEM_H
#define SISTEM_H
#include <string>

using namespace std;

struct User {
    int id;
    string username;
    string password;
    string role;
    string status;
};
struct Peminjaman {
    int id;
    string username;
    string ruangan;
    string hari;
    string jam;
    string alat;
    string lokasi;
};

void login();
void registerUser();
void adminMenu();
void userMenu();
void countdown(int seconds);
void aktivasiUser();
void tampilkanUsers();

void daftarPeminjam();
void viewPeminjam();

void lokasiPeminjaman();
void jadwalPemakaian();
void alatTambahan();

#endif