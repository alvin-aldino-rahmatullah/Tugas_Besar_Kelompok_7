#include "sistem.h"
#include "iostream"
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

void tampilkanUsers(){
    ifstream file("database/Users.csv");
    string line, temp;

    if (!file.is_open()) {
        cout << "Gagal membuka database user.\n";
        return;
    }

    getline(file, line);

    cout << "\n=============== DAFTAR USER ===============\n";
    cout << left
     << setw(5)  << "ID"
     << setw(15) << "Username"
     << setw(15) << "Role"
     << setw(10) << "Status" << endl;

    while (getline(file, line)){
        stringstream ss(line);
        User user;

        getline(ss, temp, ';');
        user.id = stoi(temp);
        getline(ss, user.username, ';');
        getline(ss, user.password, ';');
        getline(ss, user.role, ';');
        getline(ss, user.status, ';');

        cout << left
            << setw(5)  << user.id
            << setw(15) << user.username
            << setw(15) << user.role
            << setw(10) << user.status << endl;
    }
    file.close();
}

void aktivasiUser() {
    vector<User> daftarUser;
    ifstream file("database/Users.csv");
    string line, temp;

    if (!file.is_open()) {
        cout << "Gagal membuka database user.\n";
        return;
    }

    getline(file, line); 

    while (getline(file, line)) {
        stringstream ss(line);
        User user;

        getline(ss, temp, ';');
        user.id = stoi(temp);
        getline(ss, user.username, ';');
        getline(ss, user.password, ';');
        getline(ss, user.role, ';');
        getline(ss, user.status, ';');

        daftarUser.push_back(user);
    }

    file.close();

    tampilkanUsers();

    int idDipilih;
    cout << "\nMasukkan ID User: ";
    cin >> idDipilih;

    bool ditemukan = false;

    for (auto &user : daftarUser) {
        if (user.id == idDipilih) {
            ditemukan = true;

            if (user.role == "admin" || user.role == "superadmin") {
                cout << "Admin tidak boleh mengubah status admin lain.\n";
                return;
            }

            cout << "Status saat ini: " << user.status << endl;
            cout << "Ubah status menjadi (active/inactive): ";
            cin >> user.status;
            if (user.status != "active" && user.status != "inactive") {
                cout << "Status tidak valid. Gunakan 'active' atau 'inactive'.\n";
                return;
            }
            break;
        }
    }

    if (!ditemukan) {
        cout << "User tidak ditemukan.\n";
        return;
    }

    ofstream outFile("database/Users.csv");
    outFile << "id;username;password;role;status\n";

    for (const auto &user : daftarUser) {
        outFile << user.id << ";"
                << user.username << ";"
                << user.password << ";"
                << user.role << ";"
                << user.status << "\n";
    }

    outFile.close();

    cout << "\nStatus user berhasil diperbarui.\n";
}

