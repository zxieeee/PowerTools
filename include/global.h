#pragma once
#include <filesystem>
#include <string>
#include <unordered_map>
#include <vector>

using key_value = std::unordered_map<std::string, std::vector<std::string>>;
using configV = std::unordered_map<std::string, key_value>;

// TODO: get a function to fill out SOURCE AND DEST_PATH
// struct path {
//   std::string SOURCE;
//   std::string DEST_PATH;
// };

#ifdef _WIN32
const std::string CONFIG = std::string(std::getenv("APPDATA")) +
                           "\\gtk_multimedia_organiser\\config.conf";
#elif defined(__linux__)
const std::string CONFIG = std::string(std::getenv("HOME")) +
                           ".config/gtk_multimedia_organiser/config.conf";
#else
#error Unsupported Operating System
#endif
