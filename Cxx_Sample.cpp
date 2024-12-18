#include <bits/stdc++.h>
using namespace std;

int daysInMonth(int month, int year);
    

class Date {
private:
    int date, month, year;


public:
    Date() {
        date = 1;
        month = 1;
        year = 2000;
    }

    Date(int date, int month, int year) {
        this->date = date;
        this->month = month;
        this->year = year;
    }

    void Input() {
        cout << "Nhap ngay: ";
        cin >> date;
        cout << "Nhap thang: ";
        cin >> month;
        cout << "Nhap nam: ";
        cin >> year;
        Normalize();
    }

    void Output() {
        cout << setfill('0') << setw(2) << date << "-" << setw(2) << month << "-";
        cout << setfill('0') << setw(4) << year << endl;
    }

    void Normalize() {
        while (date < 1) {
            month--;
            if (month < 1) {
                month = 12;
                year--;
            }
            date += daysInMonth(month, year);
        }

        while (date > daysInMonth(month, year)) {
            date -= daysInMonth(month, year);
            month++;
            if (month > 12) {
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
int daysInMonth(int month, int year) {
    if (month == 2) {
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
            return 29;
        } else return 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

int main() {
    Date test;
    test.Input();
    test.Output();
    ++test;
    test.Output();
    --test;
    test.Output();
}