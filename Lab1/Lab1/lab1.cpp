#include "lab1.h"
#include <iostream>
#include <set>

namespace lab1Normal {
    void Dialog::matrixInput(Matrix*& matrix) {
        int rows, cols, errcode;

        if (matrix != nullptr) delete matrix;

        const char* msg = "Enter number of rows: ";

        do {
            errcode = getNum<int>(rows, msg, true);
            if (errcode) msg = "Error, not an integer number or number is too big (>2147483646) , repeat: ";
            if (!errcode && rows < 1) {
                errcode = 1;
                msg = "Error, number should be bigger than 0, repeat: ";
            }
        } while (errcode);

        msg = "Enter number of columns: ";

        do {
            errcode = getNum<int>(cols, msg, true);
            if (errcode) msg = "Error, not an integer number or number is too big (>2147483646) , repeat: ";
            if (!errcode && cols < 1) {
                errcode = 1;
                msg = "Error, number should be bigger than 0, repeat: ";
            }
        } while (errcode);

        int* nz = new int[rows + 1];
        int* values = nullptr;   //nullptr
        int* columns = nullptr;
        nz[0] = 0;

        int read;
        int* tempValues = new int[cols];
        int* tempCols = new int[cols];

        for (int i = 0; i < rows; i++) {
            std::cout << "Enter " << i << " row" << std::endl;
            int curRowNz = 0;

            for (int j = 0; j < cols; j++) {
                msg = "";

                do {
                    errcode = getNum<int>(read, msg, false);
                    if (errcode) msg = "Error, not an integer number, repeat: ";
                } while (errcode);

                if (read != 0) {
                    tempValues[curRowNz] = read;
                    tempCols[curRowNz] = j;
                    curRowNz++;
                }
            }

            nz[i + 1] = nz[i] + curRowNz;
            int* b = new int[nz[i + 1]];
            int* c = new int[nz[i + 1]];


            if (i != 0) {
                for (int ii = 0; ii < nz[i]; ii++) {
                    b[ii] = values[ii];
                    c[ii] = columns[ii];
                }
            }

            int iii = 0;
            for (int ii = nz[i]; ii < nz[i + 1]; ii++) {
                b[ii] = tempValues[iii];
                c[ii] = tempCols[iii];
                iii++;
            }

            if (i != 0) {
                delete[] columns;
                delete[] values;
            }
            columns = new int[nz[i + 1]];
            values = new int[nz[i + 1]];

            for (int ii = 0; ii < nz[i + 1]; ii++) {
                values[ii] = b[ii];
                columns[ii] = c[ii];
            }

            delete[] b;
            delete[] c;
        }

        delete[] tempValues;
        delete[] tempCols;

        matrix = new Matrix(rows, cols, values, columns, nz);
        option = options::Waiting;
    }
    void Dialog::matrixOutput(Matrix*& matrix) {
        if (matrix != nullptr) {
            const char* msg = "Enter 0 to short output and 1 to full: ";
            int errcode;
            int Opt;

            do {
                errcode = getNum<int>(Opt, msg, true);
                if (errcode) msg = "Error, not an integer number or number is too big (>2147483646) , repeat: ";    //delete
                if (!errcode && Opt != 1 && Opt != 0) {
                    errcode = 1;
                    msg = "Error, no such mode, repeat: ";
                }
            } while (errcode);
            
            if (Opt) {
                matrix->printMatrixFull();
            }
            else {
                matrix->printMatrixShort();
            }
        }
        else {
            std::cout << "Input matrix first!" << std::endl;
        }
        option = options::Waiting;
    }
    void Dialog::vectorOutput(Matrix*& matrix, int*& vector) {
        if (matrix != nullptr){
            matrix->printVector(vector);
        }
        else {
            std::cout << "Input matrix first!" << std::endl;
        }
        option = options::Waiting;
    }
    void Dialog::menu() {
        const char* msg = "";
        int errcode;
        int Option;

        std::cout << msg_menu << std::endl << msg_menuCH << std::endl;

        do {
            errcode = getNum<int>(Option, msg, false);
            if (errcode == -2) msg = "Error, not an integer number , repeat: ";
            if (!errcode && (Option < 0 || Option > 3)) {
                errcode = 1;
                msg = "Error, not an option of menu, repeat: ";
            }
        } while (errcode);

        option = (options)Option;
    }
    Dialog::~Dialog() {
        std::cout << "Finished" << std::endl;
    }

    Matrix::~Matrix() {
        delete[] values;
        delete[] cols;
        delete[] notzero;
    }
    void Matrix::createVector(int*& vector) {
        int* vals = new int[rowNumber];
        std::multiset<int> MS;
        int max;
        
        for (int i = 0; i < rowNumber; i++) {
            max = 0;
            for (int j = notzero[i]; j < notzero[i + 1]; j++) {
                MS.insert(values[j]);
            }
            int temp = 0;
            int cur = 0;
            for (const auto& el : MS) {
                if (cur != el) {
                    cur = el;
                    temp = 1;
                }
                else {
                    temp++;
                }
                if (temp > max) max = temp;
            }

            vals[i] = max;
            MS.clear();
        }

        vector = vals;
    }
    void Matrix::printMatrixFull() {
        int counter = 0;
        for (int row = 0; row < rowNumber; row++) {
            int nz = notzero[row + 1] - notzero[row];
            for (int col = 0; col < colNumber; col++) {
                if (nz != 0 && cols[counter] == col) {
                    std::cout << values[counter] << " ";
                    counter++;
                    nz--;
                }
                else {
                    std::cout << "0 ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    void Matrix::printMatrixShort() {
        int counter = 0;
        for (int row = 0; row < rowNumber; row++) {
            int nz = notzero[row + 1] - notzero[row];
            for (int col = 0; col < colNumber; col++) {
                if (nz != 0 && cols[counter] == col) {
                    std::cout << "[ " << col << " : " << row << " ]\t" << values[counter] << std::endl;
                    counter++;
                    nz--;
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    void Matrix::printVector(int*& vector) {
        if (vector == nullptr) {
            Matrix::createVector(vector);
        }

        for (int i = 0; i < rowNumber; i++) {
            std::cout << vector[i] << " ";
        }
        std::cout << std::endl << std::endl;
    }

    bool is_digit(const char* S) {
        const char* temp = "0123456789-+";
        unsigned point_count = 0;

        for (unsigned int i = 0; i < strlen(S); i++) {
            if ((i > 0) && (S[i] == '+' || S[i] == '-')) return false;
            if (!strchr(temp, S[i])) return false;
        }
        return true;
    }
    template <class T> int getNum(T& a, const char* msg, bool sizeCheck)
    {
        if (msg != nullptr) {
            std::cout << std::endl << msg;
        }

        const int N = 256;
        char S[N];

        std::cin.getline(S, N, '\n');
        if (!is_digit(S) || S[0] == '\0') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return -2;
        }

        a = atoi(S);

        if (sizeCheck) {
            if (a == INT32_MAX) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return -3;
            }
        }

        if (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return -1;
        }

        return 0;
    }
}