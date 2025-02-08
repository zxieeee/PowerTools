#include "../include/config.h"
#include "../include/global.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Now our trim function remains the same
std::string ConfigParser::trim(std::string str) {
    // Remove leading spaces
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == std::string::npos) {
        return ""; // String contains only whitespace
    }
    
    // Remove trailing spaces
    size_t end = str.find_last_not_of(" \t\n\r");
    
    // Return the trimmed substring
    return str.substr(start, end - start + 1);
}

// NOTE: I was unsure whether to have thisfunction called in constructor because
// it will iterate in directory many times so it would be problematic to keep it
// in constructor
configV ConfigParser::parseConfigFile(const std::string &filename) {
  configV configV_umap;
  std::string line;
  std::string section, key, value;
  std::vector<std::string> FILE_EXT;
  std::string ext , key_t;
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
     
      std::stringstream ss(value);
      key_t=  trim(key);

      
      FILE_EXT.clear();
      while (std::getline(ss, ext, ',')) {
        FILE_EXT.push_back(trim(ext));
        i++;
      }
      configV_umap[section][key_t] = FILE_EXT;
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
      std::cout << key.first << "=";

      for (const auto &i : key.second) {
        std::cout << i << " ";
      }

      std::cout << "\n";
    }
    std::cout << "\n";
  }
}
