#include <iostream>
#include <fstream>
#include <vector>
#include <zstd.h>

#define CHUNK_SIZE 16384

void hello();
void compress_file(const std::string &input_path, const std::string &output_path);
