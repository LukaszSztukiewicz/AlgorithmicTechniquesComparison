#include "utils.h"
#include "gtest/gtest.h"

// test CSV class read and writeVector
TEST(CSV, write_readAll) {
  CSV csv("test/test_write_readAll.csv");
  std::vector<std::string> header = {"a", "b", "c"};
  std::vector<std::string> v      = {"1", "2", "3"};
  std::vector<std::string> v2     = {"4", "5", "6"};
  csv.clear();
  csv.writeVector(header);
  csv.writeVector(v);
  csv.writeVector(v2);
  std::vector<std::vector<std::string>> result = csv.readAll();
  EXPECT_EQ(result[0], header);
  EXPECT_EQ(result[1], v);
  EXPECT_EQ(result[2], v2);
  remove("test/test_write_readAll.csv");
}

// test CSV readColumn without skipping header
TEST(CSV, read_column) {
  CSV csv("test/test_read_column.csv");
  std::vector<std::string> header = {"a", "b", "c"};
  std::vector<std::string> v      = {"1", "2", "3"};
  std::vector<std::string> v2     = {"4", "5", "6"};
  csv.clear();
  csv.writeVector(header);
  csv.writeVector(v);
  csv.writeVector(v2);
  std::vector<std::string> result = csv.readColumn(0, false);
  EXPECT_EQ(result[0], "a");
  EXPECT_EQ(result[1], "1");
  EXPECT_EQ(result[2], "4");
  remove("test/test_read_column.csv");
}

// test CSV readRow
TEST(CSV, read_row) {
  CSV csv("test/test_read_row.csv");
  std::vector<std::string> header = {"a", "b", "c"};
  std::vector<std::string> v      = {"1", "2", "3"};
  std::vector<std::string> v2     = {"4", "5", "6"};
  csv.writeVector(header);
  csv.writeVector(v);
  csv.writeVector(v2);
  std::vector<std::string> result = csv.readRow(1);
  EXPECT_EQ(result[0], "1");
  EXPECT_EQ(result[1], "2");
  EXPECT_EQ(result[2], "3");
  remove("test/test_read_row.csv");
}

// test CSV writeLine
TEST(CSV, write_line) {
  CSV csv("test/test_write_line.csv");
  csv.clear();
  csv.writeLine("1");
  csv.writeLine("2");
  csv.writeLine("3");
  std::vector<std::vector<std::string>> result = csv.readAll();
  EXPECT_EQ(result[0][0], "1");
  EXPECT_EQ(result[1][0], "2");
  EXPECT_EQ(result[2][0], "3");
  remove("test/test_write_line.csv");
}