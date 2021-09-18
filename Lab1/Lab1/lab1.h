#include <iostream>
#include <stdio.h>

namespace lab1Normal {
    class Matrix {
    public:
        Matrix(int rows, int cols, int* val, int* col, int* nz) :
            rowNumber(rows), colNumber(cols), values(val), cols(col), notzero(nz){}
        ~Matrix();

        void printMatrixFull();
        void printMatrixShort();
        void printVector(int*& vector);
    private:
        void createVector(int*& vector);

        int rowNumber, colNumber;
        int* values;
        int* cols;
        int* notzero;
    };

    class Dialog {
    public:
        enum class options {
            Exit = 0, MatrixInput,
            MatrixOutput, VectorOutput, Waiting
        };

        Dialog() : option(options::Waiting) {};
        ~Dialog();

        void matrixInput(Matrix*& matrix);
        void matrixOutput(Matrix*& matrix);
        void vectorOutput(Matrix*& matrix, int*& vector);
        void menu();
        options getOption() { return option; }
    private:
        const char* msg_menu = "0. Exit\n1. Input matrix\n2. Output matrix\n3. Output vector\n";
        const char* msg_menuCH = "Choose an option: ";
        options option;
    };

    bool is_digit(const char* S);
    template <class T> int getNum(T& a, const char* msg, bool sizeCheck);
}