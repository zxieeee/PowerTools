#pragma once
#include <string>
#include <unordered_map>

class ConfigParser {
public:
  void parseConfigFile(const std::string &filename);
  // std::string get(const std::string &key,
  //                 const std::string &default_value = "") const;
  void printConfig();
  void generateConfigFileInteractively(const std::string &filename); // for the
                                                                      // user to
                                                                      // generate
                                                                      // the
                                                                      // config
                                                                      // file
  std::unordered_map<std::string, std::unordered_map<std::string, std::string>>
      config;
};
