#include <gtest/gtest.h>
#include <fstream>
#include <iostream>
#include <string> 
#include "../src/utils.h"

// for creating temp directories during the test
// #include <filesystem>

TEST(CompressionTest, Compress) {
	const std::string input_file = "test/data/test_file.txt";
	const std::string output_file = "test/data/test_file.txt.zst";

	ASSERT_TRUE(compressFile(input_file, output_file));

	// TODO delete the output file after the test is over
}
