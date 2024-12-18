/*
Câu 24: 
Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp PS1 cho các đối tượng là phân số với các thuộc tính: tử số, mẫu số.
Xây dựng phương thức nhập phân số (mẫu số khác 0), in phân số, tối giản phân số.
2.	Xây dựng lớp PS2 kế thừa từ lớp PS1 và bổ sung:
Nạp chồng các toán tử: = (gán), > (lớn hơn), + (cộng).
3.	Viết chương trình chính ứng dụng lớp PS2 để nhập một danh sách các đối tượng là các phân số (tối đa 10 phần tử). 
Tìm phân số có giá trị lớn nhất, tính tổng các phân số trong danh sách có giá trị lớn hơn 1/4.

*/

#include<iostream>
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
            cout << "Nhap TS: "; cin >> TS;
            do {
            cout << "Nhap MS: "; cin >> MS;
            } while (MS == 0);
        }

        void Output() {
            cout << TS << "/" << MS << endl;
        }

        void Toigian() {
            int a = abs(TS), b = abs(MS);
            while (a != b) {
                if (a > b) {
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
        }

        int operator>(PS2 ps) {
            return TS * ps.MS > ps.TS * MS;
        }

        PS2 operator+(PS2 ps) {
            PS2 Result;
            Result.TS = TS * ps.MS + ps.TS * MS;
            Result.MS = MS * ps.MS;
            Result.Toigian();
            return Result; 
        }
};

void PS_Max(PS2 DS[], int n) {
    PS2 ps_max = DS[0];
    for(int i = 0; i < n; i++) {
        if(DS[i] > ps_max) {
            ps_max = DS[i];
        }
    }
    cout << "Phan so lon nhat: " << endl;
    ps_max.Output();
}

void SumOver(PS2 DS[], int n) {
    PS2 sum;
    for(int i = 0; i < n; i++) {
        if(DS[i] > PS2(1,4)) {
            sum = sum + DS[i];
        }
    }
    cout << "Tong cac phan so lon hon 1/4 la: ";
    sum.Output();
}

int main() {
    PS2 DS[10];

    int n;
    do {
        cout << "Nhap so luong phan so (toi da 10): ";
        cin >> n;
    } while (n > 10 || n < 1);

    for(int i = 0; i < n; i++) {
        cout << "Nhap phan so thu " << i + 1 << ": " << endl;
        DS[i].Input();
    }

    for(int i = 0; i < n; i++) {
        DS[i].Output();
    }

    PS_Max(DS, n);
    SumOver(DS, n);
}