#include <cstdlib> // For getenv
#include <string>  // For std::string
#include <chrono>  // For std::chrono
#include <filesystem> 
// people who are using gcc built versions older tan 8.1.0 will have to use the
// following code replace the #include <filesystem> with the following code

// TODO: Hardcoding Downloads directory using platform-specific Env Variables

//function to see changes in file dir 
#ifdef _WIN32
bool isdirectorychanged(const std::string &path , std::filesystem::file_time_type &lastWriteTime);
const std::string SOURCE =
    std::string(std::getenv("USERPROFILE")) + "\\Desktop\\test";
#elif defined(__linux__)
bool isdirectorychanged(const std::string &path , std::filesystem::file_time_type &lastWriteTime);
const std::string SOURCE = std::string(std::getenv("HOME")) + "/Downloads";
#else
#error Unsupported Operating System
#endif

std::string getfile_ext(const std::string &filename);
// std::vector<std::string> getfiles_fromDir(const std::string &SOURCE);
void movefile_indir(const std::string &SOURCE);
