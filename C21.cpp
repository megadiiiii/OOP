/*
Cau 22: 
Viet chuong trinh thuc hien cac yeu cau sau:
1.	Khai bao lop SP1 cho cac doi tuong la so phuc voi cac thuoc tinh: phan thuc, phan ao.
Xay dung ham tao, phuong thuc nhap so phuc, in so phuc, tinh module so phuc.
2.	Xay dung lop SP2 ke thua tu lop SP1 va bo sung:
Nap chong cac toan tu = (gan), < (so sanh nho hon theo module)
3.	Viet chuong trinh chinh ung dung lop SP2 de nhap mot danh sach cac doi tuong la cac so phuc (toi da 10 phan tu). 
Tim so phuc co gia tri lon nhat, nho nhat.
*/

#include<iostream>
#include<cmath>
using namespace std;

class SP1 {
    protected:
        float r_part;
        float v_part;
        
    public:
        SP1() {}
        SP1(float r_part, float v_part) {
            this -> r_part = r_part;
            this -> v_part = v_part;
        }

        void Input() {
            cout << "Nhap phan thuc: ";
            cin >> r_part;
            cout << "Nhap phan ao: ";
            cin >> v_part;
        }


        void Output() {
            if(v_part >= 0) {
                cout << r_part << "+" << v_part << "i" << endl;
            } else cout << r_part << "-" << abs(v_part) << "i" << endl;
        }

        float Module() {
            return sqrt(pow(r_part, 2) + pow(v_part, 2));
        }
};

class SP2 : public SP1 {
    public:
        SP2() {}
        SP2(float r_part, float v_part) : SP1(r_part, v_part) {}

        SP2 operator=(SP2 sp) {
            r_part = sp.r_part;
            v_part = sp.v_part;
        }

        int operator<(SP2 sp) {
            if(Module() < sp.Module()) {
                return 1;
            } else return 0;
        }
};

int main() {
    SP2 DS[10];

    int n;

    do {
        cout << "Nhap so luong so phuc (toi da 10): ";
        cin >> n;
    } while (n < 1 || n > 10);

    for(int i = 0; i < n; i++) {
        cout << "Nhap so phuc thu " << i + 1 << ": " << endl;
        DS[i].Input();
    }

    SP2 Module_min = DS[0];
    SP2 Module_max = DS[0];

    for(int i = 0; i < n; i++) {
        if(DS[i] > Module_max) {
            Module_max = DS[i];
        }

        if(DS[i] < Module_min) {
            Module_min = DS[i];
        }
    }

    cout << "So phuc Max: " << Module_max.Output() << endl;
    cout << "So phuc Min: " << Module_min.Output() << endl;
}