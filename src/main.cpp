#include "../include/core.h"
#include "../include/dirMonitor.h"

int main() {
  DirMonitor dirmonitor;
  std::vector<std::string> SOURCEs;
  if (std::filesystem::exists(CONFIG)) {
    SOURCEs = dirmonitor.organiseFolder(CONFIG);
  } else {
    std::exit(64);
  }

  dirmonitor.startMonitor

      return 0;
}
