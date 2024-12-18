/*Câu 9: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp nhân viên với các thuộc tính: họ tên, chức vụ, giới tính, năm sinh, quê quán, năm vào làm.
2.	Xây dựng các toán tử >>, << để nhập, xuất một đối tượng nhân viên.
3.	Nhập vào n nhân viên. In ra màn hình danh sách các nhân viên làm việc trên 20 năm 
(số năm làm việc bằng năm hiện tại trừ năm vào làm).
*/

#include<bits/stdc++.h>
using namespace std;


class Nhanvien {
    private:    
        string name;
        string position;
        string sex;
        int yob;
        string hometown;
        int work_year;
    public:
        Nhanvien() {
            name = "";
            position = "";
            sex = "";
            yob = 0;
            hometown = "";
            work_year = 0;
        }

        friend istream& operator>>(istream& is, Nhanvien &NV) {
            cout << "Nhap ho ten: "; getline(is, NV.name);
            cout << "Nhap chuc vu: "; getline(is, NV.position);
            cout << "Nhap gioi tinh: "; getline(is, NV.sex); 
            cout << "Nhap nam sinh: "; is >> NV.yob; is.ignore();
            cout << "Nhap que quan: "; getline(is, NV.hometown); 
            cout << "Nhap nam vao lam: "; is >> NV.work_year; is.ignore();
            return is;
        }
        friend ostream& operator<<(ostream& os, Nhanvien &NV) {
            os << left << setw(15) << NV.name;
            os << left << setw(10) << NV.position;
            os << left << setw(10) << NV.sex;
            os << left << setw(10) << NV.yob;
            os << left << setw(20) << NV.hometown;
            os << left << setw(10) << NV.work_year;
            return os;
        }

        int getWork_year(){
            return work_year;
        }

};
void Title() {
    cout << left
         << setw(15) << "Ho ten"
         << setw(10) << "Chuc vu"
         << setw(10) << "Gioi tinh"
         << setw(10) << "Nam sinh"
         << setw(20) << "Que quan"
         << setw(10) << "Nam vao lam" << endl;
}

int main() {
    int n;
    cout << "Nhap so NV: "; 
    cin >> n;
    cin.ignore();
    Nhanvien* NV = new Nhanvien[n];

    for(int i = 0; i < n; i++) {
        cout << "Nhap NV " << i + 1 << ": " << endl;
        cin >> NV[i]; 
    }


    Title();
    for(int i = 0; i < n; i++) {
        cout << NV[i] <<endl;
    }
    delete[] NV;
}