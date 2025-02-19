#include "../include/global.h"
#include <iostream>
#include <windows.h>

int main() {
  LPCSTR path = SOURCE;
  HANDLE changes;
  DWORD dwWaitStatus;
  BOOL do_something;
  changes =
      FindFirstChangeNotification(path, FALSE, FILE_NOTIFY_CHANGE_FILE_NAME);
  while (true) {
    dwWaitStatus = WaitForSingleObject(changes, INFINITE);
    if (dwWaitStatus == WAIT_OBJECT_0) {
      do_something = FindNextChangeNotification(changes);
      std::cout << do_something << std::endl;
      if (do_something) {
        std::cout << "did something" << std::endl;
      }
    }
  }
}
