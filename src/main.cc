#include <iostream>
#include <fstream>
#include <vector>
#include "utils.h"

int main() {
    std::string inputFile = "test.txt";
    std::string outputFile = "test.zst";

    if (compressFile(inputFile, outputFile)) {
        std::cout << "Compression successful." << std::endl;
    } else {
        std::cerr << "Compression failed." << std::endl;
    }

    return 0;
}

