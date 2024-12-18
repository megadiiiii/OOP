/*
Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp SP1 mô tả các đối tượng là số phức với các thuộc tính: phần thực, phần ảo.
Xây dựng hàm tạo, phương thức nhập số phức, in số phức, tính module số phức
2.	Xây dựng lớp SP2 kế thừa từ lớp SP1 và bổ sung:
Nạp chồng các toán tử: = (gán), > (lớn hơn), == (so sánh bằng)
3.	Viết chương trình chính ứng dụng lớp SP2 để nhập một danh sách các đối tượng là các số phức (tối đa 10 phần tử). 
Tìm số phức có giá trị lớn nhất và đếm xem có bao nhiêu số phức trong danh sách có giá trị bằng 3+4i.
*/

#include<iostream>
#include<cmath>
using namespace std;

class SP1 {
    protected:
        float r_part, v_part;
    public:
        SP1 () {}
        SP1 (float r_part, float v_part) {
            this -> r_part = r_part;
            this -> v_part = v_part;
        }

        void Input() {
            cout << "Nhap phan thuc: "; cin >> r_part;
            cout << "Nhap phan ao: "; cin >> v_part;
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
        SP2 () {}
        SP2 (float r_part, float v_part) : SP1(r_part, v_part) {}

        SP2 operator=(SP2 SP) {
            r_part = SP.r_part;
            v_part = SP.v_part;
            return *this;
        }

        int operator>(SP2 SP) {   
            if (Module() > SP.Module()) {
                return 1;
            } else return 0;
        }

        int operator==(SP2 SP) {
            if (r_part == SP.r_part && v_part == SP.v_part) {
                return 1;
            } else return 0;
        }
};

void SP_Max(SP2 DS[], int n) {
    SP2 Max = DS[0];
    for(int i = 0; i < n; i++) {
        if(DS[i] > Max) {
            Max = DS[i];     
        } 
    }
    cout << "So phuc Max: ";
    Max.Output();
}

void SP_Count(SP2 DS[], int n) {
    int Count = 0;
    for(int i = 0; i < n; i++) {
        if(DS[i] == SP2(3, 4)) {
            Count++;     
        } 
    }
    cout << "So so phuc bang 3 + 4i: " << Count << endl;
    }

int main() {
    SP2 DS[10];
    int n;
    do {
        cout << "Nhap so luong so phuc: ";
        cin >> n;
    } while (n > 10 || n < 1);

    for(int i = 0; i < n; i++) {
        cout << "Nhap so phuc " << i + 1 << ": " << endl;
        DS[i].Input();
    }

    SP_Max(DS, n);
    SP_Count(DS, n);
}