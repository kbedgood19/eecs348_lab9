#include "matrix.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename;
    cout << "Enter the input filename: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: could not open file." << endl;
        return 1;
    }

    int N;
    file >> N;

    vector<vector<int>> A = loadMatrix(file, N);
    vector<vector<int>> B = loadMatrix(file, N);
    file.close();

    int choice;
    do {
        cout << "\n===== Matrix Operations Menu =====" << endl;
        cout << "1. Display Matrices" << endl;
        cout << "2. Add Matrices (A + B)" << endl;
        cout << "3. Multiply Matrices (A * B)" << endl;
        cout << "4. Sum of Diagonals (Matrix A)" << endl;
        cout << "5. Swap Rows in Matrix A" << endl;
        cout << "6. Swap Columns in Matrix A" << endl;
        cout << "7. Update Element in Matrix A" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                cout << "Matrix A:\n";
                printMatrix(A);
                cout << "Matrix B:\n";
                printMatrix(B);
                break;

            case 2:
                cout << "Result of A + B:\n";
                printMatrix(addMatrices(A, B));
                break;

            case 3:
                cout << "Result of A * B:\n";
                printMatrix(multiplyMatrices(A, B));
                break;

            case 4:
                cout << "Diagonal sums of Matrix A:\n";
                sumDiagonals(A);
                break;

            case 5: {
                int r1, r2;
                cout << "Enter two row indices to swap (0-based): ";
                cin >> r1 >> r2;
                swapRows(A, r1, r2);
                break;
            }

            case 6: {
                int c1, c2;
                cout << "Enter two column indices to swap (0-based): ";
                cin >> c1 >> c2;
                swapCols(A, c1, c2);
                break;
            }

            case 7: {
                int row, col, val;
                cout << "Enter row, column, and new value: ";
                cin >> row >> col >> val;
                updateElement(A, row, col, val);
                break;
            }

            case 0:
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}