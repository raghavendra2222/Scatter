#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int matrixSize = 128;
const int numIndices = 1000; // Change the number of indices here
const int dataSize = 1000;   // Change the data size here

void parsec_roi_begin() 
{

}

void parsec_roi_end() 
{

}


void gather(const int matrix[matrixSize][matrixSize], const int indices[numIndices], int gatheredData[dataSize]) {
    for (int i = 0; i < numIndices; ++i) {
        int row = indices[i] % matrixSize;
        int col = indices[i] / matrixSize;
        if (row < matrixSize && col < matrixSize) {
            gatheredData[i] = matrix[row][col];
        }
    }
}

int main() {
    int matrix[matrixSize][matrixSize];
    int indices[numIndices];
    int gatheredData[dataSize];

    // Initialize random seed based on current time
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    // Initialize matrix with random data (for demonstration purposes)
    for (int row = 0; row < matrixSize; ++row) {
        for (int col = 0; col < matrixSize; ++col) {
            matrix[row][col] = std::rand();
        }
    }

    // Initialize indices randomly
    for (int i = 0; i < numIndices; ++i) {
        indices[i] = std::rand() % (matrixSize * matrixSize);
    }

    // Perform the Gather operation
    parsec_roi_begin();
    gather(matrix, indices, gatheredData);
    parsec_roi_end();

    // Display the gathered data (for demonstration purposes)
    std::cout << "Gathered Data:" << std::endl;
    for (int i = 0; i < numIndices; ++i) {
        std::cout << gatheredData[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
