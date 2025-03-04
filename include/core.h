#pragma once
#include "config.h"
#include "global.h"
#include <cstdlib> // For getenv
#include <filesystem>

// function to see changes in file dir
class fileOperations : public ConfigParser {
public:
  int SUCCESS;
  std::string getfile_ext(const std::filesystem::path &filename);
  int attemptToMove(const std::filesystem::path &file_path,
                    const std::filesystem::path &dest_path);
  std::filesystem::path createFolder(const std::string &DEST_PATH,
                                     const std::filesystem::path &folder);
  // TODO:(zxieee) path getPathfromConfig(const configV &configV_umap);
  void defaultMoveBehaviour(const std::string &SOURCE,
                            const std::string &DEST_PATH);
  void moveFileinDir(const std::string &SOURCE, const std::string &DEST_PATH,
                     const key_value &key_umap);
  std::vector<std::string> organiseFolder(const std::string &CONFIG);
};
