#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Constants for matrix and data sizes
const int MatrixSize = 128;
const int NumIndices = 128;
const int DataSize = 128;

// Function to perform Scatter operation
void ScatterData(int matrix[MatrixSize][MatrixSize], const int indices[NumIndices], const int data[DataSize]) {
    for (int i = 0; i < NumIndices; ++i) {
        // Calculate row and column for the current index
        int index = indices[i];
        int row = index % MatrixSize;
        int col = index / MatrixSize;

        // Check if the calculated row and column are within matrix bounds
        if (row < MatrixSize && col < MatrixSize) {
            // Scatter the data at the current index into the matrix
            matrix[row][col] = data[i];
        }
    }
}

int main() {
    // Initialize a 128x128 matrix, index array, and data array
    int matrix[MatrixSize][MatrixSize] = {0};
    int indices[NumIndices];
    int data[DataSize];

    // Initialize random seed based on current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Populate the index array and data array with random values
    for (int i = 0; i < NumIndices; ++i) {
        indices[i] = std::rand() % (MatrixSize * MatrixSize);
        data[i] = std::rand();
    }

    // Perform the Scatter operation
    ScatterData(matrix, indices, data);

    // Display the resulting matrix (for demonstration purposes)
    std::cout << "Resulting Matrix:" << std::endl;
    for (int row = 0; row < MatrixSize; ++row) {
        for (int col = 0; col < MatrixSize; ++col) {
            std::cout << matrix[row][col] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}