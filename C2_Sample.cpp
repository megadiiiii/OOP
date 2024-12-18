/*Cau 2: Viet chuong trinh thuc hien cac yeu cau sau:
1.	Khai bao lop da thuc voi cac thuoc tinh: bdt da thuc, cac he so tuong ung.
2.	Xay dung cac phuong thuc: nhap, xuat mot doi tuong da thuc.
    Dinh nghia toan tu +, - hai da thuc. Thuc hien cong, tru hai da thuc va in ket qua ra man hinh.
*/

#include<bits/stdc++.h>
using namespace std;

class Dathuc {
    private:
        int bdt, hs[10];
    public:
        void Input() {
            cout << "Nhap bac da thuc: "; cin >> bdt;
            for(int i = 0; i <= bdt; i++) {
                cout << "Nhap he so: ";
                cin >> hs[i];
            }
        }

        void Output() {
            for(int i = bdt; i >= 0; i--) {
                cout << hs[i];
                if(i > 0) {
                    cout << "x^" << i << " + ";
                }
            }
            cout << endl;
        }

        Dathuc operator+(Dathuc dt) {
            Dathuc result;
            if(bdt > dt.bdt) {
                result.bdt = bdt;                
            } else result.bdt = dt.bdt;

            for (int i = 0; i <= result.bdt; i++) {
                if (i <= bdt && i <= dt.bdt){
                    result.hs[i] = hs[i] + dt.hs[i];
                } else if (i <= bdt) {
                    result.hs[i] = hs[i];                    
                } else result.hs[i] = dt.hs[i];
            }
            return result;
        }

        Dathuc operator-(Dathuc dt) {
            Dathuc result;
            if(bdt > dt.bdt) {
                result.bdt = bdt;                
            } else result.bdt = dt.bdt;

            for (int i = 0; i <= result.bdt; i++) {
                if (i <= bdt && i <= dt.bdt){
                    result.hs[i] = hs[i] - dt.hs[i];
                } else if (i <= bdt) {
                    result.hs[i] = hs[i];                    
                } else result.hs[i] = dt.hs[i];
            }
            return result;
        }
};

int main() {
    Dathuc dt1, dt2, sum, diff;

    cout << "Nhap da thuc thu nhat:\n";
    dt1.Input();
    cout << "Da thuc thu nhat: ";
    dt1.Output();

    cout << "Nhap da thuc thu hai:\n";
    dt2.Input();
    cout << "Da thuc thu hai: ";
    dt2.Output();

    sum = dt1 + dt2;
    cout << "Tong hai da thuc: ";
    sum.Output();

    diff = dt1 - dt2;
    cout << "Hieu hai da thuc: ";
    diff.Output();
}