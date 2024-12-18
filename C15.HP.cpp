/*Câu 15: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp cán bộ với các thuộc tính: 
mã cán bộ, mã đơn vị, họ tên, năm sinh.
Khai báo lớp lương kế thừa từ lớp cán bộ và thêm các thuộc tính: 
phụ cấp, hệ số lương, bảo hiểm.
2.	Xây dựng các phương thức: 
nhập, xuất cho các đối tượng cán bộ, lương
*/

#include<bits/stdc++.h>
using namespace std;

class Canbo {
    protected:
        string ID;
        string Center;
        string name;
        int yob;
    public:
        void Input() {
            cout << "Nhap ma CB: "; getline(cin, ID);
            cout << "Nhap don vi: "; getline(cin, Center);
            cout << "Nhap ten CB: "; getline(cin, name);
            cout << "Nhap nam sinh: "; cin >> yob; cin.ignore();
        }

        void Title() {
            cout << left << setw(10) << "Ma CB"; 
            cout << left << setw(10) << "Ma DV"; 
            cout << left << setw(20) << "Ho ten"; 
            cout << left << setw(10) << "Nam sinh"; 
        }

        void Output() {
            cout << left << setw(10) << ID; 
            cout << left << setw(10) << Center; 
            cout << left << setw(20) << name; 
            cout << left << setw(10) << yob; 
        }
};

class Luong : public Canbo{
    private:
        int Bonus;
        float hs_luong;
        int Isurance;
        
    public:
        void Input() {
            Canbo :: Input();
            cout << "Nhap phu cap: "; cin >> Bonus;
            cout << "Nhap he so luong: "; cin >> hs_luong;
            cout << "Nhap bao hiem: "; cin >> Isurance;
            cin.ignore();
        }

        void Title() {
            Canbo :: Title();
            cout << left << setw(10) << "Phu cap"; 
            cout << left << setw(10) << "HS Luong"; 
            cout << left << setw(10) << "Bao hiem" << endl; 
        }

        void Output() {
            Canbo :: Output();
            cout << left << setw(10) << Bonus; 
            cout << left << setw(10) << hs_luong; 
            cout << left << setw(10) << Isurance << endl; 
        }
};

int main() {
    int n;
    cout << "Nhap so CB: ";
    cin >> n;
    cin.ignore();

    Luong* SL = new Luong[n];
    for(int i = 0; i < n; i++) {
        cout << "CB " << i + 1 << ": " << endl;
        SL[i].Input();
    }

    SL->Title();
    for(int i = 0; i < n; i++) {
        SL[i].Output();
    }

    delete[] SL;
}