#include "sistem.h"
#include "iostream"
#include <fstream>
#include <sstream>

using namespace std;
string line, temp;

int getLastUserId(){
    ifstream file("database/Users.csv");
    int lastId = 0;

    getline(file, line);

    while (getline(file, line))
    {
        stringstream ss(line);
        getline(ss, temp, ';');
        lastId = stoi(temp);
    }
    return lastId;
}

bool cekUsername(const string &username) {
    ifstream file("database/Users.csv");
    getline(file, line);

    while (getline(file, line))
    {
        stringstream ss(line);
        User user;

        getline(ss, temp, ';');
        getline(ss, user.username, ';');
        if (user.username == username)
        {
            return true;
        }
    }
    return false;
}

void registerUser(){
    string username, password;
    cout << "=== Registrasi User Baru ===" << endl;

    while (true){
        cout << "Username: ";
        cin >> username;
        if (cekUsername(username)){
            cout << "Username sudah digunakan. Silahkan pilih nama lain.\n";
        }
        else{
            break;
        }
    }
    cout << "Password: ";
    cin >> password;

    int newId = getLastUserId() + 1;

    ofstream file("database/Users.csv", ios::app);
    if (!file.is_open()){
        cout << "Gagal membuka database.\n";
        return;
    }

    file << newId << ";" << username << ";" << password << ";user;inactive\n";
    file.close();

    cout << "\nRegistrasi berhasil!\n";
    cout << "Akun menunggu aktivasi admin.\n";
}
