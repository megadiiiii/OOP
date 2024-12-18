/*
Câu 13: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp ma trận với các thuộc tính: số hàng, số cột, 
các phần tử của ma trận.
2.	Xây dựng các phương thức: nhập, xuất một đối tượng ma trận.
3.	Nhập vào hai ma trận đồng cấp.
Thực hiện cộng hai ma trận vừa nhập (dùng hàm bạn). 
In ra màn hình hai ma trận ban đầu và ma trận kết quả.
*/

#include<iostream>
using namespace std;

class Matrix {
    protected:
        int row, col;
        int mat[10][10];
    public:
        Matrix() {
            row = 0;
            col = 0;
        }
        Matrix(int row, int col) {
            this -> row = row;
            this -> col = col;
        }

        void Input() {
            cout << "Nhap so hang: "; cin >> row;
            cout << "Nhap so cot: "; cin >> col;

            for(int i = 0; i < row; i++) {
                for(int j = 0; j < col; j++) {
                    cout << "Phan tu [" << i << "][" << j << "] = ";
                    cin >> mat[i][j];
                }
            }
        }

        void Output() {
            for(int i = 0; i < row; i++) {
                for(int j = 0; j < col; j++) {
                    cout << mat[i][j] << "    ";
                }
                cout << endl;
            }
        }

        friend Matrix Sum(Matrix mt1, Matrix mt2);
};
Matrix Sum(Matrix mt1, Matrix mt2) {
    if(mt1.row != mt2.row || mt1.col != mt2.col) {
        cout << "Khong the cong 2 ma tran khac cap" << endl;
        return Matrix();
    }

    Matrix Result(mt1.row, mt1.col);
        for(int i = 0; i < mt1.row; i++) {
            for(int j = 0; j < mt1.col; j++) {
                Result.mat[i][j] = mt1.mat[i][j] + mt2.mat[i][j];        
            }
        }
    return Result;
}

int main() {
    Matrix mt1, mt2;
    cout << "Nhap ma tran 1: " << endl;
    mt1.Input();
    cout << "Nhap ma tran 2: " << endl;
    mt2.Input();

    Matrix Result = Sum(mt1, mt2);

    cout << "Ma tran 1: " << endl;
    mt1.Output();
    cout << "Ma tran 2: " << endl;
    mt2.Output();

    cout << "Sum: " << endl;
    Result.Output();
}   