#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include "../include/dirMonitor.h"
#include <windows.h>
#include <errhandlingapi.h>
#include <iostream>
#include <memory>
#include <synchapi.h>

void DirMonitor::startMonitoring(const std::vector<std::string> &SOURCEs) {
  std::vector<std::string> SOURCEsd;
  int i = 0;
  std::vector<HANDLE> changes;
  HANDLE change;
  LPCSTR path;
  for (const auto &SOURCE : SOURCEs) {
    path= SOURCE.c_str();
    change =
        FindFirstChangeNotification(path, FALSE, FILE_NOTIFY_CHANGE_LAST_WRITE);

    if (change == INVALID_HANDLE_VALUE) {
      std::cerr << "Failed to monitor directory : " << GetLastError() << "\n";
    } else {
      changes.push_back(change);
    }
  }

  DWORD dwWaitStatus;
  while (true) {
    dwWaitStatus =
        WaitForMultipleObjects(changes.size(), changes.data(), FALSE, INFINITE);
    if (dwWaitStatus >= 0) {
      if (FindNextChangeNotification(changes[dwWaitStatus - WAIT_OBJECT_0])) {
        Sleep(8000);
       organiseFolder(CONFIG);
      }
    }
  }

  for (const auto &SOURCE : SOURCEs) {
    FindCloseChangeNotification(changes[i]);
    i++;
  }
}

// static std::unique_ptr<DirMonitor> DirMonitor::create() {
//   return std::make_unique<DirMonitor>();
// }
#endif
