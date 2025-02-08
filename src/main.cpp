#include "../include/config.h"
#include "../include/core.h"
#include <chrono>
#include <filesystem>
#include <iostream>
#include <thread>

int main() {
  ConfigParser configParser;
  fileOperations fileoperation;
  configParser.parseConfigFile("include/config.txt");
  configParser.generateConfigFile("include/config.txt");

  std::string sourceDir = SOURCE; // Use the SOURCE directory from core.h
  std::filesystem::path sourcePath =
      sourceDir; // Convert to std::filesystem::path

  // Initialize last write time
  auto lastWriteTime = std::filesystem::last_write_time(sourcePath);

  // Monitor the directory for changes
  while (true) {
    if (isdirectorychanged(sourceDir, lastWriteTime)) {
      std::cout << "Change detected in directory: " << sourceDir << std::endl;
      fileoperation.moveFileinDir(
          sourceDir); // Re-run the file organization logic
    }

    // Sleep for a while before checking again (e.g., every 5 seconds)
    std::this_thread::sleep_for(std::chrono::seconds(5));
  }

  return 0;
}
