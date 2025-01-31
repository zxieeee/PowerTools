#include "../include/config.h"
#include "../include/core.h"
#include <iostream>

// global variables
int main() {
  ConfigParser config;
  fileOperations operate;
  const std::string filename =
      "/home/himanshu/code/gtk_multimedia_organiser/include/config.conf";

  const configV configV_umap = config.parseConfigFile(filename);

  std::vector<std::string> vec =
      configV_umap.at("source_directory_1").at("source_path");

  std::cout << vec.size() << "\n";
}

// std::vector<std::string> vec =
//     configV_umap.at("source_directory_1").at("source_path");

// std::cout << vec.size() << "\n";

// config.printConfig(configV_umap);
// operate.organise_folder(configV_umap);
