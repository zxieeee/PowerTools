#include <cstdlib> // For getenv
#include <string>  // For std::string

// people who are using gcc built versions older tan 8.1.0 will have to use the
// following code replace the #include <filesystem> with the following code

// TODO: Hardcoding Downloads directory using platform-specific Env Variables

#ifdef _WIN32
const std::string SOURCE =
    std::string(std::getenv("USERPROFILE")) + "\\Desktop\\test";
#elif defined(__linux__)
const std::string SOURCE = std::string(std::getenv("HOME")) + "/Downloads";
#else
#error Unsupported Operating System
#endif

std::string getfile_ext(const std::string &filename);
// std::vector<std::string> getfiles_fromDir(const std::string &SOURCE);
void movefile_indir(const std::string &SOURCE);
