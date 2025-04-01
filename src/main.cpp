#include "../include/dirMonitor.h"
#include <thread>

int main() {
  HINSTANCE hInstance = GetModuleHandle(NULL);
  DirMonitor dirmonitor;
  std::vector<std::string> SOURCEs;
  if (std::filesystem::exists(CONFIG)) {
    SOURCEs = dirmonitor.organiseFolder(CONFIG);
  } else {
    std::exit(64);
  }
  std::thread monitoringThread(&DirMonitor::startMonitoring, &dirmonitor,
                               SOURCEs);
  SysTrayApp app(hInstance);
  monitoringThread.join();

  return app.Run();
}
