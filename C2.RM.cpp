/

#include<bits/stdc++.h>
using namespace std;

class Dathuc {
    private:
        int bac, hs[10];
    public:
        void Input() {
            cout << "Nhap bac da thuc: ";
            cin >> bac;
            for(int i = 0; i <= bac; i++) {
                cout << "Nhap he so " << i << ": ";
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
            Dathuc Result;
            Result.bac = (bac > dt.bac) ? bac : dt.bac;

            for(int i = 0; i <= Result.bac; i++) {
                if(i <= bac && i <= dt.bac) {
                    Result.hs[i] = hs[i] + dt.hs[i];
                } else if(i <= bac) {
                    Result.hs[i] = hs[i];
                } else Result.hs[i] = dt.hs[i];
            }
            return Result;
        }

        Dathuc operator-(Dathuc dt) {
            Dathuc Result;
            Result.bac = (bac > dt.bac) ? bac : dt.bac;


            for(int i = 0; i <= Result.bac; i++) {
                if(i <= bac && i <= dt.bac) {
                    Result.hs[i] = hs[i] - dt.hs[i];                    
                } else if(i <= bac) {                    
                    Result.hs[i] = hs[i];                    
                }else Result.hs[i] = dt.hs[i];
            }
            return Result;
        }
};

int main() {
    Dathuc dt1, dt2, sum, diff;
    cout << "Nhap da thuc 1: " << endl;
    dt1.Input();
    cout << "Nhap da thuc 2: " << endl;
    dt2.Input();

    dt1.Output();
    dt2.Output();

    sum = dt1 + dt2;
    sum.Output();

    diff = dt1 - dt2;
    diff.Output();
}