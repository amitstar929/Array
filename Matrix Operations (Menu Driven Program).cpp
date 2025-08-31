// Program 6.27
// Write a menu driven program to read and display an m x n matrix. 
// Find the sum, transpose, and product  of two m x n matrices.

//   user input

// 1. Matrix Sum
// 2. Matrix Transpose
// 3. Matrix Multiplication

#include <iostream>
using namespace std;

// Function Declaration

void display(int** Matrix, int& row, int& column);
void input(int** Matrix, int& row, int& column);
void sum();
void Mul();
void Transpose();

// Taking Input
void input(int** Matrix,int& row, int& column){

    // Input Value
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            cin >> Matrix[i][j];
        }
    }
}

// Display Matrix
void display(int** Matrix, int& row, int& column){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Matrix Sum 
void sum(){
    int row1, column1, row2, column2;

    cout << "Enter the number of  row and column for matrix 1 : ";
    cin >> row1 >> column1;

    cout  << "Enter the number of row and column for matrix 2 : ";
    cin >> row2 >> column2;

    if(row1 < 1 || column1 < 1 || row2 < 1 || column2 < 1){
        cout << "Invalid Input! Row and Column must be positive." << endl;
        return;
    }
    if(row1 != row2 || column1 != column2){
        cout << "Matrix Addition is Not Posible!, Dimensions Must be match." << endl;
        return;
    }

    // Dynamic Memory Allocation
    int** Matrix_1 = new int* [row1];
    int** Matrix_2 = new int* [row2];
    int** Matrix_3 = new int* [row1];  // result matrix

    for(int i = 0; i < row1; i++){
        Matrix_1[i] = new int [column1];
        Matrix_2[i] = new int [column2];
        Matrix_3[i] = new int [column1]();
    }
    // Input
    cout << "\nEnter Element for Matrix 1 \n" << endl;
    input(Matrix_1, row1, column1);
    
    cout << "\nEnter Element for Matrix 2 \n" << endl;
    input(Matrix_2, row2, column2);

    // Addition
    for(int i = 0; i < row1; i++){
        for(int j = 0; j < column1; j++){
            Matrix_3[i][j] = Matrix_1[i][j] + Matrix_2[i][j];
        }
    }

    // Display Matrix Form
    cout << "\n---------Matrix_1----------" << endl;
    display(Matrix_1, row1, column1);
    cout << "\n---------Matrix_2----------" << endl;
    display(Matrix_2, row2, column2);

    // Display Result
    cout << "\nResultant Matrix (Sum)" << endl;
    display(Matrix_3, row1, column1);

    // Free Memory 

    for(int i = 0; i < row1; i++){
        delete[] Matrix_1[i];
        delete[] Matrix_2[i];// Free Memory row by row
        delete[] Matrix_3[i];
        Matrix_1[i] = nullptr;
        Matrix_2[i] = nullptr;  // Avoid Dangling Pointer row by row
        Matrix_3[i] = nullptr;
    }
    delete[] Matrix_1;
    delete[] Matrix_2;  // Free memory of Matrix_2
    delete[] Matrix_3;
    Matrix_1 = nullptr;  // Avoid Dangling Pointer
    Matrix_2 = nullptr;
    Matrix_3 = nullptr;
}

void Mul(){
    int row1, column1, row2, column2;
    cout << "Enter the number  of row and column for matrix 1 : ";
    cin >> row1 >> column1;
    cout << "Enter the number of row and column of matrix 2 : ";
    cin >> row2 >> column2;

    // Check Validation

    if(row1 < 1 || row2 < 1 || column1 < 1 || column2 < 1){
        cout << "Invalid Size!, Row and Column must be Positive. " << endl;
        return;
    }
    if(column1 != row2){
        cout << "Matrix Can't be Multiplied!, Column1 and Row2 must be Same." << endl;
        return;
    }

    int** Matrix_1 = new int* [row1];
    int** Matrix_2 = new int* [row2];
    int** Matrix_3 = new int* [row1];
    for(int i = 0; i < row1; i++){
        Matrix_1[i] = new int [column1];
        Matrix_3[i] = new int [column2]();
    }
    for(int i = 0; i < row2; i++){
        Matrix_2[i] = new int [column2];
    }

    // Input Value
    cout << "\n-------Enter the element of Matrix_1------------ " << endl;
    input(Matrix_1, row1, column1);
    cout << "\n-------Enter the element of Matrix_2------------ " << endl;
    input(Matrix_2, row2, column2);

    // Matrix Form
    cout << "\n----------Matrix_1-------------------" << endl;
    display(Matrix_1, row1, column1);
    cout << "\n----------Matrix_2-------------------" << endl;
    display(Matrix_2, row2, column2);
    // Matrix Calculation
    for(int i = 0; i < row1; i++){
        for(int j = 0; j < column2; j++){
            for(int k = 0; k < row2; k++){
                Matrix_3[i][j] += Matrix_1[i][k] * Matrix_2[k][j];
            }
        }
    }

    // Resultant Matrix.
    cout << "\n------------Resultant Matrix-------------" << endl;
    display(Matrix_3, row1, column2);

    for(int i = 0; i < row1; i++){
        delete[]  Matrix_1[i];
        delete[]  Matrix_3[i];
        Matrix_1[i] = nullptr;
        Matrix_3[i] = nullptr;
    }
    for(int i = 0; i < row2; i++){
        delete[] Matrix_2[i];
        Matrix_2[i] = nullptr;
    }
    delete[] Matrix_1;
    delete[] Matrix_2;
    delete[] Matrix_3;
    Matrix_1 = nullptr;
    Matrix_2 = nullptr;
    Matrix_3 = nullptr;

}
// Transpose Matrix
void Transpose(){
    int row, column;
    cout << "Enter the number of row and column for Matrix : " ;
    cin >> row >> column;

    if(row < 1 || column < 1){
        cout << "\nInvalid Size!, Row and Column Must Be Positive." << endl;
        return;
    }
    // Input
    
    // Dynamic Memory Allocation
    int** Matrix = new int* [row];
    for(int i = 0; i < row; i++){
        Matrix[i] = new int [column];
    }
    int** Transpose_Matrix = new int* [column];
    for(int i = 0; i < column; i++){
        Transpose_Matrix[i] = new int [row]();
    }
    
    
    cout << "\n---------Enter the Element of Matrix----------" << endl; 
    input(Matrix, row, column);

    cout << "\n-------------MatrixForm-------------------------" << endl;
    display(Matrix, row, column);

    // Calculate Transpose 
    for(int i = 0; i < column; i++){
        for(int j = 0; j < row; j++){
            Transpose_Matrix[i][j] = Matrix[j][i];
        }
    }
    // Resultant Matrix
    cout << "\n-----------------Transpose Matrix--------------------" << endl;
    display(Transpose_Matrix, column, row);

    for(int i = 0; i < row; i++){
        delete[]  Matrix[i];
        Matrix[i] = nullptr;
    }
    delete[] Matrix;
    Matrix = nullptr;

    for(int i = 0; i < column; i++){
        delete[] Transpose_Matrix[i];
        Transpose_Matrix[i] = nullptr;
    }
    delete[] Transpose_Matrix;
    Transpose_Matrix = nullptr;

} 



int main(){

    // Exit when Enter 4.

    int choice;
    while(true){
        cout << "\n------------------Enter your choice------------------" << endl;
        cout << "1 for Addition of Two Matrix." << endl;
        cout << "2 for Multiplication of Two Matrix." << endl;
        cout << "3 for Transpose of Matrix." << endl;
        cout << "4 Exit." << endl;
        cout << "Enter Digit : ";
    
        cin >> choice;
        switch(choice){
            case 1:
                sum();
                break;
            case 2:
                Mul();
                break;
            case 3:
                Transpose();
                break;
            case 4:
                return 1;
            default:
                cout << "Invalid Integer!, Integer must be (1 - 3)." << endl;
                break;
        }
    }


    // // Automatic Exit when Function One time run

    // int choice;
    // while(true){
    //     cout << "\n------------------Enter your choice------------------" << endl;
    //     cout << "1 for Addition of Two Matrix." << endl;
    //     cout << "2 for Multiplication of Two Matrix." << endl;
    //     cout << "3 for Transpose of Matrix." << endl;
    //     cout << "Enter Digit : ";
    //     cin >> choice;

    //     if(choice == 1){
    //         sum();
    //         break;
    //     }
    //     else if(choice == 2){
    //         Mul();
    //         break;
    //     }
    //     else if(choice == 3){
    //         Transpose();
    //         break;
    //     }
    //     else{
    //        cout << "Invalid Integer!, Integer must be (1 - 3)." << endl;
    //     }
    // }
    return 0;
}
