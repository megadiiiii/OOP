/*
Câu 25: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp SP1 mô tả các đối tượng là số phức với các thuộc tính: phần thực, phần ảo.
Xây dựng hàm tạo, phương thức nhập số phức, in số phức, tính module số phức
2.	Xây dựng lớp SP2 kế thừa từ lớp SP1 và bổ sung:
Nạp chồng các toán tử: = (gán), < (nhỏ hơn), + (cộng)
3.	Viết chương trình chính ứng dụng lớp SP2 để nhập một danh sách các đối tượng là các số phức (tối đa 10 phần tử).
Tìm số phức có giá trị nhỏ nhất (theo module) và tính tổng các số phức trong dãy số.
*/

#include<iostream>
#include<cmath>
using namespace std;

class SP1 {
    protected:
        float r_part, v_part;
    public:
        SP1() {
            r_part = 0;
            v_part = 0;
        }
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
                cout << r_part << " + " << v_part << "i" << endl; 
            }else cout << r_part << " - " << v_part << "i" << endl;
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
            return Module() < sp.Module();        
        }

        SP2 operator+(SP2 sp) {
            SP2 Result;
            Result.r_part = r_part + sp.r_part;
            Result.v_part = v_part + sp.v_part;
            return Result;
        }
};

void Min_SP (SP2 DS[], int n) {
    SP2 Min = DS[0];
    for(int i = 0; i < n; i++) {
        if(DS[i] < Min) {
            Min = DS[i];
        }
    }
    cout << "Min_SP = ";
    Min.Output();
}

void Sum_SP(SP2 DS[], int n) {
    SP2 Sum;
    for(int i = 0; i < n; i++) {
        Sum = Sum + DS[i];
    }
    cout << "Sum_SP = ";
    Sum.Output();
}

int main() {
    SP2 DS[10];
    int n;
    cout << "Nhap so so phuc: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Nhap SP " << i + 1 << ":" << endl;
        DS[i].Input();
    }

    Min_SP(DS, n);
    Sum_SP(DS, n);
}