#include "../include/config.h"
#include "../include/core.h"
#include <chrono>
#include <filesystem>
#include <iostream>
#include <thread>

// global variables
int main() {
  configV config;
  key_value keyvalue;
  std::filesystem::path SOURCE, DEST_PATH;
  ConfigParser configParser;
  fileOperations fileoperation;
  config = configParser.parseConfigFile("../include/config.conf");
  // configParser.generateConfigFile("include/config.txt");

  fileoperation.organiseFolder(config);
  // Initialize last write time
  // auto lastWriteTime = std::filesystem::last_write_time(sourcePath);

  // Monitor the directory for changes
  // while (true) {
  //   if (isdirectorychanged(sourceDir, lastWriteTime)) {
  //     std::cout << "Change detected in directory: " << sourceDir <<
  //     std::endl; fileoperation.moveFileinDir(
  //         SOURCE, DEST_PATH, keyvalue); // Re-run the file organization logic
  //   }
  //
  //   std::this_thread::sleep_for(std::chrono::seconds(5));
  // }

  return 0;
}
