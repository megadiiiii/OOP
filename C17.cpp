/*
Câu 17: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp điểm với các thuộc tính: tọa độ x, tọa độ y.
Xây dựng các phương thức: nhập, xuất, tính khoảng cách 2 điểm (dùng hàm bạn tính độ d)
2.	Khai báo lớp tam giác có thuộc tính 3 đỉnh là kiểu đối tượng điểm (lớp tam giác được gọi là lớp bao của lớp điểm) 
và thêm các thuộc tính: độ dài 3 cạnh.
Xây dựng các phương thức:; nhập, xuất 3 đỉnh của tam giác., tính độ dài 3 cạnh của tam giác
3.	Nhập vào 1 tam giác. Kiểm tra tính chất của tam giác (thường, đều, vuông, cân, vuông cân). 
In kết quả ra màn hình.
*/

#include<iostream>
#include<cmath>
using namespace std;

class Point {
    protected:
        float x, y;
    public:
        Point() {}
        Point(float x, float y) {
            this -> x = x;
            this -> y = y;
        }

        void Input() {
            cout << "Nhap toa do x: "; cin >> x;
            cout << "Nhap toa do y: "; cin >> y;
        }

        void Output() {
            cout << "(" << x << "," << y << ")";
        }

        friend float Distance(Point a, Point b);
};

float Distance(Point a, Point b) {
    return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
}

class Triangle {
    private: 
        Point A, B, C;
        float AB, AC, BC;
    public:
        void Input() {
            cout << "Nhap toa do dinh A: " << endl;
            A.Input();
            cout << "Nhap toa do dinh B: " << endl;
            B.Input();
            cout << "Nhap toa do dinh C: " << endl;
            C.Input();
        }

        void Length() {
            AB = Distance(A, B);
            BC = Distance(B, C);
            AC = Distance(A, C);
        }

        void Output() {
            Length();
            cout << "Tam giac co 3 dinh:" << endl;
            A.Output();
            B.Output();
            C.Output();
            cout << endl;
        }


};



int main() {
    Triangle tg;
    tg.Input();
    tg.Output();
}