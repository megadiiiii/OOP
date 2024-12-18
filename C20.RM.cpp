/*C20:
1.	Khai báo lớp SP1 cho các đối tượng là số phức với các thuộc tính: 
phần thực, phần ảo.
Xây dựng hàm tạo, phương thức nhập số phức, in số phức, tính modulec.
2.	Xây dựng lớp SP2 kế thừa từ lớp SP1 và bổ sung:
Nạp chồng các toán tử: = (gán), > (so sánh lớn hơn theo module).
3.	Viết chương trình chính ứng dụng lớp SP2 để nhập một danh sách các đối tượng là các số phức (tối đa 10 phần tử). 
Sắp xếp lại danh sách đã nhập theo trật tự giảm dần của module.
Tìm số phức có giá trị lớn nhất, nhỏ nhất.
Đếm số số phức trong danh sách có giá trị bằng 3+4i.
*/

#include<bits/stdc++.h>
using namespace std;

class SP1 {
    protected:
        int r_part, v_part;
    public:
        SP1() {
            r_part = 0;
            v_part = 0;
        }
        SP1(int r_part, int v_part) {
            this -> r_part = r_part;
            this -> v_part = v_part;
        }

        void Input() {
            cout << "Nhap phan thuc: ";
            cin >> r_part;
            cout << "Nhap phan thuc: ";
            cin >> v_part;
        }

        void Output() {
            if(v_part >= 0) {
                cout << r_part << " + " << v_part << "i" << endl;                  
            } else cout << r_part << " - " << abs(v_part) << "i" << endl;
        }

        float Module() {
            return sqrt(pow(r_part, 2) + pow(v_part, 2));
        }
};

class SP2 : public SP1 {
    public: 
        SP2() {};
        SP2(int r_part, int v_part) : SP1(r_part, v_part) {}

        SP2 operator=(SP2 sp) {
            r_part = sp.r_part;
            v_part = sp.v_part;
            return *this;
        }

        int operator==(SP2 sp) {
            if(r_part == sp.r_part && v_part == sp.v_part) {
                return 1;
            } else return 0;
        }

        int operator>(SP2 sp) {
            return Module() > sp.Module();
        }

};

void Sort(SP2 DS[], int n) {
    cout << "Danh sach SP sau sap xep" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(DS[j] > DS[i]) {
                SP2 temp = DS[i];
                DS[i] = DS[j];
                DS[j] = temp;
            }
        }
        DS[i].Output();
    }
}

void Min(SP2 DS[], int n) {
    SP2 Min = DS[0];
    for(int i = 0; i < n; i++) {
        if(Min > DS[i]) {
            Min = DS[i];
        }
    }
    cout << "SP_Min: ";
    Min.Output();
}

void Max(SP2 DS[], int n) {
    SP2 Max = DS[0];
    for(int i = 0; i < n; i++) {
        if(DS[i] > Max) {
            Max = DS[i];
        }
    }
    cout << "SP_Max: ";
    Max.Output();
}

void Count(SP2 DS[], int n) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(DS[i] == SP2(3, 4)) {
            cnt++;
        }
    }    
    cout << "Co " << cnt << " SP bang 3 + 4i";
}

int main() {
    int n;
    cout << "Nhap so SP: ";
    cin >> n;

    SP2 DS[10];

    for(int i = 0; i < n; i++) {
        cout << "SP " << i + 1 << endl;
        DS[i].Input();
    }

    Sort(DS, n);
    Min(DS, n);
    Max(DS, n);
    Count(DS, n);
}