#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>
using namespace std;

vector<vector<int>> loadMatrix(ifstream& file, int N);
void printMatrix(const vector<vector<int>>& matrix);
vector<vector<int>> addMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B);
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B);
void sumDiagonals(const vector<vector<int>>& matrix);
void swapRows(vector<vector<int>>& matrix, int r1, int r2);
void swapCols(vector<vector<int>>& matrix, int c1, int c2);
void updateElement(vector<vector<int>>& matrix, int row, int col, int newVal);

#endif