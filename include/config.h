#ifndef CORE_H
#define CORE_H

#include <string>
#include <unordered_map>

class ConfigParser 
{
public:
    ConfigParser(const std::string& filename);
    // std::string get(const std::string& key, const std::string& default_value = "") const;
    void printConfig() const;

private:
    std::unordered_map<std::string, std::string> config;
};



#endif 
