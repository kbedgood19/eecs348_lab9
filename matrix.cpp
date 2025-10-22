#include "matrix.h"
#include <iostream>
#include <iomanip>
#include <fstream>

vector<vector<int>> loadMatrix(ifstream& file, int N) {
    vector<vector<int>> matrix(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            file >> matrix[i][j];
    return matrix;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row)
            cout << setw(4) << val;
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> addMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int N = A.size();
    vector<vector<int>> C(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int N = A.size();
    vector<vector<int>> C(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

void sumDiagonals(const vector<vector<int>>& matrix) {
    int N = matrix.size();
    int mainSum = 0, secondarySum = 0;
    for (int i = 0; i < N; ++i) {
        mainSum += matrix[i][i];
        secondarySum += matrix[i][N - i - 1];
    }
    cout << "Main diagonal sum: " << mainSum << endl;
    cout << "Secondary diagonal sum: " << secondarySum << endl << endl;
}

void swapRows(vector<vector<int>>& matrix, int r1, int r2) {
    int N = matrix.size();
    if (r1 >= 0 && r1 < N && r2 >= 0 && r2 < N) {
        swap(matrix[r1], matrix[r2]);
        printMatrix(matrix);
    } else {
        cout << "Invalid row indices.\n";
    }
}

void swapCols(vector<vector<int>>& matrix, int c1, int c2) {
    int N = matrix.size();
    if (c1 >= 0 && c1 < N && c2 >= 0 && c2 < N) {
        for (int i = 0; i < N; ++i)
            swap(matrix[i][c1], matrix[i][c2]);
        printMatrix(matrix);
    } else {
        cout << "Invalid column indices.\n";
    }
}

void updateElement(vector<vector<int>>& matrix, int row, int col, int newVal) {
    int N = matrix.size();
    if (row >= 0 && row < N && col >= 0 && col < N) {
        matrix[row][col] = newVal;
        printMatrix(matrix);
    } else {
        cout << "Invalid indices.\n";
    }
}