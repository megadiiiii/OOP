/*Câu 17: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp điểm với các thuộc tính: tọa độ x, tọa độ y.
Xây dựng các phương thức: nhập, xuất, tính khoảng cách 2 điểm 
(dùng hàm bạn tính độ d)
2.	Khai báo lớp tam giác có thuộc tính 3 đỉnh là kiểu đối tượng điểm (lớp tam giác được gọi là lớp bao của lớp điểm) và thêm các thuộc tính: độ dài 3 cạnh.
Xây dựng các phương thức:; nhập, xuất 3 đỉnh của tam giác.
Tính độ dài 3 cạnh của tam giác
3.	Nhập vào 1 tam giác. Kiểm tra tính chất của tam giác 
(thường, đều, vuông, cân, vuông cân). In kết quả ra màn hình.
*/

#include<bits/stdc++.h>
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
            cout << "Nhap x: ";
            cin >> x;
            cout << "Nhap y: ";
            cin >> y;
        }

        void Output() {
            cout << "(" << x << "," << y << ")";
        }

        friend float Distance(Point a, Point b);
};

float Distance(Point a, Point b) {
    return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
}

class Triangle : public Point {
    private:
        Point A, B, C;
        float AB, BC, AC;
    public:
        Triangle() {}
        Triangle(float x, float y) : Point(x, y) {}

        void Length() {
            AB = Distance(A, B);
            BC = Distance(B, C);
            AC = Distance(A, C);
        }

        void Input() {
            cout << "Nhap dinh A: " << endl;
            A.Input();
            cout << "Nhap dinh B: " << endl;
            B.Input();
            cout << "Nhap dinh C: " << endl;
            C.Input();
        }

        void Output() {
            cout << "Tam giac co toa do: ";
            A.Output();
            B.Output();
            C.Output();
            cout << endl;
        }

        void Check() {
            Length();
            if(AB <= 0 || BC <= 0 || AC <= 0 || AB + BC <= AC || AC + BC <= AB || AC + AB <= BC) {
                cout << "Khong tao thanh tam giac";
            } else if(AB == AC && AC == BC) {
                cout << "Tao thanh tam giac deu";
            } else if(pow(AB, 2) + pow(BC, 2) == pow(AC, 2) || pow(AC, 2) + pow(BC, 2) == pow(AB, 2) || pow(AB, 2) + pow(AC, 2) == pow(BC, 2)) {
                if(AB == AC || AC == BC || BC == AB) {
                    cout << "Tao thanh tam giac vuong can";                    
                }else cout << "Tao thanh tam giac can";
            } else cout << "Tao thanh tam giac thuong";
        }
};

int main() {
    Triangle tg;
    tg.Input();
    tg.Output();
    tg.Check();
}