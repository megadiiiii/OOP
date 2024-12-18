/*Câu 18: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp PS1 cho các đối tượng là phân số với các thuộc tính: tử số, mẫu số.
Xây dựng phương thức nhập phân số (mẫu số khác 0), 
in phân số, tối giản phân số.
2.	Xây dựng lớp PS2 kế thừa từ lớp PS1 và bổ sung:
Nạp chồng các toán tử: = (gán), > (lớn hơn).
3.	Viết chương trình chính ứng dụng lớp PS2 
để nhập một danh sách các đối tượng là phân số (tối đa 10 phần tử). 
Sắp xếp lại danh sách đã nhập theo trật tự giảm dần.
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
            cout << TS << "/" << MS << endl;
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

            if(MS < 0) {
                TS = -TS;
                MS = -MS;
            }
        }


};

class PS2 : public PS1 {
    public:
        PS2() {}
        PS2(int TS, int MS) : PS1(TS, MS){}

        PS2 operator=(PS2 ps) {
            TS = ps.TS;
            MS = ps.MS;
            return *this;
        }

        int operator>(PS2 ps) {
            return TS * ps.MS > ps.TS * MS;
        }
};

void Sort(PS2* DS, int n) {
    for(int i = 0; i < n; i++) {    
        for(int j = i + 1; j < n; j++) {
            if(DS[j] > DS[i]) {
                PS2 temp = DS[i];
                DS[i] = DS[j];
                DS[j] = temp;
            }            
        }
        DS[i].Output();
    }
}

int main() {
    int n;
    do {
        cout << "Nhap so PS: ";
        cin >> n;
    } while(n > 10 || n < 1);

    PS2* DS = new PS2[n];
    for(int i = 0; i < n; i++) {
        cout << "PS " << i + 1 << ": " << endl;
        DS[i].Input();
    }

    Sort(DS, n);
    delete[] DS;
}