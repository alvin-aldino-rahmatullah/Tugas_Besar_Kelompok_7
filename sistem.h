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

void login();
void registerUser();
void adminMenu();
void userMenu();
void countdown(int seconds);

void daftarPeminjam();
void viewPeminjam();

void lokasiPeminjaman();
void jadwalPemakaian();
void alatTambahan();

#endif