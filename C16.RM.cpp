/*Câu 16: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp hình vuông với thuộc tính: độ dài cạnh.
Khai báo lớp hình chữ nhật kế thừa từ lớp hình vuông và thêm thuộc tính: độ dài cạnh thứ 2.
2.	Xây dựng các phương thức: nhập, xuất, tính chu vi, diện tích hình vuông, hình chữ nhật.
3.	Nhập vào n hình vuông. In ra màn hình hình vuông có diện tích lớn nhất 
và vị trí của hình vuông đó trong danh sách vừa nhập.
*/

#include<bits/stdc++.h>
using namespace std;

class HV {
    protected:
        float a;
    public:
        HV() {}
        HV(float a) {
            this -> a = a;
        }

        float getArea() {
            return pow(a, 2);
        }

        float getPerimeter() {
            return a * 4;
        }

        void Input() {
            cout << "Nhap canh a: ";
            cin >> a;
        }

        void Output() {
            cout << "Chu vi hinh vuong: " << getPerimeter() << endl;
            cout << "Dien tich hinh vuong: " << getArea() << endl;
        }
};


class HCN : public HV{
    private:
        float b;
    public:
        HCN() {}
        HCN(float b) : HV(a) {
            this -> b = b;
        }

        float getArea() {
            return a * b;
        }

        float getPerimeter() {
            return (a + b) * 2;
        }

        void Input() {
            HV :: Input();
            cout << "Nhap canh b: ";
            cin >> b;
        }

        void Output() {
            cout << "Chu vi HCN: " << getPerimeter() << endl;
            cout << "Dien tich HCN: " << getArea() << endl;
        }
};

void Search(HV* DS, int n) {
    float Max_Area = DS[0].getArea();
    int Max_ID = 0;
    for(int i = 0; i < n; i++) {
        if(DS[i].getArea() > Max_Area) {
            Max_ID = i;
            Max_Area = DS[i].getArea();
        }
    }
    cout << "Hinh vuong " << Max_ID + 1 << " co dien tich lon nhat." << endl;
    cout << "Dien tich hinh vuong " << Max_ID + 1 << ": " << Max_Area;
}

int main() {
    int n;
    cout << "Nhap so hinh vuong: ";
    cin >> n;
    HV* DS = new HV[n];

    for(int i = 0; i < n; i++) {
        cout << "Nhap hinh vuong " << i + 1 << ": " << endl;
        DS[i].Input();
    }

    Search(DS, n);

    delete[] DS;
}