#include "utils.h"

namespace utils {

int randomInt(int min, int max) {
  return rand() % (max - min) + min;
}

std::string randomString(int len) {
  std::string str = "";
  for (int i = 0; i < len; i++)
    str += (char)(rand() % 26 + 97);
  return str;
}

} // namespace utils
