#include "sistem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include <iomanip>

using namespace std;

RoleNode::RoleNode(string r, int l)
    : role(r), level(l), left(nullptr), right(nullptr) {}

RoleNode* insertRole(RoleNode* root, const string& role, int level) {
    if (!root) return new RoleNode(role, level);
    if (level < root->level)
        root->left = insertRole(root->left, role, level);
    else
        root->right = insertRole(root->right, role, level);
    return root;
}

int getRoleLevel(RoleNode* root, const string& role) {
    if (!root) return -1;
    if (root->role == role) return root->level;

    int kiri = getRoleLevel(root->left, role);
    if (kiri != -1) return kiri;
    return getRoleLevel(root->right, role);
}


vector<User> loadUsers() {
    vector<User> users;
    ifstream file("database/Users.csv");

    if (!file.is_open()) {
        cout << "Database user tidak ditemukan.\n";
        return users;
    }

    string line;
    getline(file, line); 

    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        User user;
        string temp;

        getline(ss, temp, ';');
        user.id = stoi(temp);

        getline(ss, user.username, ';');
        getline(ss, user.password, ';');
        getline(ss, user.role, ';');
        getline(ss, user.status);

        users.push_back(user);
    }
    return users;
}

void saveUsers(const vector<User>& users) {
    ofstream file("database/Users.csv", ios::trunc);
    file << "id;username;password;role;status\n";
    for (const auto& u : users) {
        file << u.id << ";" << u.username << ";"
             << u.password << ";" << u.role
             << ";" << u.status << "\n";
    }
}

void tampilkanUser() {
    auto users = loadUsers();

    cout << "\n=============== DAFTAR USER ===============\n";
    cout << left
     << setw(5)  << "ID"
     << setw(15) << "Username"
     << setw(15) << "Role"
     << setw(10) << "Status" << endl;
    for (const auto& u : users) {
        cout << left
            << setw(5)  << u.id
            << setw(15) << u.username
            << setw(15) << u.role
            << setw(10) << u.status << endl;
    }
}

void ubahStatusUser() {
    auto users = loadUsers();
    int id;
    cout << "ID user: ";
    cin >> id;

    for (auto& u : users) {
        if (u.id == id) {
            u.status = (u.status == "active") ? "inactive" : "active";
            saveUsers(users);
            cout << "Status berhasil diubah.\n";
            return;
        }
    }
    cout << "User tidak ditemukan.\n";
}

void jadikanAdmin() {
    auto users = loadUsers();
    int id;
    cout << "ID user: ";
    cin >> id;

    for (auto& u : users) {
        if (u.id == id) {
            u.role = "admin";
            saveUsers(users);
            cout << "User sekarang admin.\n";
            return;
        }
    }
    cout << "User tidak ditemukan.\n";
}

void hapusUser() {
    auto users = loadUsers();
    int id;
    cout << "ID user: ";
    cin >> id;

    vector<User> hasil;
    bool ketemu = false;

    for (auto& u : users) {
        if (u.id != id)
            hasil.push_back(u);
        else
            ketemu = true;
    }

    if (!ketemu) {
        cout << "User tidak ditemukan.\n";
        return;
    }

    saveUsers(hasil);
    cout << "User berhasil dihapus.\n";
}


void superAdminMenu(const User& currentUser) {
    RoleNode* root = nullptr;
    root = insertRole(root, "user", 0);
    root = insertRole(root, "admin", 1);
    root = insertRole(root, "superadmin", 2);

    if (getRoleLevel(root, currentUser.role) < 2) {
        cout << "Akses ditolak. Bukan Super Admin.\n";
        return;
    }

    int pilih;
    do {
        cout << "=============================" << endl;
        cout << " SELAMAT DATANG SUPER ADMIN " << endl;
        cout << "=============================" << endl;
        cout << "1. Lihat user\n";
        cout << "2. Aktif / Nonaktif user\n";
        cout << "3. Jadikan admin\n";
        cout << "4. Hapus user\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1: tampilkanUser(); break;
            case 2: ubahStatusUser(); break;
            case 3: jadikanAdmin(); break;
            case 4: hapusUser(); break;
            case 0: cout << "Keluar...\n"; break;
            default: cout << "Menu tidak valid.\n";
        }
    } while (pilih != 0);
}
