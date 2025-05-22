#include "utils.h"

void hello() {
	std::cout << "hello" << std::endl;
}

bool compressFile(const std::string& inputPath, const std::string& outputPath) {
    // Set compression level
    int compressionLevel = 21;

    // Open input file
    std::ifstream inputFile(inputPath, std::ios::binary);
    if (!inputFile) {
        std::cerr << "Failed to open input file: " << inputPath << std::endl;
        return false;
    }

    // Read input file into buffer
    std::vector<char> inputBuffer((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();

    // Allocate output buffer with size determined by ZSTD_compressBound
    size_t compressedBound = ZSTD_compressBound(inputBuffer.size());
    std::vector<char> compressedBuffer(compressedBound);

    // Compress the data
    size_t compressedSize = ZSTD_compress(compressedBuffer.data(), compressedBound, inputBuffer.data(), inputBuffer.size(), compressionLevel);
    if (ZSTD_isError(compressedSize)) {
        std::cerr << "Compression error: " << ZSTD_getErrorName(compressedSize) << std::endl;
        return false;
    }

    // Open output file
    std::ofstream outputFile(outputPath, std::ios::binary);
    if (!outputFile) {
        std::cerr << "Failed to open output file: " << outputPath << std::endl;
        return false;
    }

    // Write compressed data to output file
    outputFile.write(compressedBuffer.data(), compressedSize);
    outputFile.close();

    return true;
}

