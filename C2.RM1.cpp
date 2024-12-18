/*Cau 2: Viet chuong trinh thuc hien cac yeu cau sau:
1.	Khai bao lop da thuc voi cac thuoc tinh: bdt da thuc, cac he so tuong ung.
2.	Xay dung cac phuong thuc: nhap, xuat mot doi tuong da thuc.
    Dinh nghia toan tu +, - hai da thuc. Thuc hien cong, tru hai da thuc va in ket qua ra man hinh.
*/

#include<bits/stdc++.h>
using namespace std;

class Poly {
    private:
        int bac, hs[10];
    public: 
        void Input() {
            cout << "Nhap bac: "; cin >> bac;
            for(int i = 0; i <= bac; i++) {
                cout << "Nhap he so bac " << i << ": ";
                cin >> hs[i];
            }
        }

        void Output() {
            for(int i = bac; i >= 0; i--) {
                if(hs[i] >= 0) {                   
                    cout << hs[i] << "x^" << i ;
                } else cout << "(" << hs[i] << "x" << ")" << "^" << i;
                if(i > 0) {
                    cout << " + ";
                }
            }
            cout << endl;
        }

        Poly operator+(Poly pl) {
            Poly Result;
            Result.bac = (bac > pl.bac) ? bac : pl.bac;

            for(int i = 0; i <= Result.bac; i++) {
                if(i <= bac && i <= pl.bac) {
                    Result.hs[i] = hs[i] + pl.hs[i];
                } else if(i <= bac) {
                    Result.hs[i] = hs[i];                    
                } else Result.hs[i] = pl.hs[i];
            }
            return Result;
        }

        Poly operator-(Poly pl) {
            Poly Result;
            Result.bac = (bac > pl.bac) ? bac : pl.bac;

            for(int i = 0; i <= Result.bac; i++) {
                if(i <= bac && i <= pl.bac) {
                    Result.hs[i] = hs[i] - pl.hs[i];
                } else if(i <= bac) {
                    Result.hs[i] = hs[i];
                } else Result.hs[i] = pl.hs[i];

            }
            return Result;
        }
};

int main() {
    Poly PL1, PL2, sum, diff;
    cout << "Nhap da thuc 1:" << endl;
    PL1.Input();
    cout << "Nhap da thuc 2:" << endl;
    PL2.Input();
    
    PL1.Output();
    PL2.Output();

    sum = PL1 + PL2;
    cout << "Tong 2 da thuc: ";
    sum.Output();

    diff = PL1 - PL2;
    cout << "Hieu 2 da thuc: ";
    diff.Output();
}