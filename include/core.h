#pragma once
#include <cstdlib> // for getenv
#include <stdio.h>
#include <string>

// TODO: Hardcoding Downloads directory using platform specific Env Variables
// to be fixed in the future
#ifdef _WIN32
const std::string SOURCE =
    std::string(std::getenv(% USERPROFILE %)) + "/Downloads";
#elif defined(__linux__)
const std::string SOURCE = std::string(std::getenv("HOME")) + "/Downloads";
#else
std::cerr << "Unsupported Operating System" << std::endl;
#endif
std::string getfile_ext(const std::string &filename);
// std::vector<std::string> getfiles_fromDir(const std::string &SOURCE);
void movefile_indir(const std::string &SOURCE);
