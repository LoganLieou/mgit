#include <zstd.h>
#include <iostream>
#include <vector>
#include <fstream>

int main() {
    const std::string input = "Hello Zstandard!";
    std::vector<char> compressed(ZSTD_compressBound(input.size()));

    size_t compressed_size = ZSTD_compress(
        compressed.data(), compressed.size(),
        input.data(), input.size(), 3
    );

    if (ZSTD_isError(compressed_size)) {
        std::cerr << "Compression failed: " << ZSTD_getErrorName(compressed_size) << "\n";
        return 1;
    }

    std::cout << "Compressed " << input.size() << " bytes into " << compressed_size << " bytes.\n";
    return 0;
}

