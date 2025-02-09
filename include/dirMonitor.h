#pragma once
#include "../include/global.h"

class DirMonitor {
public:
  virtual void startMonitoring(const std::string &folderPath) = 0;
  virtual ~DirMonitor() {}
};

// Factory function to create an instance (defined per OS)
FileMonitor *createFileMonitor();
