#include "sistem.h"
#include "iostream"
#include "string"
#include "thread"
#include "chrono"
using namespace std;

void countdown(int detik) {
    cout << endl; 
    for (int i = detik; i > 0; --i)
    {
        cout << "Silahkan Tunggu Selama " << i << " Detik..." << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << endl; 
}

string login() {
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

        if (username == "admin" && password == "admin123") {
            cout << "-[Login sebagai Admin berhasil.]-" << endl;
            cout << endl; 
            return "admin";
        }
        else if (username == "user" && password == "user123") {
            cout << "-[Login sebagai User berhasil.]-" << endl;
            cout << endl; 
            return "user";
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
