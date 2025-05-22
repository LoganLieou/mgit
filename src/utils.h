#include <iostream>
#include <fstream>
#include <vector>
#include <zstd.h>

void hello();
bool compressFile(const std::string &input_path, const std::string &output_path);
