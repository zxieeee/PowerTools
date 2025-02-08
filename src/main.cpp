#include "../include/config.h"
#include "../include/core.h"
#include <iostream>

// global variables
int main() {
  ConfigParser config;
  fileOperations operate;
  const std::string filename =
      "../include/config.conf";

  const configV configV_umap = config.parseConfigFile(filename);

  config.printConfig(configV_umap);
  operate.organise_folder(configV_umap);

}



