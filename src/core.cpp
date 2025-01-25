#include "../include/core.h"
#include "../include/config.h"
#include <filesystem>
#include <iostream>
#include <sstream>                
#include <unordered_map>
#include <fstream>
#include <algorithm>



//people who are using gcc built versions older tan 8.1.0 will have to use the following code
//replace the #include <filesystem> with the following code #include <experimental/filesystem>  and replace std::filesystem with std::experimental::filesystem
//or update your gcc version

std::string getfile_ext(const std::filesystem::path &filename) {
  std::string ext = filename.extension().string();
  if (!ext.empty() && ext.front() == '.') {
    return ext.substr(1);
  } else
    return ""; // TODO: check if returning an empty string is a good idea
}

void movefile_indir(const std::string &SOURCE) {

  // NOTE: Get files from the specified dir this can be consolidated into a
  // function but then we have to read it aswell there wasnt muchto gain so i
  // kept it in the same function
  for (const auto &file : std::filesystem::directory_iterator(SOURCE)) {
    std::filesystem::path SourceDir(SOURCE);
    if (std::filesystem::is_regular_file(file.status())) {
      std::string ext = getfile_ext(file);
      std::filesystem::path file_path(file);
      std::filesystem::path folder(ext + "_folder");

      if (!std::filesystem::exists(SourceDir / folder)) {
        std::filesystem::create_directory(SourceDir / folder);
      }

      std::filesystem::path dest_path =
          SourceDir / folder / file_path.filename();

      if (std::filesystem::exists(file)) {
        try {
          std::filesystem::rename(file_path, dest_path);

          std::cout << "Moved: " << file_path.string() << " -> "
                    << dest_path.string() << std::endl;
        } catch (const std::exception &e) {
          std::cerr << "Error moving file: " << file_path << " - " << e.what()
                    << std::endl;
        }
      } else {
        std::cerr << "File not found: " << file_path.string() << std::endl;
      }
    }
  }
}

// Implementation of ConfigParser methods
ConfigParser::ConfigParser(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening the file: " << filename;
        return;
    }

    std::string line;
    while (std::getline(file, line)) 
    {
        if (line.empty() || line[0] == '#') 
        {
            continue;
        }

        std::string key, value;
        std::istringstream iss(line);
        std::getline(iss, key, '=');
        std::getline(iss, value);

        key.erase(key.begin(), std::find_if(key.begin(), key.end(), [](int ch) {
            return !std::isspace(ch);
        }));

        value.erase(value.begin(), std::find_if(value.begin(), value.end(), [](int ch) {
            return !std::isspace(ch);
        }));

        config[key] = value;
    }
}

void ConfigParser::printConfig() const {
    for (const auto &kv : config) {
        std::cout << kv.first << " = " << kv.second << std::endl;
    }
}

// std::string ConfigParser::get(const std::string& key, const std::string& default_value) const {
//     auto it = config.find(key);
//     return it != config.end() ? it->second : default_value;

