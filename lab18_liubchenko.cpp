#include <iostream>

using namespace std;

class Matrix {
private:
    int array[10];

public:
    Matrix() {
        for (int i = 0; i < 10; ++i) {
            array[i] = 0;
        }
    }

    void setValues(const int values[]) {
        for (int i = 0; i < 10; ++i) {
            array[i] = values[i];
        }
    }

    Matrix operator-(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 10; ++i) {
            result.array[i] = this->array[i] - other.array[i];
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 10; ++i) {
            result.array[i] = this->array[i] * other.array[i];
        }
        return result;
    }

    bool operator==(const Matrix& other) const {
        for (int i = 0; i < 10; ++i) {
            if (this->array[i] != other.array[i]) {
                return false;
            }
        }
        return true;
    }

    void print() const {
        for (int i = 0; i < 10; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Matrix mat1, mat2;

    int values1[10], values2[10];
    for (int i = 0; i < 10; ++i) {
        values1[i] = i + 1;
        values2[i] = i + 2;
    }

    mat1.setValues(values1);
    mat2.setValues(values2);

    cout << "Matrix 1: ";
    mat1.print();
    cout << "Matrix 2: ";
    mat2.print();

    Matrix subtractionResult = mat1 - mat2;
    cout << "Subtraction Result: ";
    subtractionResult.print();

    Matrix multiplicationResult = mat1 * mat2;
    cout << "Multiplication Result: ";
    multiplicationResult.print();

    if (mat1 == mat2) {
        cout << "Matrices are equal." << endl;
    }
    else {
        cout << "Matrices are not equal." << endl;
    }

    return 0;
}
