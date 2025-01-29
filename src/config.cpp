#include "../include/config.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>

// NOTE: I was unsure whether to have thisfunction called in constructor because
// it will iterate in directory many times so it would be problematic to keep it
// in constructor
//
void ConfigParser::parseConfigFile(const std::string &filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error opening the file: " << filename;
  }

  std::string line;
  std::string section, key, value;
  while (std::getline(file, line)) {
    if (line.empty() || line[0] == '#') {
      continue;
    }

    // NOTE: adding support for reading sections such as [Source_dir1]
    if (line[0] == '[' && line.back() == ']') {
      section = line.substr(1, line.length() - 2);
      config[section] = {};
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

      config[section][key] = value;
    }
    // std::cout << key << " = " << value << std::endl;
  }
}

void ConfigParser::printConfig() {
  // Print parsed config
  for (const auto &section : config) {
    std::cout << "[" << section.first << "]\n";
    for (const auto &pair : section.second) {
      std::cout << pair.first << " = " << pair.second << "\n";
    }
    std::cout << "\n";
  }
}

// std::string ConfigParser::get(const std::string& key, const std::string&
// default_value) const {
//     auto it = config.find(key);
//     return it != config.end() ? it->second : default_value;
