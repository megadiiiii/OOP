/*
1.	Khai báo lớp hình vuông với thuộc tính: độ dài cạnh.
Khai báo lớp hình chữ nhật kế thừa từ lớp hình vuông và thêm thuộc tính: độ dài cạnh thứ 2.
2.	Xây dựng các phương thức: nhập, xuất, tính chu vi, diện tích hình vuông, hình chữ nhật.
3.	Nhập vào n hình vuông. In ra màn hình hình vuông có diện tích lớn nhất và vị trí của 
hình vuông đó trong danh sách vừa nhập.
*/

#include<iostream>
using namespace std;

class HV {
    protected:
        float a;
    public:
        HV() {}
        HV(float a) {
            this -> a = a;  
        }

        float getPerimeter() {
            return a * 4;
        }

        float getArea() {
            return a * a;
        }

        void Input() {
            cout << "Nhap chieu dai: "; cin >> a;
        }

        void Output() {
            cout << "Chu vi hinh vuong: " << getPerimeter() << endl;
            cout << "Dien tich hinh vuong: " << getArea() << endl;
        }
};

class HCN : public HV {
    private:
        float b;
    public:
        HCN() {}
        HCN(float b) : HV(a) {
            this -> b = b;  
        }

        float getPerimeter() {
            return (a + b) * 2;
        }

        float getArea() {
            return a * b;
        }

        void Input() {
            cout << "Nhap chieu dai: "; cin >> a;
        }

        void Output() {
            cout << "Chu vi hinh vuong: " << getPerimeter() << endl;
            cout << "Dien tich hinh vuong: " << getArea() << endl;
        }
};

void Max_Square(HV DS[], int n) {
    int Max_Id = 0;
    float Max_Area = DS[0].getArea();
    for(int i = 0; i < n; i++) {
        if(DS[i].getArea() > Max_Area) {
            Max_Id = i;
            Max_Area = DS[i].getArea();
        }   
    }
    cout << "Dien tich lon nhat la: " << Max_Area << endl;
    cout << "Hinh vuong " << Max_Id + 1 << " la hinh vuong co dien tich lon nhat" << endl;
}

int main() {
    int n;
    cout << "Nhap so hinh vuong: ";
    cin >> n;
    HV* DS = new HV[n];

    for(int i = 0; i < n; i++) {
        cout << "Nhap hinh vuong thu " << i + 1 << ": " << endl;
        DS[i].Input();
    }

    Max_Square(DS, n);

    delete[] DS;
}