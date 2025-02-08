#pragma once
#include <string>
#include <unordered_map>
#include <vector>

using key_value = std::unordered_map<std::string, std::vector<std::string>>;
using configV = std::unordered_map<std::string, key_value>;

struct path {
  std::string SOURCE;
  std::string DEST_PATH;
};
