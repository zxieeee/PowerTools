#include "../include/dirMonitor.h"
#include <iostream>

int main() {
  DirMonitor dirmonitor;
  std::vector<std::string> SOURCEs;
  if (std::filesystem::exists(CONFIG)) {
    SOURCEs = dirmonitor.organiseFolder(CONFIG);
  } else {
    std::exit(64);
  }

  dirmonitor.startMonitoring(SOURCEs);

  return 0;
}
