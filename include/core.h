#pragma once
#include "global.h"
#include <cstdlib> // For getenv
#include <filesystem>
#include <string> // For std::string

class fileOperations {
public:
  std::string getfile_ext(const std::filesystem::path &filename);
  std::filesystem::path createFolder(const std::string &DEST_PATH,
                                     const std::filesystem::path &folder);
  void defaultMoveBehaviour(const std::string &SOURCE);
  void moveFile_inDir(const std::string &SOURCE, const std::string &DEST_PATH,
                      const key_value &key_umap);
  void organise_folder(const configV &configV_umap);
};
