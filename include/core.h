#pragma once
#include "global.h"
#include <cstdlib> // For getenv
#include <filesystem>
#include <string> // For std::string

// function to see changes in file dir
#ifdef _WIN32
bool isdirectorychanged(const std::string &path,
                        std::filesystem::file_time_type &lastWriteTime);
const std::string SOURCE =
    std::string(std::getenv("USERPROFILE")) + "\\Desktop\\test";
#elif defined(__linux__)
bool isdirectorychanged(const std::string &path,
                        std::filesystem::file_time_type &lastWriteTime);
const std::string SOURCE =
    std::string(std::getenv("HOME")) + "/Downloads/jpg_folder";
#else
#error Unsupported Operating System
#endif

class fileOperations {
public:
  int SUCCESS;
  std::string getfile_ext(const std::filesystem::path &filename);
  int attemptToMove(const std::filesystem::path &file_path,
                    const std::filesystem::path &dest_path);
  std::filesystem::path createFolder(const std::string &DEST_PATH,
                                     const std::filesystem::path &folder);
  // path getPathfromConfig(const configV &configV_umap);
  void defaultMoveBehaviour(const std::string &SOURCE);
  void moveFileinDir(const std::string &SOURCE, const std::string &DEST_PATH,
                     const key_value &key_umap);
  void organiseFolder(const configV &configV_umap);
};
