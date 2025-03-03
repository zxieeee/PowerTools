#ifdef _WIN32
#include "../include/dirMonitor.h"
#include <errhandlingapi.h>
#include <memory>
#include <synchapi.h>
#include <windows.h>

void DirMonitor::startMonitoring(const std::vector<std::string> &SOURCEs) {
  int i = 0;
  std::vector<HANDLE> changes;
  for (const auto &SOURCE : SOURCEs) {
    LPCSTR path = SOURCE.c_str();
    change =
        FindFirstChangeNotification(path, FALSE, FILE_NOTIFY_CHANGE_LAST_WRITE);
    changes.push_back(change);
    if (changes = INVALID_HANDLE_VALUE) {
      std::cerr << "Failed to monitor directory : " << GetLastError() << "\n";
    }
  }

  DWORD dwWaitStatus;

  while (true) {
    dwWaitStatus =
        WaitForMultipleObjects(changes.size(), changes, FALSE, INFINITE);
    if (dwWaitStatus = > 0) {
      if (FindNextChangeNotification(changes[dwWaitStatus])) {
        organiseFolder(CONFIG);
      } else
    }
  }

  for (const auto &SOURCE : SOURCEs) {
    FindCloseChangeNotification(changes[i]);
  }
}

static std::unique_ptr<DirMonitor> DirMonitor::create() {
  return std::make_unique<DirMonitor>();
}
#endif
