#pragma once
#include <string>
#include <unordered_map>

class ConfigParser {
public:
  void parseConfigFile(const std::string &filename);
  // std::string get(const std::string &key,
  //                 const std::string &default_value = "") const;
  void printConfig();

  std::unordered_map<std::string, std::unordered_map<std::string, std::string>>
      config;
};
