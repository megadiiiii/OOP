/*Cau 1:
1.	Khai báo lớp thí sinh với các thuộc tính: 
mã thí sinh, họ tên, điểm toán, điểm lý, điểm hóa.
2.	Xây dựng các phương thức: nhập, xuất, 
tính tổng điểm một đối tượng thí sinh.
Xây dựng constructor không đối, có đối
3.	Nhập vào n thí sinh. 
In ra màn hình thông tin của thí sinh có tổng điểm cao nhất 
(yêu cầu sử dụng biến con trỏ để cấp phát và giải phóng bộ nhớ). 
4.	Sắp xếp họ tên tăng dần
*/

#include<bits/stdc++.h>
using namespace std;

class Thisinh {
    private:
        string ID;
        string name;
        float Toan;
        float Li;
        float Hoa;
    public:
        Thisinh() {}
        Thisinh(string ID, string name, float Toan, float Li, float Hoa) {
            this -> ID = ID;
            this -> name = name;
            this -> Toan = Toan;
            this -> Li = Li;
            this -> Hoa = Hoa;
        }

        float Sum_Score() {
            return Toan + Li + Hoa;
        }

        void Input() {
            cin.ignore();
            cout << "Nhap MSV: ";
            getline(cin, ID);
            cout << "Nhap ho ten: ";
            getline(cin, name);
            
            cout << "Nhap diem toan: ";
            cin >> Toan;cin.ignore();
            cout << "Nhap diem li: ";
            cin >> Li;
            cout << "Nhap diem hoa: ";
            cin >> Hoa;
        }

        void Title() {
            cout << left << setw(10) << "MSV";
            cout << left << setw(20) << "Ho ten";
            cout << left << setw(10) << "Toan";
            cout << left << setw(10) << "Li";
            cout << left << setw(10) << "Hoa";
            cout << left << setw(10) << "Tong diem" << endl;
        }

        void Output() {
            cout << left << setw(10) << ID;
            cout << left << setw(20) << name;
            cout << left << setw(10) << Toan;
            cout << left << setw(10) << Li;
            cout << left << setw(10) << Hoa;
            cout << left << setw(10) << Sum_Score() << endl;
        }

        string getName() {
            return name;
        }
};

void Max_Score(Thisinh* TS, int n) {
    Thisinh Max = TS[0];
    TS->Title();
    for(int i = 0; i < n; i++) {
        if(TS[i].Sum_Score() > Max.Sum_Score()) {
            Max = TS[i];
        }
    }
    Max.Output();
}

void Sort(Thisinh* TS, int n) {
    cout << "Danh sach thi sinh sau sap xep" << endl;
    TS->Title();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(TS[i].getName() > TS[j].getName()) {
                Thisinh temp = TS[i];
                TS[i] = TS[j];
                TS[j] = temp;
            }
        }     
        TS[i].Output();  
    }
}

int main() {
    int n;
    cout << "Nhap so thi sinh: ";
    cin >> n;

    Thisinh* TS = new Thisinh[n];
    for(int i = 0; i < n; i++) {
        cout << "TS " << i + 1 << ": " << endl;
        TS[i].Input();
    }

    Max_Score(TS, n);
    Sort(TS, n);
    delete[] TS;
}