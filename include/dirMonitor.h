#pragma once
#include "../include/core.h"
#include "../include/global.h"
#include "core.h"
#include <string_view>

class DirMonitor : public fileOperations {
public:
  virtual void startMonitoring(const std::string &SOURCE) = 0;
  virtual ~DirMonitor() {}
};

// Factory function to create an instance (defined per OS)
// DirMonitor *createDirMonitor();
