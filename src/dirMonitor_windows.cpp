#include "../include/dirMonitor.h"
#include <windows.h>

void DirMonitor::startMonitoring(const std::string &SOURCE) {
  LPCSTR path = SOURCE;
  HANDLE changes;
  DWORD dwWaitStatus;
  changes =
      FindFirstChangeNotification(path, FALSE, FILE_NOTIFY_CHANGE_LAST_WRITE);
  while (true) {
    dwWaitStatus = WaitForSingleObject(changes, INFINITE);
    if (dwWaitStatus == WAIT_OBJECT_0) {
      if (FindNextChangeNotification(changes)) {
        organiseFolder(CONFIG);
      }
    }
  }
}
