#include "sistem.h"
#include <iostream>
#include <string>

using namespace std;

string login() {
    string username, password;

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    if (username == "admin" && password == "admin123") {
        cout << "Login sebagai Admin berhasil." << endl;
        return "admin";
    }
    else if (username == "user" && password == "user123") {
        cout << "Login sebagai User berhasil." << endl;
        return "user";
    }
    else {
        cout << "Login gagal." << endl;
        return "gagal";
    }
}

