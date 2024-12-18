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
        Time() {
            hour = 0;
            min = 0;
            sec = 0;
        }

        Time(int hour, int min, int sec) {
            this -> hour = hour;
            this -> min = min;
            this -> sec = sec;
        }

        ~Time() {}

        void Input() {
            cout << "Nhap gio: "; cin >> hour;
            cout << "Nhap phut: "; cin >> min;
            cout << "Nhap giay: "; cin >> sec;
            Nomalize();
        }

        void Output() {
            cout << setfill('0') << setw(2) << hour <<  ":"
                                 << setw(2) << min <<  ":" 
                                 << setw(2) << sec << endl;
        }

        void Nomalize(){
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

        Time operator++() {
            Time Up;
            sec++;
            Nomalize();
            return *this;
        }
        Time operator--() {
            sec--;
            Nomalize();
            return *this;
        }
};

int main () {
    Time time;
    time.Input();
    time.Output();

    ++time;
    time.Output();

    Time t1 =--time;
    t1.Output();
}