#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int matrixSize = 128;
const int kernelSize = 3;
void parsec_roi_begin() 
{

}

void parsec_roi_end() 
{

}

void convolution(const int inputMatrix[matrixSize][matrixSize], int outputMatrix[matrixSize][matrixSize], const int kernel[kernelSize][kernelSize]) {
    for (int i = 1; i < matrixSize - 1; ++i) {
        for (int j = 1; j < matrixSize - 1; ++j) {
            int sum = 0;
            for (int k = -1; k <= 1; ++k) {
                for (int l = -1; l <= 1; ++l) {
                    sum += inputMatrix[i + k][j + l] * kernel[k + 1][l + 1];
                }
            }
            outputMatrix[i][j] = sum;
        }
    }
}

int main() {
    int inputMatrix[matrixSize][matrixSize];
    int outputMatrix[matrixSize][matrixSize];
    int kernel[kernelSize][kernelSize] = {{-1, -1, -1}, {-1, 8, -1}, {-1, -1, -1}};

    // Initialize inputMatrix with random data (for demonstration purposes)
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            inputMatrix[i][j] = std::rand();
        }
    }

    // Perform the Convolution operation
    convolution(inputMatrix, outputMatrix, kernel);

    // Display the resulting outputMatrix (for demonstration purposes)
    std::cout << "Resulting Output Matrix:" << std::endl;
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            std::cout << outputMatrix[i][j] << " ";
        }
        parsec_roi_begin();
        std::cout << std::endl;
        parsec_roi_end();
    }

    return 0;
}
