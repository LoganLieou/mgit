#include "utils.h"

// TEST function to see if bazel is working correctly
void hello() {
	std::cout << "hello" << std::endl;
}

// utilize zstd to compress a file
void compress_file(const std::string& input_path, const std::string& output_path) {
    std::ifstream fin(input_path, std::ios::binary);
    if (!fin) {
        throw std::runtime_error("Failed to open input file: " + input_path);
    }

    std::ofstream fout(output_path, std::ios::binary);
    if (!fout) {
        throw std::runtime_error("Failed to open output file: " + output_path);
    }

    std::vector<char> in_buf(CHUNK_SIZE);
    size_t max_compressed_size = ZSTD_compressBound(CHUNK_SIZE);
    std::vector<char> out_buf(max_compressed_size);

    while (fin) {
        fin.read(in_buf.data(), CHUNK_SIZE);
        std::streamsize read_bytes = fin.gcount();
        if (read_bytes <= 0) break;

        size_t compressed_size = ZSTD_compress(
            out_buf.data(),
            out_buf.size(),
            in_buf.data(),
            static_cast<size_t>(read_bytes),
            3  // compression level
        );

        if (ZSTD_isError(compressed_size)) {
            throw std::runtime_error("Compression error: " + std::string(ZSTD_getErrorName(compressed_size)));
        }

        fout.write(out_buf.data(), compressed_size);
    }
}
