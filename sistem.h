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

struct RoleNode {
    string role;
    int level;
    RoleNode* left;
    RoleNode* right;

    RoleNode(string r, int l);
};

RoleNode* buildRoleTree();
int getRoleLevel(RoleNode* root, const string& role);

void superAdminMenu(const User& currentUser);


void login();
void registerUser();
void adminMenu();
void userMenu();
void countdown(int seconds);
void aktivasiUser();
void tampilkanUsers();

void daftarPeminjam();
void editPeminjaman();
void lokasiPeminjaman();
void alatTambahan();

#endif