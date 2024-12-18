/*Câu 27: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp date với các thuộc tính: ngày, tháng, năm. 
Xây dựng hàm tạo không đối, hàm tạo có đối, hàm hủy một đối tượng date.
2.	Xây dựng các phương thức: nhập, xuất, chuẩn hóa một đối tượng date.
3.	Định nghĩa toán từ ++,-- để tăng, giảm một ngày. 
Thực hiện tăng, giảm một ngày và in kết quả ra màn hình 
(kết quả phải được chuẩn hóa dưới dạng dd-mm-yyyy).
(A++;//thực hiện biểu thức A trước sau đó mới tăng a lên một đơn vị
++A; // Tăng A trước lên 1 một đơn sau rồi mới thực hiện biểu thức
*/

#include<bits/stdc++.h>
using namespace std;

int dates_month(int month, int year);

class Date {
    private:
        int date, month, year;
    public:
        Date() {}
        Date(int date, int month, int year) {
            this -> date = date;
            this -> month = month;
            this -> year = year;
        }

        void Input() {
            cout << "Nhap ngay: ";
            cin >> date;
            cout << "Nhap thang: ";
            cin >> month;
            cout << "Nhap nam: ";
            cin >> year;
        }

        void Output() {
            Normalize();
            cout << setfill('0') << setw(2) << date << "-" << setw(2) << month << "-";
            cout << setfill('0') << setw(4) << year << endl;
        }

        void Normalize() {
            while(date < 1) {
                month--;
                if(month < 1) {
                    month = 12;
                    year--;
                }
                date += dates_month(month, year);
            }

            while(date > dates_month(month, year)) {
                date -= dates_month(month, year);
                month++;
                if(month > 12) {
                    month = 1;
                    year++;
                }
            } 
        }

        Date operator++() {
            date++;
            Normalize();
            return *this;
        }

        Date operator--() {
            date--;
            Normalize();
            return *this;
        }
};

int dates_month(int month, int year) {
    if(month == 2) {
        if(year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
            return 29;
        } else return 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } return 31;
}

int main() {
    Date test;
    test.Input();
    test.Output();

    Date Up = ++test;
    Up.Output();

    Date temp = test;
    Date Down = --temp;
    Down.Output();
}