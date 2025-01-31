#include "../include/config.h"
#include "../include/global.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// NOTE: I was unsure whether to have thisfunction called in constructor because
// it will iterate in directory many times so it would be problematic to keep it
// in constructor
configV ConfigParser::parseConfigFile(const std::string &filename) {
  configV configV_umap;
  std::string line;
  std::string section, key, value;
  std::vector<std::string> FILE_EXT;
  std::string ext;
  int i = 0;

  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error opening the file: " << filename;
  }

  while (std::getline(file, line)) {
    if (line.empty() || line[0] == '#') {
      continue;
    }

    // NOTE: adding support for reading sections such as [Source_dir1]
    if (line[0] == '[' && line.back() == ']') {
      section = line.substr(1, line.length() - 2);
      configV_umap[section] = {};
      continue;
    }
    if (!section.empty()) {
      std::istringstream iss(line);
      std::getline(iss, key, '=');
      std::getline(iss, value);
      key.erase(key.begin(), std::find_if(key.begin(), key.end(), [](int ch) {
                  return !std::isspace(ch);
                }));

      value.erase(value.begin(),
                  std::find_if(value.begin(), value.end(),
                               [](int ch) { return !std::isspace(ch); }));
      std::stringstream ss(value);
      FILE_EXT.clear();
      while (std::getline(ss, ext, ',')) {
        FILE_EXT.push_back(ext);
        i++;
      }
      configV_umap[section][key] = FILE_EXT;
    }
    // std::cout << key << " = " << value << std::endl;
  }
  return configV_umap;
}

// print for debug
void ConfigParser::printConfig(configV configV_umap) {
  for (const auto &section : configV_umap) {
    std::cout << "[" << section.first << "]\n";

    for (const auto &key : section.second) {
      std::cout << key.first << " = ";

      for (const auto &i : key.second) {
        std::cout << i << " ";
      }

      std::cout << "\n";
    }
    std::cout << "\n";
  }
}
