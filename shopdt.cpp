#include <iostream>
#include <string>

using namespace std;

// Struct quan ly thong tin dien thoai
struct Mobile {
    string id;
    string brand;
    string version;
    string seriesId;
    int year;

    void input() {
        cout << "Nhap ID DT: ";
        getline(cin, id);
        cout << "Nhap hang (Brand): ";
        getline(cin, brand);
        cout << "Nhap phien ban (Version): ";
        getline(cin, version);
        cout << "Nhap Series ID: ";
        getline(cin, seriesId);
        cout << "Nhap nam san xuat: ";
        cin >> year;
        cin.ignore();
    }

    void output() const {
        cout << "[ID: " << id << " | Hang: " << brand << " | Ban: " << version 
             << " | Series: " << seriesId << " | Nam: " << year << "]\n";
    }
};

// Struct quan ly don hang
struct Order {
    string idOrder;
    string idCustomer;
    string customerAddress;
    Mobile items[20];
    int itemCount = 0;
    int month;
    int year;
    bool paymentStatus;

    void input() {
        cout << "Nhap ID don hang: ";
        getline(cin, idOrder);
        cout << "Nhap ID khach hang: ";
        getline(cin, idCustomer);
        cout << "Nhap dia chi: ";
        getline(cin, customerAddress);
        cout << "Nhap thang dat (1-12): ";
        cin >> month;
        cout << "Nhap nam dat: ";
        cin >> year;
        cout << "Trang thai thanh toan (1: Da TT, 0: Chua TT): ";
        int st;
        cin >> st;
        paymentStatus = (st == 1);
        cin.ignore();
    }

    void output() const {
        cout << "Don hang " << idOrder << " - KH: " << idCustomer 
             << " - " << (paymentStatus ? "Da TT" : "Chua TT") << "\n";
    }
};

int main() {
    return 0;
}