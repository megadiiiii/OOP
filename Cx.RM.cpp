/*Cx. Viết chương trình thực hiện các yêu cầu sau:
1. Khai báo lớp time với các thuộc tính: giờ, phút, giây.
Xây dựng hàm tạo không đối, hàm tạo có đối, hàm hủy một đối tượng time.
2. Xây dựng các phương thức: nhập, xuất, chuẩn hóa một đối tượng time.
3. Định nghĩa toán từ ++,-- để tăng, giảm một giây. 
Thực hiện tăng, giảm một giây và in kết quả ra màn hình 
(kết quả phải được chuẩn hóa dưới định dạng 24 tiếng hh:mm:ss).
*/

#include<bits/stdc++.h>
using namespace std;

class Time {
    private:    
        int hour, min, sec;        
    public: 
        Time() {}

        ~Time() {}

        Time(int hour, int min, int sec) {
            this -> hour = hour;
            this -> min = min;
            this -> sec = sec;
        }

        void Input() {
            cout << "Nhap hour: "; cin >> hour;
            cout << "Nhap min: "; cin >> min;
            cout << "Nhap sec: "; cin >> sec;
            Normalize();
        }

        void Output() {
            cout << setfill('0') << setw(2) << hour << ":"
                                 << setw(2) << min << ":"
                                 << setw(2) << sec << endl;
        }

        void Normalize() {
            while(hour >= 24) {
                hour -= 24;
            }
            
            while(min >= 60) {
                min -= 60;
                hour++;
            }

            while(sec >= 60) {
                sec -= 60;
                min++;
            }

            while(hour < 0) {
                hour += 24;
            }

            while(min < 0) {
                min += 60;
            }
        }

        Time operator++()  {
            Time time;
            time.sec = this -> sec + 1;
            time.min = this -> min;
            time.hour = this -> hour;
            Normalize();
            return time;
        }

        Time operator--()  {
            Time time;
            time.sec = this -> sec - 1;
            time.min = this -> min;
            time.hour = this -> hour;
            Normalize();
            return time;
        }
};

int main() {
    Time test;
    test.Input();
    test.Output();

    Time Up = ++test;
    Up.Output();
    Time down = --test;
    down.Output();
}