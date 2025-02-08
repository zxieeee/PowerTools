#pragma once
#include "global.h"
#include <string>

// Class Implementation
class ConfigParser {
public:
  configV parseConfigFile(const std::string &filename);
  void printConfig(configV configV_umap);
  void generateConfigFile(const std::string &filename);
  std::string trim(std::string str);
};
