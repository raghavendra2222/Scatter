#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int matrixSize = 128; // Change matrix size here
const int numIndices = 1000;
const int dataSize = 1000;

void parsec_roi_begin() 
{

}

void parsec_roi_end() 
{

}

void scatter(int matrix[matrixSize][matrixSize], int indices[numIndices], int data[dataSize]) {
    for (int i = 0; i < numIndices; ++i) {
        int row = indices[i] % matrixSize;
        int col = indices[i] / matrixSize;
        if (row < matrixSize && col < matrixSize) {
            matrix[row][col] = data[i];
        }
    }
}

int main() {
    int matrix[matrixSize][matrixSize] = {0};
    int indices[numIndices];
    int data[dataSize];

    // Initialize indices and data randomly (for demonstration purposes)
    std::srand(static_cast<unsigned int>(std::time(0))); // Use time(0) instead of nullptr
    for (int i = 0; i < numIndices; ++i) {
        indices[i] = std::rand() % (matrixSize * matrixSize);
        data[i] = std::rand();
    }

    // Perform the Scatter operation
    scatter(matrix, indices, data);

    // Display the resulting matrix (for demonstration purposes)
    std::cout << "Resulting Matrix:" << std::endl;
    for (int row = 0; row < matrixSize; ++row) {
        for (int col = 0; col < matrixSize; ++col) {
            std::cout << matrix[row][col] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
