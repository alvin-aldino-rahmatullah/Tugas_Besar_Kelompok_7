#include "sistem.h"
#include "iostream"
#include "string"
#include "thread"
#include "chrono"
#include "fstream"
#include "sstream"

using namespace std;

bool authenticateUser(
    const string& inputUsername,
    const string& inputPassword,
    User& currentUser
) {
    ifstream file("database/Users.csv");
    if (!file.is_open()) {
        cout << "Gagal membuka database user.\n";
        return false;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream stream(line);
        string temp;

        User user;

        getline(stream, temp, ';');
        user.id = stoi(temp);

        getline(stream, user.username, ';');
        getline(stream, user.password, ';');
        getline(stream, user.role, ';');
        getline(stream, user.status, ';');

        user.username.erase(
            user.username.find_last_not_of(" \n\r\t") + 1
        );

        if (user.username == inputUsername &&
            user.password == inputPassword) {

            if (user.status != "active") {
                cout << "Akun belum aktif, hubungi admin.\n";
                return false;
            }

            currentUser = user;
            return true;
        }
    }
    return false;
}


void countdown(int detik) {
    cout << endl; 
    for (int i = detik; i > 0; --i)
    {
        cout << "Silahkan Tunggu Selama " << i << " Detik..." << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << endl; 
}


void login() {
    User currentUser;
    string username, password;
    int percobaan = 0;
    const int maksimal = 3;
    const int berhenti = 10;

    while (true) {
        cout << endl; 
        cout << "Username: ";
        cin >> username;

        cout << "Password: ";
        cin >> password;

        if (authenticateUser(username, password, currentUser)) {
            cout << "Login berhasil sebagai " << currentUser.role << endl;
            if (currentUser.role == "admin") {
                adminMenu();
            } else if (currentUser.role == "user") {
                userMenu();
            } else if (currentUser.role == "superadmin") {
                superAdminMenu(currentUser);
            }
        }
        else {
            percobaan++;
            cout << "-[login gagal! percobaan ke " << percobaan << "]-" << endl;

            if (percobaan == maksimal) {
                cout << endl; 
                cout << "--TERLALU BANYAK PERCOBAAN GAGAL--" << endl;
                cout << "--AKSES LOGIN DIBLOKIR SEMENTARA--" << endl;

                countdown(berhenti);
                percobaan = 0;
                cout << "--SILAHKAN MENCOBA LOGIN KEMBALI--" << endl;
            }
        }
    }
}
