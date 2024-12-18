/*Câu 19: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp PS1 cho các đối tượng là phân số với các thuộc tính: TS, MS.
Xây dựng phương thức nhập phân số (mẫu số khác 0),
in phân số, tối giản phân số.
2.	Xây dựng lớp PS2 kế thừa từ lớp PS1 và bổ sung:
Nạp chồng các toán tử: = (gán), < (nhỏ hơn).
3.	Viết chương trình chính ứng dụng lớp PS2 
để nhập một danh sách các đối tượng là các phân số (tối đa 10 phần tử). 
Sắp xếp lại danh sách đã nhập theo trật tự giảm dần
Tìm phân số có giá trị lớn nhất, nhỏ nhất.
Tính tổng các phân số trong danh sách có giá trị nhỏ hơn 1/2.
*/

#include<bits/stdc++.h>
using namespace std;

class PS1 {
    protected:
        int TS, MS;
    public:
        PS1() {
            TS = 0;
            MS = 1;
        }
        PS1(int TS, int MS) {
            this -> TS = TS;
            this -> MS = MS;
        }

        void Input() {
            cout << "Nhap TS: ";
            cin >> TS;
            do {
                cout << "Nhap MS: ";
                cin >> MS;
            } while(MS == 0);            
        }

        void Output() {
            if(MS >= 0) {
                cout << TS << "/" << MS << endl;
            }else cout << -TS << "/" << abs(MS) << endl;
        }

        void TG() {
            int a = abs(TS), b = abs(MS);
            while(a != b) {
                if(a > b) {
                    a -= b;
                } else b -= a;
            }
            TS /= a;
            MS /= b;
        }
};

class PS2 : public PS1 {
    public:
        PS2() {}
        PS2(int TS, int MS) : PS1(TS, MS) {}

        PS2 operator=(PS2 ps) {
            TS = ps.TS;
            MS = ps.MS;
            return *this;
        }

        int operator<(PS2 ps) {
            return TS * ps.MS < ps.TS * MS;
        }

        PS2 operator+(PS2 ps) {
            PS2 Result;
            Result.TS = TS * ps.MS + ps.TS * MS;
            Result.MS = MS * ps.MS;
            Result.TG();
            return Result;
        }
};

void Sort(PS2 DS[], int n) {
    cout << "DS sau sap xep" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(DS[i] < DS[j]) {
                PS2 temp = DS[i];
                DS[i] = DS[j];
                DS[j] = temp;
            }
        }
        DS[i].Output();
    }
}

void Min(PS2 DS[], int n) {
    PS2 Min = DS[0];
    cout << "PS_Min: ";
    for(int i = 0; i < n; i++) {
        if(DS[i] < Min) {
            Min = DS[i];
        }
    }
    Min.Output();
}

void Max(PS2 DS[], int n) {
    PS2 Max = DS[0];
    cout << "PS_Max: ";
    for(int i = 0; i < n; i++) {
        if(Max < DS[i]) {
            Max = DS[i];
        }
    }
    Max.Output();
}

void Sum(PS2 DS[], int n) {
    PS2 Result;
    cout << "Tong cac PS nho hon 1/2: ";
    for(int i = 0; i < n; i++) {
        if(DS[i] < PS2(1, 2)) {
            Result = Result + DS[i];
        } 
    }
    Result.Output();
}

int main() {
    PS2 DS[10];
    int n;
    cout << "Nhap so PS: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "PS " << i + 1 << endl;
        DS[i].Input();
    }

    Sort(DS, n);
    Min(DS, n);
    Max(DS, n);
    Sum(DS, n);
}