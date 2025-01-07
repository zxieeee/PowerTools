#pragma once
#include <cstdlib> // for getenv
#include <filesystem>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#ifdef _WIN32
const std::string SOURCE = "%USERPROFILE%/Downloads";
#elif defined(__linux__)
const std::string SOURCE = std::string(std::getenv("HOME")) + "/Downloads";
#else
std::cerr << "Unsupported Operating System" << std::endl;
#endif
std::string getfile_ext(const std::string &filename);
std::vector<std::string> getfiles_fromDir(const std::string &SOURCE);
void save(const std::string &SOURCE);
