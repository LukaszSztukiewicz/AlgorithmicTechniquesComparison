#include "csv.h"
CSV::CSV(std::string filename, bool isCreateNewFile) : filename(filename) {
  if (isCreateNewFile) {
    std::fstream file(filename, std::fstream::trunc | std::fstream::out);
    file.close();
  }
};

void CSV::clear() {
  std::fstream file(filename, std::fstream::trunc);
  file.close();
}

void CSV::writeLine(std::string line, std::string end, bool append) {
  std::fstream file;
  if (append)
    file.open(filename, std::ios::app);
  else
    file.open(filename, std::ios::out);
  file << line << end;
  file.close();
}

void CSV::writeVector(std::vector<std::string> v) {
  std::string line = "";
  for (auto s : v)
    line += s + delimiter;
  writeLine(line, "\n");
}

std::vector<std::string> CSV::readRow(int row) {
  std::fstream file;
  file.open(filename, std::fstream::in);
  std::vector<std::string> result;
  std::string line;
  for (int i = 0; i <= row; i++) {
    std::getline(file, line);
  }
  std::stringstream ss(line);
  std::string item;
  while (std::getline(ss, item, delimiter[0])) {
    result.push_back(item);
  }
  return result;
}
std::vector<std::string> CSV::readColumn(int column, bool skipHeader) {
  std::fstream file;
  file.open(filename, std::fstream::in);
  std::vector<std::string> result;
  std::string line;
  if (skipHeader) {
    std::getline(file, line);
  }
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string item;
    for (int i = 0; i <= column; i++) {
      std::getline(ss, item, delimiter[0]);
    }
    result.push_back(item);
  }
  return result;
}

std::vector<std::vector<std::string>> CSV::readAll(bool skipHeader) {
  std::fstream file;
  file.open(filename, std::fstream::in);
  std::vector<std::vector<std::string>> result;
  std::string line;
  if (skipHeader) {
    std::getline(file, line, '\n');
  }
  while (std::getline(file, line, '\n')) {
    std::stringstream ss(line);
    std::string item;
    std::vector<std::string> row;
    while (std::getline(ss, item, delimiter[0])) {
      row.push_back(item);
    }
    result.push_back(row);
  }
  file.close();
  return result;
}