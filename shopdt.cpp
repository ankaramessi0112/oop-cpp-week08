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

struct Shop {
    string shopName;
    string shopAddress;
    Mobile mobiles[100];
    int mobileCount = 0;
    Order orders[100];
    int orderCount = 0;

    Shop(string name = "Shop DTDD", string addr = "Thu Duc") {
        shopName = name;
        shopAddress = addr;
    }

    // Them dien thoai
    void addMobile() {
        if (mobileCount >= 100) return;
        Mobile m;
        m.input();
        mobiles[mobileCount++] = m;
    }

    // Xoa dien thoai theo ID
    void removeMobile(string id) {
        int idx = -1;
        for (int i = 0; i < mobileCount; i++) {
            if (mobiles[i].id == id) {
                idx = i;
                break;
            }
        }
        if (idx == -1) return;
        for (int i = idx; i < mobileCount - 1; i++) {
            mobiles[i] = mobiles[i + 1];
        }
        mobileCount--;
    }

    // Tao moi 1 order
    void createOrder() {
        if (orderCount >= 100) return;
        Order ord;
        ord.input();
        
        cout << "Nhap ID DT muon mua vao don: ";
        string idM;
        getline(cin, idM);
        for (int i = 0; i < mobileCount; i++) {
            if (mobiles[i].id == idM) {
                ord.items[ord.itemCount++] = mobiles[i];
                break;
            }
        }
        orders[orderCount++] = ord;
    }

    // Chinh sua order
    void editOrder(string idOrder) {
        for (int i = 0; i < orderCount; i++) {
            if (orders[i].idOrder == idOrder) {
                cout << "Nhap dia chi moi: ";
                getline(cin, orders[i].customerAddress);
                cout << "Nhap trang thai moi (1: Da TT, 0: Chua TT): ";
                int st;
                cin >> st;
                orders[i].paymentStatus = (st == 1);
                cin.ignore();
                return;
            }
        }
    }

    // Thong ke theo thang
    void statisticOrdersByMonth(int m, int y) {
        int total = 0;
        for (int i = 0; i < orderCount; i++) {
            if (orders[i].month == m && orders[i].year == y) {
                orders[i].output();
                total++;
            }
        }
        cout << "Tong so don thang " << m << "/" << y << ": " << total << endl;
    }
};


int main() {
    Shop shop;
    cout << "--- 1. Them DT ---\n";
    shop.addMobile();
    
    cout << "--- 2. Tao Don ---\n";
    shop.createOrder();
    
    cout << "--- 3. Thong ke ---\n";
    shop.statisticOrdersByMonth(9, 2026);
    
    return 0;
}