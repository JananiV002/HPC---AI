// ############
// Author: JANANI.V
// REG NO: 24011501007
//CLASS: M.TECH
//UNIVERSITY: SHIV NADAR UNIVERSITY
// #############

#include <iostream>
#include <cstdlib> // For rand()
#include <ctime>   // For time()
using namespace std;

// Define the size of the matrices
#define SIZE 256

int main() {
    // Declare 256x256 matrices A, B, and C
    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];

    // Initialize random number generator with the current time as the seed
    srand(time(0));

    // Initialize matrix A with random values between 0 and 99
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            A[i][j] = rand() % 100; // Generate a random number between 0 and 99
        }
    }

    // Initialize matrix B with random values between 0 and 99
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            B[i][j] = rand() % 100; // Generate a random number between 0 and 99
        }
    }

    // Perform matrix addition: C[i][j] = A[i][j] + B[i][j]
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            C[i][j] = A[i][j] + B[i][j]; // Sum corresponding elements of A and B
        }
    }

    // Output the result matrix C (only print the first 5x5 block for readability)
    cout << "Resultant Matrix C (A + B) (First 5x5 block): " << endl;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            // Print only the first 5x5 block of the matrix to avoid excessive output
            if (i < 5 && j < 5) {
                cout << C[i][j] << " ";
            }
        }
        if (i < 5) cout << endl; // Move to the next line after printing the 5th row
    }

    // If you'd like to print the entire matrix, you can uncomment the following code:
    /*
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    */

    return 0;
}

