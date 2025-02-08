#include "../include/config.h"
#include "../include/global.h"
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
configV ConfigParser::parseConfigFile(const std::string &filename) {
  configV configV_umap;
  std::string line;
  std::string section, key, value;
  std::vector<std::string> FILE_EXT;
  std::string ext, key_t, ext_t;
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
      key_t = trim(key);

      FILE_EXT.clear();
      while (std::getline(ss, ext, ',')) {
        ext_t = trim(ext);
        FILE_EXT.push_back(ext_t);
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
      std::cout << key.first << " = ";

      for (const auto &i : key.second) {
        std::cout << i << " ";
      }

      std::cout << "\n";
    }
    std::cout << "\n";
  }
}

// body pf function to genrate a config

void ConfigParser::generateConfigFile(const std::string &filename) {
  std::ofstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error creating the file: " << filename << std::endl;
    return;
  }

  // for settings
  std::string timeDelay;
  std::cout << "Enter time delay (e.g., 10s): ";
  std::getline(std::cin, timeDelay);

  file << "# settings\n";
  file << "[settings]\n";
  file << "time_delay=" << timeDelay << "\n\n";

  // for source directories
  int sourceDirCount = 0;
  while (true) {
    std::string sourceDir;
    std::cout << "Enter source directory path (or type 'exit' to finish): ";
    std::getline(std::cin, sourceDir);

    if (sourceDir == "exit") {
      break;
    }

    sourceDirCount++;
    file << "# source directory " << sourceDirCount << "\n";
    file << "[source_directory_" << sourceDirCount << "]\n";
    file << "source_directory=" << sourceDir << "\n";

    // Prompt for file extensions for each category
    std::vector<std::string> categories = {"images", "documents", "videos",
                                           "music", "others"};
    for (const auto &category : categories) {
      std::string extensions;
      std::cout << "Enter " << category
                << " extensions (comma-separated, e.g., .png,.jpg): ";
      std::getline(std::cin, extensions);

      if (!extensions.empty()) {
        file << category << "=" << extensions << "\n";
      }
    }

    file << "\n";
  }

  std::cout << "Config file generated: " << filename << std::endl;
}
