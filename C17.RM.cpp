/* Cau 17: Viet chuong trinh thuc hien cac yeu cau sau:
1.	Khai bao lop diem voi cac thuoc tinh: toa do x, toa do y.
Xay dung cac phuong thuc: nhap, xuat
Tinh khoang cach 2 diem (dung ham ban tinh do dai)
2.	Khai bao lop tam giac co thuoc tinh 3 dinh la kieu doi tuong diem 
(lop tam giac duoc goi la lop bao cua lop diem) va them cac thuoc tinh: do dai 3 canh.
Xay dung cac phuong thuc:; nhap, xuat 3 dinh cua tam giac.
Tinh do dai 3 canh cua tam giac
3.	Nhap vao 1 tam giac. 
Kiem tra tinh chat cua tam giac (thuong, deu, vuong, can, vuong can). 
In ket qua ra man hinh.
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
            cout << "Nhap x: "; cin >> x;
            cout << "Nhap y: "; cin >> y;
        }

        void Output() {
            cout << "(" << x << "," << y << ")";
        }

        friend float Distance(Point a, Point b);
};
float Distance(Point a, Point b) {
    return sqrt(pow((b.x - a.x),2) + pow((b.y - a.y),2));
}

class Triangle : public Point {
    private:
        Point A, B, C;
        float AB, AC, BC;
    public: 
        void Input() {
            cout << "Nhap dinh A:" << endl;
            A.Input(); 
            cout << "Nhap dinh B:" << endl;
            B.Input(); 
            cout << "Nhap dinh C:" << endl;
            C.Input(); 
        }

        void Length() {
            AB = Distance(A, B);
            AC = Distance(A, C);
            BC = Distance(B, C);
        }

        void Output() {
            Length();
            cout << "Tam giac co 3 dinh: " << endl;
            A.Output();
            B.Output();
            C.Output();
            cout << endl;
            cout << "AB = " << AB << endl;
            cout << "AC = " << AC << endl;
            cout << "BC = " << BC << endl;
        }

        void Check() {
            Length();
            if(AB <= 0 || AC <= 0 || BC <= 0 || AB + AC <= BC || AB + BC <= AC || AC + BC <= AC) {
                cout << "Khong tao thanh tam giac";
            } else if (AB == AC == BC) {
                cout << "Tao thanh tam giac deu";
            } else if (AB == AC || AC == BC || AB == BC) {
                cout << "Tao thanh tam giac can";
            } else if (pow(AB, 2) + pow(AC, 2) == pow(BC, 2) || pow(AB, 2) + pow(BC, 2) == pow(AC, 2) || pow(BC, 2) + pow(AC, 2) == pow(AB, 2)) {
                if(AB == AC || AC == BC || AB == BC) {
                    cout << "Tao thanh tam giac vuong can";
                } else cout << "Tao thanh tam giac vuong";
            } else cout << "Tao thanh tam giac thuong";
        }
};



int main () {
    Triangle tg;
    tg.Input();
    tg.Output();
    tg.Check();
}

