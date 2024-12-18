/*Câu 9: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp nhân viên với các thuộc tính: 
họ tên, chức vụ, giới tính, năm sinh, quê quán, năm vào làm.
2.	Xây dựng các toán tử >>, << để nhập, xuất một đối tượng nhân viên.
3.	Nhập vào n nhân viên. In ra màn hình danh sách các nhân viên làm việc trên 20 năm 
(số năm làm việc bằng năm hiện tại trừ năm vào làm).
*/

#include<bits/stdc++.h>
using namespace std;

class Nhanvien {
    private:
        string name;
        string job;
        string sex;
        int yob;
        string hometown;
        int work_start;
    public:
        Nhanvien() {}
        Nhanvien(string name, string job, string sex, int yob, string hometown, int work_start) {
            this -> name = name;
            this -> job = job;
            this -> sex = sex;
            this -> yob = yob;
            this -> hometown = hometown;
            this -> work_start = work_start;
        }

        friend istream& operator>>(istream& is, Nhanvien& nv) {
            cout << "Nhap ten NV: ";
            getline(is, nv.name);
            cout << "Nhap chuc vu: ";
            getline(is, nv.job);
            cout << "Nhap gioi tinh: ";
            getline(is, nv.sex);
            cout << "Nhap nam sinh: ";
            is >> nv.yob;
            is.ignore();
            cout << "Nhap que quan: ";
            getline(is, nv.hometown);
            cout << "Nhap nam vao lam: ";
            is >> nv.work_start;
            is.ignore();
            return is;
        }

        friend ostream& operator<<(ostream& os, Nhanvien& nv) {
            cout << left << setw(20) << nv.name;
            cout << left << setw(10) << nv.job;
            cout << left << setw(10) << nv.sex;
            cout << left << setw(10) << nv.yob;
            cout << left << setw(15) << nv.hometown;
            cout << left << setw(10) << nv.work_start << endl;
            return os;
        }

        int getWork_start() {
            return work_start;
        }
};

void Title() {
    cout << left << setw(20) << "Ten NV";
    cout << left << setw(10) << "Chuc vu";
    cout << left << setw(10) << "Gioi tinh";
    cout << left << setw(10) << "Nam sinh";
    cout << left << setw(15) << "Que quan";
    cout << left << setw(15) << "Nam vao lam" << endl;
}

int main() {
    int n;
    cout << "Nhap so NV: ";
    cin >> n;
    cin.ignore();

    Nhanvien* NV = new Nhanvien[n];

    for(int i = 0; i < n; i++) {
        cout << "NV " << i + 1 << ": " << endl;
        cin >> NV[i];
    }

    cout << "DANH SACH NHAN VIEN LAM TREN 20 NAM" << endl;
    Title();
    for(int i = 0; i < n; i++) {
        if(2024 - NV[i].getWork_start() > 20){            
            cout << NV[i]; 
        }
    }

    delete[] NV;
}