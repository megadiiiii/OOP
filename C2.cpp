/*Cau 2: Viet chuong trinh thuc hien cac yeu cau sau:
1.	Khai bao lop da thuc voi cac thuoc tinh: bdt da thuc, cac he so tuong ung.
2.	Xay dung cac phuong thuc: nhap, xuat mot doi tuong da thuc.
    Dinh nghia toan tu +, - hai da thuc. 
    Thuc hien cong, tru hai da thuc va in ket qua ra man hinh.
*/

#include<bits/stdc++.h>
using namespace std;

class Dathuc {
    private:
        int bac, hs[10];
    public:
        void Input() {
            cout << "Nhap bac cua da thuc: ";
            cin >> bac;
            for(int i = 0; i <= bac; i++) {
                cout << "Nhap he so bac " << i << ": ";
                cin >> hs[i];
            }
        }

        void Output() {
            for(int i = bac; i >= 0; i--) {
                cout << hs[i];
                if(i > 0) {
                    cout << "x^" << i << " + ";
                }
            }
            cout << endl;
        }

        Dathuc operator+(Dathuc dt) {
            Dathuc result;
            result.bac = (bac > dt.bac) ? bac : dt.bac;

            for(int i = 0; i <= result.bac; i++) {
                if(i <= bac && i <= dt.bac) {
                    result.hs[i] = hs[i] + dt.hs[i];
                } else if(i <= bac) {
                    result.hs[i] = hs[i];
                }
                else result.hs[i] = dt.hs[i];
            }
            return result;
        }

        Dathuc operator-(Dathuc dt) {
            Dathuc result;
            result.bac = (bac > dt.bac) ? bac : dt.bac;

            for(int i = 0; i <= result.bac; i++) {
                if(i <= bac && i <= dt.bac) {
                    result.hs[i] = hs[i] - dt.hs[i];
                }else if(i <= bac) {
                    result.hs[i] = hs[i];
                }
                else result.hs[i] = dt.hs[i];
            }
            return result;
        }
};

int main() {
    Dathuc dt1, dt2, sum, diff;
    cout << "Nhap da thuc 1:" << endl;
    dt1.Input();
    cout << "Nhap da thuc 2:" << endl;
    dt2.Input();

    dt1.Output();
    dt2.Output();

    sum = dt1 + dt2;
    cout << "Tong 2 da thuc: ";
    sum.Output();

    diff = dt1 - dt2;
    cout << "Hieu 2 da thuc: ";
    diff.Output();
}
