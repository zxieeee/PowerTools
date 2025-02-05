#include "../include/core.h"
#include <filesystem>
#include <iostream>

// people who are using gcc built versions older tan 8.1.0 will have to use the
// following code replace the #include <filesystem> with the following code
// #include <experimental/filesystem>  and replace std::filesystem with
// std::experimental::filesystem or update your gcc version

std::string getfile_ext(const std::filesystem::path &filename) {
  std::string ext = filename.extension().string();
  if (!ext.empty() && ext.front() == '.') {
    return ext.substr(1);
  } else
    return ""; // TODO: Returning emtpy string is fine. We can use <optional>
               // which can allow us to return a nullptr but may be something
               // that is not needed
}
// function to detected the change in dir is made or not 
bool isdirectorychanged(const std::string &path , std::filesystem::file_time_type &lastWriteTime )
{
  std::filesystem::file_time_type newWriteTime = std::filesystem::last_write_time(path);
  if(newWriteTime != lastWriteTime)
  {
    lastWriteTime = newWriteTime;
    return true;
  }
  return false;
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
