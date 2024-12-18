/*Câu 8: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp ma trận với các thuộc tính: số hàng, số cột,
các phần tử của ma trận.
2.	Xây dựng các phương thức: nhập, xuất một đối tượng ma trận.
3.	Nhập vào 1 ma trận. In ra màn hình ma trận vừa nhập. 
Tính tổng các phần tử nằm trên 4 đường viền của ma trận.
*/

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

            cout << "Nhap ma tran: " << endl;
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
                    cout << Mat[i][j] << "    ";
                }
                cout << endl;
            }
        }

        friend int Sum_Bound(Matrix Mat);
};

int Sum_Bound(Matrix Mat) {
    int bound = 0;
    for (int i = 0; i < Mat.row; i++) {
        bound += Mat.Mat[i][0]; // Cạnh trái
        bound += Mat.Mat[i][Mat.col - 1]; // Cạnh phải
    }
    for (int j = 1; j < Mat.col - 1; j++) {
        bound += Mat.Mat[0][j]; // Hàng trên
        bound += Mat.Mat[Mat.row - 1][j]; // Hàng dưới
    }
    cout << "Sum_bound: " << bound << endl;
    return bound;
}

int main() {
    Matrix Mat;
    Mat.Input();
    Mat.Output();
    Sum_Bound(Mat);
}