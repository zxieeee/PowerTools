#include "../include/core.h"

int main() {
  fileOperations fileoperation;
  if (std::filesystem::exists(CONIG)) {
    fileoperation.organiseFolder(CONFIG);
  } else {
    std::exit(64);
  }
  return 0;
}
