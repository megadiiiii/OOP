/*Câu 13: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp ma trận với các thuộc tính: 
số hàng, số cột, các phần tử của ma trận.
2.	Xây dựng các phương thức: 
nhập, xuất một đối tượng ma trận.
3.	Nhập vào hai ma trận đồng cấp. 
Thực hiện cộng hai ma trận vừa nhập (dùng hàm bạn). 
In ra màn hình hai ma trận ban đầu và ma trận kết quả.*/

#include<bits/stdc++.h>
using namespace std;

class Matrix {
    private:
        int row, col;
        int Mat[10][10];
    public:
        Matrix() {}
        Matrix(int row, int col) {
            this -> row = row;
            this -> col = col;
        }

        void Input() {
            cout << "Nhap so hang: "; cin >> row;
            cout << "Nhap so cot: "; cin >> col;

            for(int i = 0; i < row; i++) {
                for(int j = 0; j < col; j++) {
                    cout << "Mat[" << i << "][" << j << "] = ";
                    cin >> Mat[i][j];
                }
            }
        }

        void Output() {
            for(int i = 0; i < row; i++) {
                for(int j = 0; j < col; j++) {
                    cout << Mat[i][j] << "\t";
                }
                cout << endl;
            }
        }

        friend Matrix Sum(Matrix MT1, Matrix MT2);
};

Matrix Sum(Matrix MT1, Matrix MT2) {
    if(MT1.row != MT2.row || MT1.col != MT2.col) {
        cout << "Ma tran khac cap, khong the cong";
    }

    Matrix Result(MT1.row, MT1.col);
    for(int i = 0; i < MT1.row; i++) {
        for(int j = 0; j < MT2.col; j++) {
            Result.Mat[i][j] = MT1.Mat[i][j] + MT2.Mat[i][j];
        }
    }
    return Result;
}

int main() {
    Matrix MT1, MT2, Result;

    cout << "MT1" << endl;
    MT1.Input();
    cout << "MT2" << endl;
    MT2.Input();

    cout << "MT1" << endl;
    MT1.Output();
    cout << "MT2" << endl;
    MT2.Output();
    
    cout << "Tong 2 MT" << endl;
    Result = Sum(MT1, MT2);
    Result.Output();
}
