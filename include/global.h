#pragma once
#include <filesystem>
#include <string>
#include <unordered_map>
#include <vector>

using key_value = std::unordered_map<std::string, std::vector<std::string>>;
using configV = std::unordered_map<std::string, key_value>;

// TODO: get a function to fill out SOURCE AND DEST_PATH
struct path {
  std::string SOURCE;
  std::string DEST_PATH;
};

#ifdef _WIN32
bool isdirectorychanged(const std::string &path,
                        std::filesystem::file_time_type &lastWriteTime);
const std::string config_path =
    std::string(std::getenv("USERPROFILE")) + "\\Desktop\\test";
#elif defined(__linux__)
bool isdirectorychanged(const std::string &path,
                        std::filesystem::file_time_type &lastWriteTime);
const std::string config_path =
    std::string(std::getenv("HOME")) + ".config/Powertools/config.conf";
#else
#error Unsupported Operating System
#endif
