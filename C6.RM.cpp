/*Câu 6: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp người với các thuộc tính: họ tên, năm sinh.
Khai báo lớp sinh viên kế thừa từ lớp người và thêm các thuộc tính: 
mã sinh viên, điểm trung bình.
2.	Xây dựng các phương thức: constructor, nhập, xuất
cho các đối tượng người, sinh viên.
3.	Nhập vào n sinh viên. 
Nhập thông tin tìm kiếm là mã sinh viên hoặc họ tên. 
In ra màn hình thông tin sinh viên tìm thấy hoặc thông báo là không tìm thấy.*/

#include<bits/stdc++.h>
using namespace std;

class Person {
    protected:
        string name;
        int yob;
    public:
        void Input() {
            cin.ignore();
            cout << "Nhap ho ten: ";
            getline(cin, name);
            cout << "Nhap nam sinh: ";
            cin >> yob;
            cin.ignore();
        }

        void Title() {
            cout << left << setw(20) << "Ho ten";
            cout << left << setw(10) << "Nam sinh";
        }

        void Output() {
            cout << left << setw(20) << name;
            cout << left << setw(10) << yob;
        }

        string getName() {
            return name;
        }
};

class Student : public Person {
    private:
        string ID;
        float avg_score;
        
    public:
        void Input() {
            Person :: Input();
            cout << "Nhap MSV: ";
            getline(cin, ID);
            cout << "Nhap diem trung binh: ";
            cin >> avg_score;
        }

        void Title() {
            Person :: Title();
            cout << left << setw(20) << "MSV";
            cout << left << setw(10) << "DTB" << endl;
        }

        void Output() {
            Person :: Output();
            cout << left << setw(20) << ID;
            cout << left << setw(10) << avg_score << endl;
        }

        string getID() {
            return ID;
        }
};

void ST_Search(Student* ST, int n, string search) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(ST[i].getID() == search || ST[i].getName() == search) {
            ST[i].Output();
            cnt++;
        }
    }
    if(cnt == 0) cout << "Not found";
}

int main() {
    int n;
    cout << "Nhap so SV: ";
    cin >> n;

    Student* ST = new Student[n];
    for(int i = 0; i < n; i++) {
        cout << "SV " << i + 1 << ": " << endl;
        ST[i].Input();  
    }

    cin.ignore();    
    string search;
    cout << "Nhap MSV hoac ho ten SV de tim kiem: " ;
    getline(cin, search);

    ST->Title();
    ST_Search(ST, n, search);

    delete[] ST;
}