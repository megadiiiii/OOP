/*Câu 7: Viết chương trình thực hiện các yêu cầu sau:
1.	Khai báo lớp ma trận vuông với các thuộc tính: 
cấp ma trận, các phần tử của ma trận.
2.	Xây dựng các phương thức: nhập, xuất một đối tượng ma trận.
3.	Nhập vào 1 ma trận. In ra màn hình ma trận vừa nhập.
Tính tổng các phần tử nằm trên đường chéo chính
tổng các phần tử nằm trên đường chéo phụ của ma trận.
*/

#include<bits/stdc++.h>
using namespace std;

class Matrix {
    private:
        int level;
        int Mat[10][10];
    public: 
        Matrix() {
            level = 0;
        }

        Matrix(int level) {
            this -> level = level;
        }

        int getMatrix(int i, int j) {
            return Mat[i][j];
        }
        
        int getLevel() {
            return level;
        }

        void Input() {
            cout << "Nhap cap cua ma tran: ";
            cin >> level;

            for(int i = 0; i < level; i++) {
                for(int j = 0; j < level; j++) {
                    cout << "Mat[" << i << "][" << j << "] = ";
                    cin >> Mat[i][j];
                }
            }
        }

        void Output() {
            cout << "Ma tran vua nhap:" << endl; 
            for(int i = 0; i < level; i++) {
                for(int j = 0; j < level; j++) {
                    cout << Mat[i][j] << "\t";
                }
                cout << endl; 
            }
        }

        friend int Sum_DCC(Matrix mat);
        friend int Sum_DCP(Matrix mat);
};

int Sum_DCC(Matrix mat) {
    int sum_dcc = 0;
    for(int i = 0; i < mat.level; i++) {
        for(int j = 0; j < mat.level; j++) {
            if(i == j) {
                sum_dcc += mat.Mat[i][j];
            }
        }
    }
    cout << "Tong duong cheo chinh la: " << sum_dcc << endl;
    return sum_dcc;
}

int Sum_DCP(Matrix mat) {
    int sum_dcp = 0;
    for(int i = 0; i < mat.level; i++) {
        for(int j = 0; j < mat.level; j++) {
            if(i + j == mat.level - 1) {
                sum_dcp += mat.Mat[i][j];
            }
        }
    }
    cout << "Tong duong cheo phu la: " << sum_dcp << endl;
    return sum_dcp;
}

int main() {
    Matrix mat;
    mat.Input();
    mat.Output();

    Sum_DCC(mat);
    Sum_DCP(mat);
}