//Create a Matrix class. 
//Write a menu-driven program to perform following Matrix operations 
//(exceptions should be thrown by the functions if matrices passed to them are incompatible and handled by the main() function):
//sum()
//product()
//transpose()

#include <iostream>
#include <exception>

using namespace std;

class IncompatibleMatricesException : public exception {
public:
    const char* what() const throw()
    {
        return "Incompatible matrices!";
    }
};//this is the exception that a handler will throw if the matrix is appropriate.

class Matrix {
    int rows;
    int cols;
    int** arr;

public:
// the constructor and destructor
    Matrix(int r, int c);
    ~Matrix();

    void input();
    void display();
    void transpose();

    Matrix operator+(const Matrix& x);
    Matrix operator*(const Matrix& x);

    //declaring all the methods and operators that has to be used and performed.
};


Matrix::Matrix(int r, int c)
{
    rows = r;
    cols = c;
    // Allocate memory for the 2D array
    arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
} //the basic constructor

Matrix::~Matrix()
{
    // Deallocate the memory for the 2D array
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

void Matrix::input()//this method will take inputs for the matrices.
{
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }
}

void Matrix::display()//this method will display the matrices.
{
    cout << "Matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void Matrix::transpose()
{
    // Create a new matrix with dimensions swapped for the transpose
    Matrix result(cols, rows);
    
    // Calculate the transpose by swapping rows and columns
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            result.arr[i][j] = arr[j][i];
        }
    }
// Display the transpose matrix
    cout << "Transpose:" << endl;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << result.arr[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix Matrix::operator+(const Matrix& x)
{
     // Check if the dimensions of the matrices are compatible for addition
    if (rows != x.rows || cols != x.cols) {
        throw IncompatibleMatricesException();// Throw an exception if matrices are incompatible
    }
 // Create a new matrix to store the result of addition
    Matrix result(rows, cols);
    // Perform matrix addition by adding corresponding elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.arr[i][j] = arr[i][j] + x.arr[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& x)
{
    // Check if the dimensions of the matrices are compatible for multiplication
    if (cols != x.rows) {
        throw IncompatibleMatricesException();// Throw an exception if matrices are incompatible
    }

// Create a new matrix to store the result of multiplication
    Matrix result(rows, x.cols);

    // Perform matrix multiplication using the standard algorithm
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < x.cols; j++) {
            result.arr[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                result.arr[i][j] += arr[i][k] * x.arr[k][j];
            }
        }
    }
    return result;
}

int main()
{
    int rows1, cols1, rows2, cols2;
    int choice;

// Getting the dimensions of the matrices from the user
    cout << "Enter the number of rows and columns for the first matrix:" << endl;
    cin >> rows1 >> cols1;
    Matrix mat1(rows1, cols1);
    mat1.input();

    cout << "Enter the number of rows and columns for the second matrix:" << endl;
    cin >> rows2 >> cols2;
    Matrix mat2(rows2, cols2);
    mat2.input();

// Menu loop
    while (true) {
        cout << endl;
        cout << "-----------------------------" << endl;
        cout << "Menu:" << endl;
        cout << "1. Add Matrices" << endl;
        cout << "2. Multiply Matrices" << endl;
        cout << "3. Transpose Matrices" << endl;
        cout << "4. Exit" << endl;
        cout << "-----------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1://this will simply perform the operation according to the selected operation and throw the exceptions if required.
                try {
                    Matrix sum = mat1 + mat2;
                    cout << "Sum of the matrices:" << endl;
                    sum.display();
                } catch (const IncompatibleMatricesException& e) {
                    cout << "Exception: " << e.what() << endl;
                }
                break;
            case 2:
                try {
                    Matrix product = mat1 * mat2;
                    cout << "Product of the matrices:" << endl;
                    product.display();
                } catch (const IncompatibleMatricesException& e) {
                    cout << "Exception: " << e.what() << endl;
                }
                break;
            case 3:
                cout << "Transpose of Matrix 1:" << endl;
                mat1.transpose();
                cout << "Transpose of Matrix 2:" << endl;
                mat2.transpose();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
